cmake_minimum_required(VERSION 3.10)

project(RayTracerChallenge)

# Add Google Test
add_subdirectory(googletest)

enable_testing()

set(SRC_TEST
	tests/tuple_tests.cpp
	tests/color_tests.cpp
	tests/canvas_tests.cpp
    tests/matrix_tests.cpp
)

set(SRC_CORE
	src/features/tuple.cpp
	src/features/color.cpp
	src/features/canvas.cpp
    src/features/matrix.cpp
)

set(SRC_EXE
	src/main.cpp
)

add_library(
	rtcore
	${SRC_CORE}
)

add_executable(
	raytracer
	${SRC_EXE}
)

target_link_libraries (
	raytracer
	rtcore
)

add_executable(
	RTTests
	${SRC_TEST}
)

target_link_libraries(
	RTTests
	rtcore
	gtest
	gtest_main
)

add_test(
	NAME RTTests
	COMMAND RTTests
)
