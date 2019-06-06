#pragma once
#include "../main.h"

namespace browser {
    namespace elements {
        enum elementTypes {
            Container,
            Text,
            Interactable,
            Special
        };

        enum displayModes {
            Inline,
            InlineBlock,
            InlineFlex,
            InlineGrid,
            InlineTable,

            Block,
            Contents,
            Flex,
            Grid,
            Table
        };

        enum fontModes {
            Normal,
            Bold,
            Italic,
            Underline,
            Strikethrough,
        };

        struct color {
            /* color(short r, short g, short b, short a):
                r(r), g(g), b(b), a(a) {} */

            short r = 0, g = 0, b = 0, a = 0;
        };

        struct position {
            /* position(int top, int right, int bottom, int left):
                top(top), right(right), bottom(bottom), left(left) {} */

            int top = 0, right = 0, 
            bottom = 0, left = 0;
        };

        struct size {
            /* size(int height, int width):
                height(height), width(width) {} */

            int height = 0,
                width = 0;
        };

        struct properties {
            /* properties(displayModes display,
                int x, int y,
                int height, int width,
                int maxHeight, int maxWidth,
                int minHeight, int minWidth,

                browser::elements::position padding, browser::elements::position margin,

                short lineHeight, short fontSize,
                fontModes fontStyle,
                browser::elements::color color,
                browser::elements::color background
            ): display(display), x(x), y(y),
                height(height), width(width),
                maxHeight(maxHeight), maxWidth(maxWidth),
                minHeight(minHeight), minWidth(minWidth),

                padding(padding), margin(margin),

                lineHeight(lineHeight), fontSize(fontSize),
                fontStyle(fontStyle),

                color(color), background(background) {} */

            displayModes display = Block;
            int x = 0, y = 0;
            int height = 0, width = 0;
            int maxHeight = 0, maxWidth = 0;
            int minHeight = 0, minWidth = 0;

            browser::elements::position padding; // = browser::elements::position{0, 0, 0, 0};
            browser::elements::position margin; // = browser::elements::position{0, 0, 0, 0};

            short lineHeight = 0;
            short fontSize = 0;
            fontModes fontStyle = Normal;

            browser::elements::color color; // = browser::elements::color{0, 0, 0, 255};
            browser::elements::color background; // = browser::elements::color{255, 255, 255, 255};
        };

        struct renderQueueItem {
            browser::elements::size size;
            browser::elements::properties properties;
        };
    }
}