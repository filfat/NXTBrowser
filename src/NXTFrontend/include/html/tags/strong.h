#pragma once

#include <iostream>

#include "../properties.h"

namespace browser {
    namespace elements {
        // Duplicate of B tag
        class Strong: public browser::elements::B {
            private:
            public:
                Strong(std::string content) : browser::elements::B(content) { }
        };
    }
}