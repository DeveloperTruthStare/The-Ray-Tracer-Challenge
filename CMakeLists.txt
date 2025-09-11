cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(RayTracerChallenge)

file(GLOB_RECURSE RAYTRACER_SOURCES
	src/*.cpp
	src/*.h
	src/features/*.cpp
	src/features/*.h
)

add_executable(
	raytracer
	${RAYTRACER_SOURCES}
)
