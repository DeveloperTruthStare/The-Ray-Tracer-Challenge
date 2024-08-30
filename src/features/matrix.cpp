#include <vector>

#include "matrix.h"
#include "tuple.h"

namespace qprt
{
    Matrix::Matrix(std::initializer_list<std::initializer_list<float>> init)
    {
        this->rows = init.size();
        this->cols = init.begin()->size();
        this->data.resize(rows);

        size_t row = 0;
        for (const auto& rowList : init) {
            this->data[row].assign(rowList);
            ++row;
        }
    }

    float Matrix::get(int row, int col) const
    {
        return this->data[row][col];
    }

    bool Matrix::operator==(const Matrix& other) const
    {
        if (this->rows != other.rows || this->cols != other.cols) return false;
        for(int i = 0; i < this->rows; ++i)
        {
            for(int j = 0; j < this->cols; ++j)
            {
                if (this->data[i][j] != other.get(i, j)) return false;
            }
        }
        return true;
    }
    
    bool Matrix::operator!=(const Matrix& other) const
    {
        if (this->rows != other.rows || this->cols != other.cols) return true;
        for(size_t i = 0; i < this->rows; ++i)
        {
            for(size_t j = 0; j < this->cols; ++j)
            {
                if (this->data[i][j] != other.get(i, j)) return true;
            }
        }
        return false;
    }

    Tuple Matrix::operator*(const Tuple& other) const
    {
        if (this->rows != 4 || this->cols != 4) {
            std::cerr << "Matrix size is not 4x4, returning original tuple\n";
            return other;
        }
        Tuple result(0, 0, 0, 0);
        for(int i = 0; i < 4; ++i)
        {
            result[i] = 0;
            for(int j = 0; j < 4; ++j)
            {
                result[i] += other[j] * this->data[i][j];
            }
        }
        return result;
    }
}
