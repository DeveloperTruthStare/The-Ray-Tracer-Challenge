#pragma once

#include "tuple.h"
#include "material.h"
#include "transform.h"

namespace qprt {
    class Sphere {
        public:
            Transform transform;
            Material material;
            float radius;
            Sphere(Tuple position, float radius);
            Tuple NormalAt(Tuple point);
    };
}