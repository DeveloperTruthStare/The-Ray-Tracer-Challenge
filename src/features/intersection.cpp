#include "intersection.h"

namespace qprt {
    Intersection::Intersection(float t, std::shared_ptr<Sphere> o) {
        this->t = t;
        this->object = o;
    }
}