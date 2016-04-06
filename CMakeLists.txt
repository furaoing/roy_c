cmake_minimum_required(VERSION 3.3)
project(zeus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        data_structure/b_tree.h
        IO/FileIO.h
        nlp/vocabulary_miner.h
        nn/prototpyes/prototypes.h
        util/mil/bigdataset_attack.cpp
        util/mil/insertion_sort.c
        util/mil/quick_sort.h
        util/mil/true_random.h
        util/mil/roy_system.h
        main.cpp
        data_structure/stack.h
        data_structure/graph.h
        util/mil/timer_example.h
        data_structure/stack_cpp.h

        util/mil/isPrime.h)

find_package(Boost REQUIRED)


include_directories( ${PROJECT_SOURCE_DIR})

add_executable(zeus ${SOURCE_FILES})
target_link_libraries(zeus ${Boost_LIBRARIES})