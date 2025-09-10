#include "world.h"
#include "translation.h"

#include <iostream>
#include <memory>

namespace qprt {
    World::World() {
        // Default world
        this->lightSources = std::vector<Light>();
        this->lightSources.push_back(Light(Point(-10, 10, -10), Color(1, 1, 1)));

        this->renderables = std::vector<Sphere>();
        this->renderables.push_back(Sphere(Point(-1, 0, 1), 0.5));
        this->renderables[0].material.color = Color(0.8, 1.0, 0.6);
        this->renderables[0].material.diffuse = 0.7;
        this->renderables[0].material.specular = 0.2;

        this->renderables.push_back(Sphere(Point(1, 0, 1), 0.5));
        this->renderables[1].material = Material(Color(1, 0, 0));

        std::cout << this->renderables[0].transform.get().to_string() << std::endl;
        std::cout << this->renderables[1].transform.get().to_string() << std::endl;
        std::cout << (CreateTranslationMatrix(1, 1, 0) * CreateScalingMatrix(0.5, 0.5, 0.5)).to_string() << std::endl;
    }

    std::vector<Intersection> World::intersect_world(Ray ray) const {
        auto xs = std::vector<Intersection>();
        for(int i = 0; i < this->renderables.size(); ++i) {
            auto s = find_intersects(ray, std::make_shared<Sphere>(this->renderables[i]));
            for (int j = 0; j < s.size(); ++j) {
                xs.push_back(s[j]);
            }
        }

        return xs;
    }

    Comps World::prepare_computations(Intersection xs, Ray ray) const {
        Comps comp = Comps();
        comp.object = xs.object;
        comp.t = xs.t;
        comp.point = ray.direction * xs.t + ray.origin;
        comp.eyev = -ray.direction;
        comp.normalv = xs.object->NormalAt(comp.point);
        if (dot_product(comp.normalv, comp.eyev)) {
            comp.inside = true;
            //comp.normalv = -comp.normalv;
        }
        return comp;
    }

    Color World::shade_hit(Comps comps) const {
        return lighting(comps.object->material, this->lightSources[0], comps.point, comps.eyev, comps.normalv);
    }

    Color World::color_at(Ray ray) const {
        auto xs = this->intersect_world(ray);
        if (xs.size() == 0) {
            return BLACK;
        }
        // Sort xs
        for(int i = 0; i < xs.size()-1; ++i) {
            for(int j = i; j < xs.size(); ++j) {
                if (xs[i].t > xs[j].t) {
                    auto tmp = xs[i];
                    xs[i] = xs[j];
                    xs[j] = tmp;
                }
            }
        }

        auto comps = this->prepare_computations(xs[0], ray);
        return this->shade_hit(comps);
    }
}