#pragma once

#include <iostream>

#include "../properties.h"

namespace browser {
    namespace elements {
        class A: public browser::elements::GenericTextElement {
            private:
            public:
                const browser::elements::properties defaultProperties = {
                    .display = Inline,
                    .x = 0, .y = 0,
                    .height = 0, .width = 0,
                    .maxHeight = 0, .maxWidth = 0,

                    .padding = {0, 0, 0, 0},
                    .margin = {16, 0, 16, 0},

                    .fontSize = 16,
                    .fontStyle = Normal,

                    .color = {55, 55, 255, 255},
                    .background = {255, 255, 255, 0}
                };
                
                A(std::string content) : browser::elements::GenericTextElement(content) {
                    this->properties = this->defaultProperties;
                }
        };
    }
}