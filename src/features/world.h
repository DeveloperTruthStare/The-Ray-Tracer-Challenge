#pragma once

#include <vector>
#include "light.h"
#include "sphere.h"
#include "ray.h"
#include "intersection.h"
#include "comps.h"

#include <vector>

namespace qprt {
    class World {
        public:
            World();
            std::vector<Intersection> intersect_world(Ray) const;
            Comps prepare_computations(Intersection, Ray) const;
            Color shade_hit(Comps) const;
            Color color_at(Ray) const;
        private:
            std::vector<Light> lightSources;
            std::vector<Sphere> renderables;
    };
}