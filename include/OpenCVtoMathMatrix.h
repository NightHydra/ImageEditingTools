//
// Created by Alek on 7/13/2025.
//

#ifndef OPENCV_TO_MATH_MATRIX_H_
#define OPENCV_TO_MATH_MATRIX_H_

#include <string>
#include <opencv2/opencv.hpp>

#include <MatrixLibrary/matrix_library.h>

void loadImageToMatrix(MathMatrix& blank_matrix, std::string file_path);
bool convert_color_matrix_to_img(cv::Mat & ImMat, MathMatrix& pixels, int width, int height);

#endif //OPENCV_TO_MATH_MATRIX_H_
