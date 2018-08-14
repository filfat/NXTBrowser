#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#ifdef __SWITCH__
#include <SDL2/SDL2_gfxPrimitives.h>
#endif
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

static SDL_Window *_window;
static SDL_Renderer *_renderer;
static SDL_Surface *_surface;
static SDL_Texture *_background_texture;

namespace sdl_helper {
    void init() {
        SDL_Init(SDL_INIT_EVERYTHING);
        #ifdef __SWITCH__
        SDL_CreateWindowAndRenderer(1280, 720, 0, &_window, &_renderer);
        #elif __MACOS__
        _window = SDL_CreateWindow(
            "NXTBrowser",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            1280,
            720,
            SDL_WINDOW_OPENGL
        );
        _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
        #endif
        _surface = SDL_GetWindowSurface(_window);
        SDL_SetRenderDrawBlendMode(_renderer, SDL_BLENDMODE_BLEND);
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
        IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_WEBP | IMG_INIT_TIF);
        TTF_Init();

        SDL_Surface *_background_surface = IMG_Load("romfs:/gui/browser.png");
        _background_texture = SDL_CreateTextureFromSurface(_renderer, _background_surface);
    }

    void exit() {
        TTF_Quit();
        IMG_Quit();
        SDL_DestroyRenderer(_renderer);
        //SDL_FreeSurface(_surface);
        SDL_DestroyWindow(_window);
        SDL_Quit();
    }

    void drawTexture(SDL_Surface *surf, SDL_Texture *tex, int x, int y) {
        SDL_Rect position;
        position.x = x;
        position.y = y;
        position.w = surf->w;
        position.h = surf->h;
        SDL_RenderCopy(_renderer, tex, NULL, &position);
    }

    SDL_Rect renderText (std::string text, SDL_Surface *surf, SDL_Rect pos, int width,
                        TTF_Font *font, SDL_Color color) {

        SDL_Surface *surface = TTF_RenderUTF8_Blended_Wrapped(font, text.c_str(), color, width);
        SDL_SetSurfaceAlphaMod(surface, 255);
        
        SDL_Rect size;
        size.x = pos.x;
        size.y = pos.y;
        size.h = surface->h;
        size.w = surface->w;

        SDL_BlitSurface(surface, NULL, surf, &size);
        SDL_FreeSurface(surface);
        return size;
    }

    void renderBackground (SDL_Surface *surf, SDL_Rect pos, SDL_Color color) {
        SDL_FillRect(surf, &pos, SDL_MapRGBA(surf->format, color.r, color.g, color.b, color.a));
    }

    // deprecated, remove asap
    void drawRect(SDL_Surface *surf, int x, int y, int w, int h, int r, int b, int g, int a) {
        SDL_Rect pos;
        pos.x = x;
        pos.y = y;
        pos.h = h;
        pos.w = w;
        SDL_FillRect(surf, &pos, SDL_MapRGBA(surf->format, r, g, b, a));
    }
    
    // deprecated, remove asap
    SDL_Rect drawText(SDL_Surface *surf, int x, int y, std::string text, TTF_Font *font, bool center = false, int cr = 0, int cg = 0, int cb = 0, int ca = 255) {
        return renderText(text, surf, {x, y, 0, 0}, DEVICE_WIDTH, font, {(unsigned char)cr, (unsigned char)cg, (unsigned char)cb, (unsigned char)ca});
    }
}