#include "net/net.h"

std::string data;
size_t write_data(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);

    data = ((std::string*)userp)->c_str();
    return size * nmemb;
}

namespace browser {
    bool NET::doTick(browser::STACK *STACK, browser::DOM *DOM) {
        auto curl = curl_easy_init();
        stack Stack = STACK->getCurrentPage();
        std::string source;

        if (!Stack.go)
            return false;

        printf("NET->Downloading: %s\n", Stack.path.c_str());

        curl_easy_setopt(curl, CURLOPT_URL, Stack.path.c_str());
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &source);
        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res == 23 || !data.empty()) {
            STACK->setSource(data, false);
            DOM->SHOULD_UPDATE = true;

            printf("NET->Download Completed: %s\n", Stack.path.c_str());
        } else {
            printf("NET->Failed To Download: %s\n", Stack.path.c_str());
        }
        return DOM->SHOULD_UPDATE;
    };
}