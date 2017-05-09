cmake_minimum_required(VERSION 3.7)
project(kinect_depth_data_filtering)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        ctmf.c
        ctmf.h
        drsfilter.cpp
        drsfilter.h
        drsfilterdata.h
        filters.cpp
        filters.h
        fmm.cpp
        fmm.h
        fmmdata.h
        gradientfilter.cpp
        gradientfilter.h
        medianfilter.cpp
        medianfilter.h)

add_executable(kinect_depth_data_filtering ${SOURCE_FILES})