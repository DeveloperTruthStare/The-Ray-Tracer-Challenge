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

    Matrix::Matrix(size_t rows, size_t cols)
    {
        this->rows = rows;
        this->cols = cols;
        this->data.resize(rows);

        for(auto i = 0; i < rows; ++i)
        {
            this->data[i].resize(cols);
        }
    }

    float Matrix::get(size_t row, size_t col) const
    {
        return this->data[row][col];
    }


    Matrix Matrix::T() const
    {
        auto t = Matrix(this->cols, this->rows);
        for(size_t row = 0; row < this->rows; ++row)
        {
            for(size_t col = 0; col < this->cols; ++col)
            {
                t[col][row] = this->data[row][col];
            }
        }
        return t;
    }

    Matrix Matrix::sub_matrix(size_t row, size_t col) const
    {
        auto result = Matrix(this->rows-1, this->cols-1);
        size_t r = 0;
        size_t c = 0;
        for(size_t i = 0; i < this->rows; ++i)
        {
            if (i != row)
            {
                c = 0;
                for(size_t j = 0; j < this->cols; ++j)
                {
                    if (j != col)
                    {
                        result[r][c] = this->data[i][j];
                        c++;
                    }
                }
                r++;
            }
        }
        return result;
    }

    float Matrix::determinant() const
    {
        if (this->rows != this->cols) throw new std::out_of_range("Must have same rows and cols to calculate determinant");
        float result = 0.0;
        if (this->rows == 2)
        {
            return this->data[0][0] * this->data[1][1] - this->data[1][0] * this->data[0][1];
        }
        for(size_t i = 0; i < this->rows; ++i)
        {
            result += this->cofactor(i, 0) * this->data[i][0];
        }
        return result;
    }

    int Matrix::cofactor_sign(size_t row, size_t col) const
    {
        bool even = (row + col) % 2 == 0;
        return even * 1 + !even * -1;
    }

    float Matrix::cofactor(size_t row, size_t col) const
    {
        return this->cofactor_sign(row, col) * this->sub_matrix(row, col).determinant();
    }

    Matrix Matrix::inverse() const
    {
        auto inv = Matrix(this->rows, this->cols);

        auto det = this->determinant();


        for(size_t r = 0; r < this->rows; ++r)
        {
            for(size_t c = 0; c < this->cols; ++c)
            {
                inv[r][c] = this->cofactor(c, r) / det;
            }
        }
        return inv;
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


    std::vector<float>& Matrix::operator[](const size_t row)
    {
        return this->data[row];
    }

    std::vector<float> Matrix::operator[](const size_t row) const
    {
        return this->data[row];
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

    Matrix Matrix::operator*(const Matrix& other) const
    {
        if (this->cols != other.rows) throw new std::out_of_range("Matrix composition is not compatible for multiplication");

        Matrix result(this->rows, other.cols);
        for(size_t r = 0; r < result.rows; ++r)
        {
            for(size_t c = 0; c < result.cols; ++c)
            {
                for(int i = 0; i < this->cols; ++i)
                {
                    result[r][c] += this->get(r, i) * other.get(i, c);
                }
            }
        }
        return result;
    }
}
