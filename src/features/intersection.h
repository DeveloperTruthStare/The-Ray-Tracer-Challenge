#pragma once

#include "tuple.h"
#include "sphere.h"
#include <memory>

namespace qprt {
    struct Intersection {
        public:
            Intersection(float t, std::shared_ptr<Sphere> o);
        float t;
        std::shared_ptr<Sphere> object;

    };
}