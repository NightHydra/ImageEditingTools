//
// Created by Alek on 7/13/2025.
//

#include <vector>

#include "OpenCVtoMathMatrix.h"

/**
 * @brief A function that converts a color image matrix to a MathMatrix object
 *     that calculations can be performed on.  The matrix placed in @ref blank_matrix
 *     will be a 3x(w*h) matrix where each column is the RGB value of pixel (h,w) where
 *     h is the height of the image and w is the width.  Column 1 will represent pixel
 *     (0,1) in the matrix though
 * @param blank_matrix
 * @param ImMap Is an RGB opened opencv image to read the pixels from.
 */
void fill_matrix_with_pixel_colors(MathMatrix& blank_matrix, cv::Mat & ImMat)
{
    blank_matrix.clear();

    for (int r = 0; r<ImMat.rows; r++)
    {
        for (int c = 0; c<ImMat.cols; c++)
        {
            std::vector<double> value = ImMat.at<std::vector<double>>(r, c);

            blank_matrix.addCol(MathVector(value));
        }
    }
}

bool convert_color_matrix_to_img(cv::Mat & ImMat, MathMatrix& pixels, int width, int height)
{
    if (width <= 0 || height <= 0 || width * height != pixels.getNumCols() || 3 != pixels.getNumRows())
    {
        return false;
    }
    // Just set it to a new image to replace the old image
    ImMat = cv::Mat(height, width, CV_8UC3, cv::Scalar(255, 255, 255));

    int pixel_row_ind = 0;
    int pixel_col_ind = 0;

    for (unsigned int c = 0; c < pixels.getNumCols(); c++)
    {
        // Create a new 3d vector for the color
        cv::Vec3b color;
        unsigned char ind = 0;
        for (MathMatrix::colIterator itr = pixels.colBegin(c); itr != pixels.colEnd(c); ++itr)
        {
            color[ind] = static_cast<int>(*itr);
            ++ind;
        }
        ImMat.at<cv::Vec3b>(pixel_row_ind, pixel_col_ind) = color;

        ++pixel_row_ind;
        if (pixel_row_ind == width)
        {
            pixel_row_ind = 0;
            ++pixel_col_ind;
        }
    }
    return true;
}
