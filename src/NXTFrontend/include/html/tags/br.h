#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>



#include "../properties.h"
#include "genericElement.h"

namespace browser {
    namespace elements {
        class Br: public browser::elements::GenericElement {
            private:
            public:
                const browser::elements::properties defaultProperties = {
                    .display = Block,
                    .x = 0, .y = 0,
                    .height = 0, .width = 0,
                    .maxHeight = 0, .maxWidth = 0,

                    .padding = {0, 0, 0, 0},
                    .margin = {16, 0, 16, 0},
                };
                
                Br() : browser::elements::GenericElement() {
                    this->properties = this->defaultProperties;
                }
        };
    }
}