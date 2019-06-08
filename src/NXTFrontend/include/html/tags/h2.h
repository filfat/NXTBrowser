#pragma once

#include <iostream>

#include "../properties.h"

namespace browser {
    namespace elements {
        class H2: public browser::elements::GenericTextElement {
            private:
            public:
                const browser::elements::properties defaultProperties = {
                    .display = Block,
                    .x = 0, .y = 0,
                    .height = 0, .width = 0,
                    .maxHeight = 0, .maxWidth = 0,

                    .padding = {0, 0, 0, 0},
                    .margin = {14, 0, 14, 0},

                    .fontSize = 24,
                    .fontStyle = Bold,

                    .color = {55, 55, 55, 255},
                    .background = {255, 255, 255, 0}
                };
                
                H2(std::string content) : browser::elements::GenericTextElement(content) {
                    this->properties = this->defaultProperties;
                }
        };
    }
}