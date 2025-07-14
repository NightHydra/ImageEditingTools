//
// Created by Alek on 7/13/2025.
//

#ifndef IMAGEEDITINGTOOLS_H
#define IMAGEEDITINGTOOLS_H

#include <opencv2/opencv.hpp>
#include "OpenCVtoMathMatrix.h"

MathMatrix create_projection_img_matrix(const MathMatrix& original_matrix, const MathVector& projection_color);
cv::Mat load_color_img(const std::string & fpath);
bool save_color_img(const std::string & fpath, const cv::Mat& img);

#endif //IMAGEEDITINGTOOLS_H
