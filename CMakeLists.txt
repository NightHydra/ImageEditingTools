cmake_minimum_required(VERSION 3.31)
project(ImageEditingTools)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV)

add_library(image_editing_library src/OpenCVtoMathMatrix.cpp
        src/ImageEditingTools.cpp
        include/ImageEditingTools.h)

# Submodule Dependencies
add_subdirectory(libs/MatrixLibrary)
target_link_libraries(image_editing_library PUBLIC matrix_library ${OpenCV_LIBS})

target_include_directories(image_editing_library PUBLIC include)
target_include_directories(image_editing_library PUBLIC include/ImageEditingLibrary ${OpenCV_INCLUDE_DIRS})





