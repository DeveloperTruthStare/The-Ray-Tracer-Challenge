#pragma once

#include <vector>

#include "tuple.h"

namespace qprt
{
    class Matrix
    {
     public:
        Matrix(std::initializer_list<std::initializer_list<float>>);
        float get(int, int) const;
        size_t rows, cols;
        std::vector<std::vector<float>> data;

        bool operator==(const Matrix&) const;
        bool operator!=(const Matrix&) const;

        Tuple operator*(const Tuple&) const;
    };
}
