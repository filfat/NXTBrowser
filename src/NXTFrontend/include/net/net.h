#pragma once
#include <iostream>
#include <curl/curl.h>
#include <curl/easy.h>

#include "main.h"

#include "../stack/stack.h"
#include "../dom/dom.h"

namespace browser {
    class NET {
        public:
            NET() {};
            ~NET() {};

            void prepareTick() {}

            bool doTick(browser::STACK *STACK, browser::DOM *DOM);
    };
}