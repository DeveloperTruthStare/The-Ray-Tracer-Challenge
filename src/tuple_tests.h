#pragma once
#include "tuple.h"

namespace qprt::test
{
	void print_tuple(Tuple);
	void create_point();
	void create_vector();
	void add_vector_point();
	void subtract_point_point();
	void subtract_point_vector();
	void negate_tuple();
	void multiply_tuple_scalar();
	void multiply_scalar_tuple();
	void divide_tuple_scalar();
	void magnitude(Tuple);
	void normalize();
	void dot_test();
	void cross_test();
	void run_all_tests_tuple();
}
