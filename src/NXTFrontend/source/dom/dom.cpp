#include <iostream>

#include "dom/dom.h"
#include "html/parser.h"

namespace browser {
    bool DOM::doTick(browser::STACK *STACK, browser::GUI *GUI) {
        try {
            if(!this->SHOULD_UPDATE) //TODO
                return false;
            
            printf("DOM->Started drawing the DOM...\n");

            int position = 0; // TODO: good scroll
            auto doc = STACK->getCurrentPage().xmlParser;
            
            printf("DOM->Draw->Parsing Document...\n");
            auto element = doc->FirstChildElement("html")->FirstChildElement("body");
            for(const tinyxml2::XMLElement* child = element->FirstChildElement(); child != NULL; child=child->NextSiblingElement()) {
                // TODO: Do this properly
                std::string type = child->Value();
                position = browser::parser::html_parser(child, type, position);
            }
            printf("DOM->Draw->Done Parsing Document\n");


            printf("DOM->Successfully drew the DOM\n");
        } catch(...) {
            printf("DOM->Failed to draw DOM\n");
        }

        this->SHOULD_UPDATE = false;
        return true;
    }
}