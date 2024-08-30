#include <gtest/gtest.h>
#define EPSILON 0.001

#include "../src/features/matrix.h"



using namespace qprt;

TEST(Matrix, CreateMatrix) {
    // GIVEN
    Matrix m = {
        {1, 2, 3, 4},
        {5.5, 6.5, 7.5, 8.5},
        {9, 10, 11, 12},
        {13.5, 14.5, 15.5, 16.5}
    };

    // WHEN
    

    // THEN
    ASSERT_NEAR(m.get(0, 0), 1, EPSILON);
    ASSERT_NEAR(m.get(0, 1), 2, EPSILON);
    ASSERT_NEAR(m.get(0, 2), 3, EPSILON);
    ASSERT_NEAR(m.get(0, 3), 4, EPSILON);
    ASSERT_NEAR(m.get(1, 0), 5.5, EPSILON);
    ASSERT_NEAR(m.get(1, 1), 6.5, EPSILON);
    ASSERT_NEAR(m.get(1, 2), 7.5, EPSILON);
    ASSERT_NEAR(m.get(1, 3), 8.5, EPSILON);
    ASSERT_NEAR(m.get(2, 0), 9, EPSILON);
    ASSERT_NEAR(m.get(2, 1), 10, EPSILON);
    ASSERT_NEAR(m.get(2, 2), 11, EPSILON);
    ASSERT_NEAR(m.get(2, 3), 12, EPSILON);
    ASSERT_NEAR(m.get(3, 0), 13.5, EPSILON);
    ASSERT_NEAR(m.get(3, 1), 14.5, EPSILON);
    ASSERT_NEAR(m.get(3, 2), 15.5, EPSILON);
    ASSERT_NEAR(m.get(3, 3), 16.5, EPSILON);
}

TEST(Matrix, 2x2Matrix) {
    // GIVEN
    Matrix mat = {
        {1, 2},
        {3, 4}
    };

    // WHEN
    int rows = mat.rows;
    int cols = mat.cols;

    // THEN
    ASSERT_EQ(rows, 2);
    ASSERT_EQ(cols, 2);
}

TEST(Matrix, 3x3Matrix) {
    // GIVEN
    Matrix mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // WHEN
    int rows = mat.rows;
    int cols = mat.cols;

    // THEN
    ASSERT_EQ(rows, 3);
    ASSERT_EQ(cols, 3);

}

TEST(Matrix, EqualsOperator) {
    // GIVEN
    Matrix A = { {1, 2}, {3, 4} };
    Matrix B = { {1, 2}, {3, 4} };

    // WHEN
    bool result = A == B;

    // THEN
    ASSERT_EQ(result, true);
}

TEST(Matrix, NotEqualsOperator) {
    // GIVEN
    Matrix A = { {1, 2}, {3, 4} };
    Matrix B = { {1, 1}, {1, 1} };

    // WHEN
    bool result = A != B;

    // THEN
    ASSERT_EQ(result, true);
}

TEST(Matrix, MatrixMultiplyTuple) {
    // GIVEN
    Matrix A = {
        {1, 2, 3, 4},
        {2, 4, 4, 2},
        {8, 6, 4, 1},
        {0, 0, 0, 1}
    };
    Tuple b(1, 2, 3, 1);

    // WHEN
    Tuple result = A * b;

    // THEN
    ASSERT_NEAR(result[0], 18, EPSILON);
    ASSERT_NEAR(result[1], 24, EPSILON);
    ASSERT_NEAR(result[2], 33, EPSILON);
    ASSERT_NEAR(result[3], 1, EPSILON);

}

