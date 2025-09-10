#pragma once

#include "sphere.h"
#include <memory>

namespace qprt {
    class Comps {
        public:
        std::shared_ptr<Sphere> object;
        float t;
        Tuple point;
        Tuple eyev;
        Tuple normalv;
        bool inside;
        Comps();
    };
}