#include "light.h"
#include "material.h"
#include "tuple.h"
#include "color.h"
#include "ray.h"
#include <cmath>

namespace qprt {
    Light::Light(Tuple position, Color intensity) {
        this->position = position;
        this->intensity = intensity;
    }

    Color lighting(Material m, Light light, Tuple point, Tuple eyeV, Tuple normalV) {
        auto effective_color = m.color * light.intensity;
        auto lightv = (light.position - point).normal();
        auto ambient = effective_color * m.ambient;

        auto light_dot_normal = dot_product(lightv, normalV);

        auto diffuse = BLACK;
        auto specular = BLACK;

        if (light_dot_normal >= 0) {
            diffuse = effective_color * m.diffuse * light_dot_normal;
            auto reflectV = reflect(-lightv, normalV);
            auto reflect_dot_eye = dot_product(reflectV, eyeV);
            if (reflect_dot_eye > 0) {
                auto factor = std::pow(reflect_dot_eye, m.shininess);
                specular = light.intensity * m.specular * factor;    
            }
        }
        
        return ambient + diffuse + specular;
    }
}