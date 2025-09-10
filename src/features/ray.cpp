#include "ray.h"
#include "sphere.h"
#include "intersection.h"

#include <vector>
#include <cmath>
#include <memory>
#include <optional>
#include <sstream>

namespace qprt {
    Ray::Ray(Tuple origin, Tuple direction) {
        this->origin = origin;
        this->direction = direction;
    }

    Tuple Position(Ray ray, float t) {
        return ray.origin + ray.direction * t;
    }
    
    std::string Ray::to_string() const {
        std::ostringstream oss;

        oss << "Origin: " << this->origin << ", Direction: " << this->direction << std::endl;

        return oss.str();
    }

    std::vector<Intersection> find_intersects(const Ray& ray, const std::shared_ptr<Sphere>& sphere) {
        auto intersections = std::vector<Intersection>();
        Ray ray2 = Ray(sphere->transform.Inverse() * ray.origin, sphere->transform.Inverse() * ray.direction);
        auto obj_to_ray = ray2.origin - sphere->transform.get() * Point(0, 0, 0);
        auto a = ray2.direction.SqrMagnitude();
        auto b = 2 * dot_product(ray2.direction, obj_to_ray);
        auto c = obj_to_ray.SqrMagnitude() - 1;

        auto discriminant = b * b - (4 * a * c);

        if (discriminant < 0) {
            return intersections;
        }

        auto t1 = (-b + std::sqrt(discriminant)) / (2 * a);
        auto t2 = (-b - std::sqrt(discriminant)) / (2 * a);

        if (t1 > t2) {
            auto tmp = t2;
            t2 = t1;
            t1 = tmp;
        }

        intersections.push_back(Intersection(t1, sphere));
        if (t1 != t2)
            intersections.push_back(Intersection(t2, sphere));

        return intersections;
    }

    std::optional<Intersection> hit_sorted(std::vector<Intersection> intersections) {
        // all intersections should be sorted from smallest to largest, even after being "merged"
        for (auto i = 0; i < intersections.size(); ++i) {
            if (intersections[i].t > 0) {
                return intersections[i];
            }
        }
        return std::nullopt;
    }

    std::optional<Intersection> hit(std::vector<Intersection> intersections) {
        int lowestPositiveIndex = -1;
        for (auto i = 0; i < intersections.size(); ++i) {
            if (intersections[i].t > 0) {
                if (lowestPositiveIndex == -1) {
                    lowestPositiveIndex = i;
                } else if (intersections[i].t < intersections[lowestPositiveIndex].t) {
                    lowestPositiveIndex = i;
                }
            }
        }
        if (lowestPositiveIndex == -1) {
            return std::nullopt;
        } else {
            return intersections[lowestPositiveIndex];
        }
    }

    Tuple reflect(Tuple in, Tuple normal) {
        return in - normal * 2 * dot_product(in, normal);
    }
}