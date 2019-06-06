#include <iostream>

#include "stack/stack.h"

namespace browser {
    STACK::STACK() {
        this->Stack.source = "";
        this->Stack.path = "http://lite.cnn.io/en";
        this->Stack.loaded = 0;
        this->Stack.go = true;

        #ifdef __SWITCH__
            romfsInit();
        #endif

        this->Stack.xmlParser = new tinyxml2::XMLDocument();
    }
    STACK::~STACK() {
        #ifdef __SWITCH__
            romfsExit();
        #endif
    }

    stack STACK::getCurrentPage() {
        return this->Stack;
    }

    void STACK::setPath (std::string path, bool go) {
        this->Stack.path = path;

        if (go) {
            this->Stack.go = true;
            this->Stack.loaded = 0;
        }
    }
    void STACK::setSource (std::string page, bool file) {
        this->Stack.go = false;
        
        if (file) {
            printf("%s", (const char*)std::string("STACK->Loading file: " + page).c_str());
            //std::ifstream ifs = std::ifstream(page);
            //this->Stack.source = browser::validator::validate_and_fix(std::string(std::istreambuf_iterator<char>{ifs}, {}));
            this->Stack.path = "file://" + page;
        } else {
            this->Stack.source = browser::validator::validate_and_fix(std::string(page, {}));
            
        }

    }

    void STACK::prepareTick() {
        if(this->Stack.source.empty())
            this->Stack.source = "<html><head>404</head><body><h1>Error</h1><p>We couldn't find the requested file :(</p></body></html>"; // TODO: Embedd error page
    }
    bool STACK::doTick() {
        this->Stack.xmlParser->Parse((const char*)this->Stack.source.c_str(), this->Stack.source.size());
        return true;
    }
}