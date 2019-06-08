#pragma GCC diagnostic ignored "-Wmissing-field-initializers"

#include <iostream>
#include <vector>

#include "html/parser.h"
#include "html/elements.h"

namespace browser {
    int parser::html_parser (const tinyxml2::XMLElement* child, std::string type, int position) {
        browser::elements::GenericElement *tag;
        browser::elements::renderQueueItem renderItem;

        std::string text = "";
        if (child && child->GetText())
            text = child->GetText();

        try {
            if (type == "h1") {
                tag = new browser::elements::H1(text);
            } else if (type == "h2") {
                tag = new browser::elements::H2(text);
            } else if (type == "h3") {
                tag = new browser::elements::H3(text);
            } else if (type == "h4") {
                tag = new browser::elements::H4(text);
            } else if (type == "h5") {
                tag = new browser::elements::H5(text);
            } else if (type == "h6") {
                tag = new browser::elements::H6(text);
            }
            
            else if (type == "p") {
                tag = new browser::elements::P(text);
            } else if (type == "font") {
                tag = new browser::elements::P(text);
            } else if (type == "aside") {
                tag = new browser::elements::P(text);
            } else if (type == "pre") {
                tag = new browser::elements::P(text);
            }
            
            else if (type == "b") {
                tag = new browser::elements::B(text);
            } else if (type == "strong") {
                tag = new browser::elements::Strong(text);
            }

            else if (type == "li") {
                text = std::string("• ") + text; // FIXME: let tag handle list icon
                tag = new browser::elements::Li(text);
            }

            else if (type == "a") {
                tag = new browser::elements::A(text);
            }
            
            else if (type == "br") {
                tag = new browser::elements::Br();
            }

            else {
                tag = new browser::elements::GenericElement();
                printf("DOM->Parser->Unsupported Tag: %s\n", type.c_str());
            }
        } catch(...) {
            printf("DOM->Parser->Error!\n");
        }

        /*switch (tag->elementType) {
            case browser::elements::elementTypes::Text:
                //renderItem = tag->getRenderQueueItem(_browser_surface);

                position += renderItem.properties.margin.top;

                #ifndef __NATIVE_GUI__
                    sdl_helper::renderText(text, _browser_surface,
                        {renderItem.properties.margin.left + renderItem.properties.padding.left,
                        position, 0, 0}, renderItem.properties.width, tag->getFont(), {0, 0, 0, 255});
                #endif

                position += renderItem.properties.height;
                position += renderItem.properties.margin.bottom;
                break;
            case browser::elements::elementTypes::Container:
                renderItem = tag->getRenderQueueItem(_browser_surface);
                position += renderItem.size.height;
                break;
            default:
                // TODO:
                break;
        }*/

        delete tag, renderItem;
        for(const tinyxml2::XMLElement* c = child->FirstChildElement(); c != NULL; c = c->NextSiblingElement()) {
            std::string type = c->Value();
            position = browser::parser::html_parser(c, type, position);
        }

        return position;
    }
}