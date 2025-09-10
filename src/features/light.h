#pragma once

#include "tuple.h"
#include "color.h"
#include "material.h"

namespace qprt {
    class Light {
        public:
            Tuple position;
            Color intensity;
            Light(Tuple, Color);
    };

    Color lighting(Material, Light, Tuple, Tuple, Tuple);
}