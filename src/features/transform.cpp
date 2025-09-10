#include "transform.h"
#include "translation.h"

namespace qprt {
    Transform::Transform() {
        this->transform = IdentityMatrix(4);
    }

    Matrix Transform::Inverse() const {
        return this->transform.inverse();
    }

    Matrix Transform::Transpose() const {
        return this->transform.T();
    }
    Matrix Transform::get() const {
        return this->transform;
    }

    void Transform::moveTo(float positionX, float positionY, float positionZ) {

    }
    void Transform::Scale(float scale) {
        this->transform = this->transform * CreateScalingMatrix(scale, scale, scale);
    }
    void Transform::Scale(float scaleX, float scaleY, float scaleZ) {
        this->transform = this->transform * CreateScalingMatrix(scaleX, scaleY, scaleZ);
    }

    Matrix Transform::operator=(const Matrix& rhs) {
        this->transform = rhs;
        return this->transform;
    }
}