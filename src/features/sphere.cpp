#include "sphere.h"
#include "translation.h"

namespace qprt {
    Sphere::Sphere(Tuple position, float radius) {
        this->transform = CreateTranslationMatrix(position.x, position.y, position.z) * CreateScalingMatrix(radius, radius, radius);
    }

    Tuple Sphere::NormalAt(Tuple point) {
        auto object_point = this->transform.Inverse() * point;
        auto object_normal = object_point - Point(0, 0, 0);
        auto worldNormal = this->transform.Inverse().T() * object_normal;
        worldNormal.w = 0;

        return worldNormal.normal();
    }
}