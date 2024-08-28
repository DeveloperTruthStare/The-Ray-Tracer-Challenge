#include "main_tests.h"
#include "tuple_tests.h"
#include "color_tests.h"

namespace qprt::test
{
	void run_all_tests()
	{
		run_all_tests_tuple();
		run_all_tests_color();
	}
}
