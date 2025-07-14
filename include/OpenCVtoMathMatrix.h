//
// Created by Alek on 7/13/2025.
//

#ifndef OPENCV_TO_MATH_MATRIX_H_
#define OPENCV_TO_MATH_MATRIX_H_

#include <string>
#include <opencv2/opencv.hpp>

#include <MatrixLibrary/matrix_library.h>

void fill_matrix_with_pixel_colors(MathMatrix& blank_matrix, const cv::Mat & ImMat);
bool convert_color_matrix_to_img(cv::Mat & ImMat, const MathMatrix& pixels, int width, int height);

#endif //OPENCV_TO_MATH_MATRIX_H_
