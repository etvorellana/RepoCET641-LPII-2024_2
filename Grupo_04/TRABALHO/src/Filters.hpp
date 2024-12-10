#ifndef FILTERS_HPP
#define FILTERS_HPP

#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
#include <string>

using namespace std;
using namespace cv;

class Filters
{
public:
  void blur(Mat &inputImage);
  void medianBlur(Mat &inputImage);
  void gaussianBlur(Mat &inputImage);
};

#endif