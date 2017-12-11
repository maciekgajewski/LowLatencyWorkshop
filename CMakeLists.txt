cmake_minimum_required(VERSION 2.8)

project(workshop)

add_subdirectory(google_benchmark benchmark EXCLUDE_FROM_ALL)

if (MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest")
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -g -Wall -Wextra")
endif()

if(NOT DEFINED BENCHMARK_ROOT)
	set(BENCHMARK_ROOT ${CMAKE_SOURCE_DIR}/google_benchmark)
endif()

include_directories(${BENCHMARK_ROOT}/include)
link_directories(${BENCHMARK_ROOT}/lib)

add_subdirectory(spellchecker)
add_subdirectory(dictionary_benchmark)

