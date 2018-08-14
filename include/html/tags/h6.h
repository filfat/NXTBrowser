#pragma once

#include <iostream>

#include "../properties.h"

namespace browser {
    namespace elements {
        class H6: public browser::elements::GenericTextElement {
            private:
            public:
                const browser::elements::properties defaultProperties = {
                    display: Block,
                    x: 0, y: 0,
                    height: 0, width: 0,
                    maxHeight: DEVICE_HEIGHT, maxWidth: DEVICE_WIDTH,

                    padding: {0, 0, 0, 0},
                    margin: {12, 0, 12, 0},

                    fontSize: 12,
                    fontStyle: Bold,

                    color: {55, 55, 55, 255},
                    background: {255, 255, 255, 0}
                };
                
                H6(std::string content) : browser::elements::GenericTextElement(content) {
                    this->properties = this->defaultProperties;
                }
        };
    }
}