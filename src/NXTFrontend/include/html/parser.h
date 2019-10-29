// TODO:
// --------------------------------------------------------------------------
// 
//                  New branch-based rendering/parse system
//
// --------------------------------------------------------------------------
// Every branch should be able to live in its own thread spawning another
// branch thread for every child
//
// body -> header -> h1
//      |         └> h2 -> span -> i
//      |
//      ├> main -> ...
//      |       |
//      |       ├> ...
//      |       |
//      |       └> ...
//      |
//      └> footer
//
// --------------------------------------------------------------------------
// Then we keep track of the relative index where n is the relative
// tree/branch index:
//    
// header       = 0:0
//   h1         = 0:0
//   h2         = 0:1
//     span     = 0:1:0
//       i      = 0:1:0:0
// main         = 1:0
// footer       = 2:0
//
// Each branch should be rendered into it's own surface.
// Which would give use the ability to only update the branch that changed.
// In this example that would be "h2", "main" and "footer"
//
// It would oossible even re-use surfaces that are identical, provided
// ofcourse that it saves more performance than it takes to compare
// each branch with eachother.
//
// --------------------------------------------------------------------------
//

#pragma once
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"

#include <iostream>
#include <vector>

#include "../main.h"
#include "html/elements.h"

namespace browser {
    namespace parser {
        int html_parser (const tinyxml2::XMLElement* child, std::string type, int position);
    }
}