TEST(Matrix, MatrixMultiplyMatrix) {
    // GIVEN
    Matrix A = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 8, 7, 6},
        {5, 4, 3, 2}
    };
    Matrix B = {
        {-2, 1, 2, 3},
        {3, 2, 1, -1},
        {4, 3, 6, 5},
        {1, 2, 7, 8}
    };

    // WHEN
    Matrix Result = A * B;

    // THEN
    ASSERT_NEAR(Result.get(0, 0), 20, EPSILON);
    ASSERT_NEAR(Result.get(0, 1), 22, EPSILON);
    ASSERT_NEAR(Result.get(0, 2), 50, EPSILON);
    ASSERT_NEAR(Result.get(0, 3), 48, EPSILON);
    ASSERT_NEAR(Result.get(1, 0), 44, EPSILON);
    ASSERT_NEAR(Result.get(1, 1), 54, EPSILON);
    ASSERT_NEAR(Result.get(1, 2), 114, EPSILON);
    ASSERT_NEAR(Result.get(1, 3), 108, EPSILON);
    ASSERT_NEAR(Result.get(2, 0), 40, EPSILON);
    ASSERT_NEAR(Result.get(2, 1), 58, EPSILON);
    ASSERT_NEAR(Result.get(2, 2), 110, EPSILON);
    ASSERT_NEAR(Result.get(2, 3), 102, EPSILON);
    ASSERT_NEAR(Result.get(3, 0), 16, EPSILON);
    ASSERT_NEAR(Result.get(3, 1), 26, EPSILON);
    ASSERT_NEAR(Result.get(3, 2), 46, EPSILON);
    ASSERT_NEAR(Result.get(3, 3), 42, EPSILON);
}

TEST(Matrix, MultiplyByIdentity) {
    // GIVEN
    Matrix A = {
        {0, 1, 2, 4},
        {1, 2, 4, 8},
        {2, 4, 8, 16},
        {4, 8, 16, 32}
    };
    Matrix identity_matrix = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    // WHEN
    auto result = A * identity_matrix;

    // THEN
    ASSERT_EQ(A, result);
}

TEST(Matrix, TransposeMatrix) {
    // GIVEN
    Matrix A = {
        {0, 9, 3, 0},
        {9, 8, 0, 8},
        {1, 8, 5, 3},
        {0, 0, 5, 8}
    };

    // WHEN
    auto transpose = A.T();

    // THEN
    for(size_t row = 0; row < A.rows; ++row)
    {
        for(size_t col = 0; col < A.cols; ++col)
        {
            ASSERT_NEAR(A.get(row, col), transpose.get(col, row), EPSILON);
        }
    }
}

TEST(Matrix, SubMatrix) {
    // GIVEN
    Matrix A = {
        {1, 5, 7},
        {-3, 2, 7},
        {0, 6, 3}
    };
    Matrix answer = {
        {-3, 2},
        {0, 6}
    };

    // WHEN
    auto subMatr = A.sub_matrix(0, 2);

    // THEN
    ASSERT_EQ(subMatr, answer);
}

TEST(Matrix, Determinant2X2) {
    // GIVEN
    Matrix A = {
        {5, 0},
        {-1, 5}
    };

    // WHEN
    auto det = A.determinant();

    // THEN
    ASSERT_NEAR(det, 25, EPSILON);
}

TEST(Matrix, Determinant3x3) {
    // GIVEN
    Matrix A = {
        {1, 2, 6},
        {-5, 8, -4},
        {2, 6, 4}
    };

    // WHEN
    auto det = A.determinant();

    // THEN
    ASSERT_NEAR(det, -196, EPSILON);
}

TEST(Matrix, Determinant4x4) {
    // GIVEN
    Matrix A = {
        {-2, -8, 3, 5},
        {-3, 1, 7, 3},
        {1, 2, -9, 6},
        {-6, 7, 7, -9}
    };

    // WHEN
    auto det = A.determinant();

    // THEN
    ASSERT_NEAR(det, -4071, EPSILON);

}


TEST(Matrix, Inverse) {
    // GIVEN
    Matrix A = {
        {-5, 2, 6, -8},
        {1, -5, 1, 8},
        {7, 7, -6, -7},
        {1, -3, 7, 4}
    };
    Matrix answer = {
        {0.21805, 0.45113, 0.24060, -0.04511},
        {-0.80827, -1.45677, -0.44361, 0.52068},
        {-0.07895, -0.22368, -0.05263, 0.19737},
        {-0.52256, -0.81391, -0.30075, 0.30639}
    };
    // WHEN
    auto inv = A.inverse();
    auto det = A.determinant();

    // THEN
    ASSERT_NEAR(det, 532, EPSILON);
    for(size_t r = 0; r < 4; ++r)
    {
        for(size_t c = 0; c < 4; ++c)
        {
            ASSERT_NEAR(inv[r][c], answer[r][c], EPSILON);
        }
    }
}
