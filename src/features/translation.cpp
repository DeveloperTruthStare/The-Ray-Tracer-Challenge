#include "translation.h"
#include <cmath>

namespace qprt {
    Matrix CreateTranslationMatrix(float x, float y, float z) {
        Matrix I4 = IdentityMatrix(4);
        I4[0][3] = x;
        I4[1][3] = y;
        I4[2][3] = z;

        return I4;
    }

    Matrix CreateScalingMatrix(float scaleX, float scaleY, float scaleZ) {
        Matrix scaler = Matrix(4, 4);
        scaler[0][0] = scaleX;
        scaler[1][1] = scaleY;
        scaler[2][2] = scaleZ;
        scaler[3][3] = 1;

        return scaler;
    }

    Matrix CreateRotationMatrix_X(float rotation) {
        auto xRotator = IdentityMatrix(4);
        xRotator[1][1] = std::cos(rotation);
        xRotator[1][2] = -std::sin(rotation);
        xRotator[2][1] = -std::sin(rotation);
        xRotator[2][2] = std::cos(rotation);

        return xRotator;
    }
    Matrix CreateRotationMatrix_Y(float rotation) {
        auto yRotator = IdentityMatrix(4);
        yRotator[0][0] = std::cos(rotation);
        yRotator[0][2] = std::sin(rotation);
        yRotator[2][0] = -std::sin(rotation);
        yRotator[2][2] = std::cos(rotation);

        return yRotator;
    }
    Matrix CreateRotationMatrix_Z(float rotation) {
        auto zRotator = IdentityMatrix(4);
        zRotator[0][0] = std::cos(rotation);
        zRotator[0][1] = -std::sin(rotation);
        zRotator[1][0] = std::sin(rotation);
        zRotator[1][1] = std::cos(rotation);

        return zRotator;
    }

    Matrix CreateShearingMatrix(float Xy, float Xz, float Yx, float Yz, float Zx, float Zy) {
        Matrix shearingMatrix = {
            {1, Xy, Xz, 0},
            {Yx, 1, Yz, 0},
            {Zx, Zy, 1, 0},
            {0, 0, 0, 1}
        };
        return shearingMatrix;
    }
}