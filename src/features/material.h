#pragma once

#include "color.h"

namespace qprt {
    class Material {
        public:
            float ambient;
            float diffuse;
            float specular;
            float shininess;
            Color color;
            Material();
            Material(Color);
    };
}