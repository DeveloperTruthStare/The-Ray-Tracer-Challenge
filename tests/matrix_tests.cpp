#include <gtest/gtest.h>
#define EPSILON 0.000001

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

TEST(Matrix, MatrixMultiplication) {
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
