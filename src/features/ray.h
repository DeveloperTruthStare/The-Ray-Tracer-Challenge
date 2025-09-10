#pragma once

#include "tuple.h"
#include "intersection.h"
#include <vector>
#include <optional>

namespace qprt {
    class Ray {
        public:
            Tuple origin, direction;
            Ray(Tuple origin, Tuple direction);
            std::string to_string() const;
    };   

    Tuple Position(Ray ray, float t);
    std::vector<Intersection> find_intersects(const Ray& ray, const std::shared_ptr<Sphere>& object);
    std::optional<Intersection> hit_sorted(std::vector<Intersection>);
    std::optional<Intersection> hit(std::vector<Intersection>);

    Tuple reflect(Tuple in, Tuple normal);
}