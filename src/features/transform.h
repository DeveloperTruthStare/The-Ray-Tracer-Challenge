#pragma once

#include "matrix.h"
#include "tuple.h"

namespace qprt {
    class Transform {
        public:
            Transform();
            Matrix Inverse() const;
            Matrix Transpose() const;
            Matrix get() const;

            void moveTo(Tuple);
            void moveTo(float, float, float);
            void Scale(float);
            void Scale(float, float, float);

            Matrix operator=(const Matrix& other);
        private:
            Matrix transform;
    };
}