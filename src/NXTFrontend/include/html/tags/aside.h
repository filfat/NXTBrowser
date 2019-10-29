#pragma once

#include <iostream>

#include "../properties.h"
#include "p.h"

namespace browser {
    namespace elements {
        // Duplicate of P tag
        class Aside: public browser::elements::P {
            private:
            public:
                Aside(std::string content) : browser::elements::P(content) { }
        };
    }
}