#pragma once
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"

#include <iostream>

#include "../main.h"

#ifndef __NATIVE_GUI__
    struct font {
        TTF_Font* font;
        std::string fontPath;
        int fontSize;
    };
    struct fontSurface {
        TTF_Font *font;
        std::string text;
        SDL_Color color;
        int width;

        SDL_Surface *surface;
    };
#endif

static std::vector<font> fontCache;
static std::vector<fontSurface> fontSurfaceCache;
namespace browser {
    namespace utils {
        #ifndef __NATIVE_GUI__
            TTF_Font* get_font_from_cache(std::string path, int size) {
                /*if ((int)fontCache.size() > 5) {
                    TTF_CloseFont(fontCache.begin()->font);
                    fontCache.erase(fontCache.begin());
                }*/

                for (int i = 0; i < (int)fontCache.size(); i++) {
                    if (fontCache[i].fontSize == size && fontCache[i].fontPath == path) {
                        if (fontCache[i].font == NULL) {
                            fontCache.erase(fontCache.begin() + i);
                            continue;
                        }

                        return fontCache[i].font;
                    }
                }

                printf("APP->Loading font...");
                TTF_Font *font = TTF_OpenFont(path.c_str(), size);
                fontCache.push_back({ font, path, size });
                printf(" Done!\n");
                return font;
            }

            SDL_Surface* get_text_surface_from_cache(TTF_Font *font, std::string text, SDL_Color color, int width) {
                /*if ((int)fontSurfaceCache.size() > 45) {
                    SDL_FreeSurface(fontSurfaceCache.begin()->surface);
                    fontSurfaceCache.erase(fontSurfaceCache.begin());
                }*/

                for (int i = 0; i < (int)fontSurfaceCache.size(); i++) {
                    if ((fontSurfaceCache[i].width == width) &&
                        (fontSurfaceCache[i].text == text) &&
                        (fontSurfaceCache[i].color.r == color.r) &&
                        (fontSurfaceCache[i].color.g == color.g) &&
                        (fontSurfaceCache[i].color.b == color.b) &&
                        (fontSurfaceCache[i].color.a == color.a) &&
                        (fontSurfaceCache[i].font == font)) {

                        if (fontSurfaceCache[i].surface == NULL) {
                            fontSurfaceCache.erase(fontSurfaceCache.begin() + i);
                            continue;
                        }
                        
                        return fontSurfaceCache[i].surface;
                    }
                }

                SDL_Surface *surface = TTF_RenderUTF8_Blended_Wrapped(font, text.c_str(), color, width);
                fontSurfaceCache.push_back({
                    font,
                    text,
                    color,
                    width,
                    surface
                });
                return surface;
            }
        #endif
    }
}