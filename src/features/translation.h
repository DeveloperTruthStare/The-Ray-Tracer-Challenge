#pragma once

#include "matrix.h"

namespace qprt {
    Matrix CreateTranslationMatrix(float x, float y, float z);
    Matrix CreateScalingMatrix(float, float, float);
    Matrix CreateRotationMatrix_X(float);
    Matrix CreateRotationMatrix_Y(float);
    Matrix CreateRotationMatrix_Z(float);
    Matrix CreateShearingMatrix(float, float, float, float, float, float);
}
