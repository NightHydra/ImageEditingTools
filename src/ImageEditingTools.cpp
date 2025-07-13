//
// Created by Alek on 7/13/2025.
//

#include "ImageEditingTools.h"

MathMatrix create_projection_img_matrix(const MathMatrix& original_matrix, const MathVector& projection_color)
{
    MathMatrix projection_matrix = createProjectionMatrix(projection_color);
    return projection_matrix * original_matrix;
}

cv::Mat load_color_img(const std::string & fpath)
{
    return cv::imread(fpath, cv::IMREAD_COLOR);
}

bool save_color_img(const std::string & fpath, const cv::Mat& img)
{
    return cv::imwrite(fpath, img);
}


