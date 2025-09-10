#include "material.h"

namespace qprt {
    Material::Material() {
        this->ambient = 0.1;
        this->diffuse = 0.9;
        this->specular = 0.9;
        this->shininess = 200;
        this->color = Color(1, 1, 1);
    }

    Material::Material(Color color) {
        this->color = color;
        this->ambient = 0.1;
        this->diffuse = 0.9;
        this->specular = 0.9;
        this->shininess = 200;
    }
}