cmake_minimum_required(VERSION 3.10)

project(RayTracerChallenge)

# Add Google Test
add_subdirectory(googletest)

enable_testing()

set(SRC_TEST
	src/tuple/tuple_tests.cpp
	src/color/color_tests.cpp
	src/canvas/canvas_tests.cpp
)

set(SRC_CORE
	src/tuple/tuple.cpp
	src/color/color.cpp
	src/canvas/canvas.cpp
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
