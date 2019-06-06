#pragma once
#include <SDL2/SDL.h>

#include "../properties.h"

extern device_aspect DEVICE;

namespace browser {
    namespace elements {
        class GenericElement {
            private:
            public:
                TTF_Font *font;
                std::string content;

                browser::elements::elementTypes elementType = browser::elements::elementTypes::Container;
                const browser::elements::properties defaultProperties;
                browser::elements::properties properties;

                GenericElement () {
                    this->properties = this->defaultProperties;
                }
                virtual ~GenericElement () {
                    //delete &this->properties;
                    // delete &this->defaultProperties;
                }

                const browser::elements::properties getDefaultProperties () {
                    return defaultProperties;
                }

                void SetFont(TTF_Font *font) {};

                virtual TTF_Font* getFont() { return this->font; };
                virtual browser::elements::renderQueueItem getRenderQueueItem (SDL_Surface* _surface) {
                    // Update maxwidth & maxheight
                    #ifndef __NATIVE_GUI__
                        if(this->properties.maxWidth <= 0)
                            this->properties.maxWidth = _surface->w;
                        if(this->properties.maxHeight <= 0)
                            this->properties.maxHeight = _surface->h;
                    #endif

                    // Get element height and width
                    int width = this->properties.width, height = this->properties.height;
                    
                    // Add Padding
                    width       += (this->properties.padding.right + this->properties.padding.right) * DEVICE.scaling,
                    height      += (this->properties.padding.top + this->properties.padding.bottom)  * DEVICE.scaling;

                    // Add Margin
                    width       += (this->properties.margin.right + this->properties.margin.right) * DEVICE.scaling;
                    height      += (this->properties.margin.top + this->properties.margin.bottom) * DEVICE.scaling;

                    //printf("DOM->Parser->GenericElement->height: " + std::to_string(height));
                    //printf("DOM->Parser->GenericElement->width: " + std::to_string(width));

                    return (browser::elements::renderQueueItem) {
                        .size = {
                            height = height * DEVICE.scaling,
                            width = width * DEVICE.scaling
                        },
                        .properties = this->properties
                    };
                }
        };
    }
}