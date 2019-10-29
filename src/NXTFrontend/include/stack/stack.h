#pragma once
#include <iostream>

#include "../main.h"
#include "../html/validator.h"

extern device_aspect DEVICE;

struct stack {
    tinyxml2::XMLDocument *xmlParser;
    std::string source;
    std::string path;

    double loaded = 75;
    bool go = false;
};

namespace browser {
    class STACK {
        private:
            stack Stack;

        public:
            STACK();
            ~STACK();

            stack getCurrentPage();

            void setPath (std::string path, bool go);
            void setSource (std::string page, bool file = false);

            void prepareTick();
            bool doTick();
    };
}