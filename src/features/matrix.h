#pragma once

#include <vector>

#include "tuple.h"

namespace qprt {
    class Matrix {
     public:
        Matrix(std::initializer_list<std::initializer_list<float>>);
        Matrix(size_t rows, size_t cols);
        float get(size_t, size_t) const;
        size_t rows, cols;
        std::vector<std::vector<float>> data;

        Matrix T() const;
        Matrix sub_matrix(size_t row, size_t col) const;

        float determinant() const;
        int cofactor_sign(size_t, size_t) const;
        float cofactor(size_t, size_t) const;
        Matrix inverse() const;

        bool operator==(const Matrix&) const;
        bool operator!=(const Matrix&) const;
        Matrix operator*(const Matrix&) const;
        Tuple operator*(const Tuple&) const;
        std::vector<float>& operator[](const size_t);
        std::vector<float> operator[](const size_t) const;

    };
}
