#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
#include <string>

using namespace std;
using namespace cv;

class Interface
{
private:
  vector<string> filters;
  vector<string> flags;
  string inputPath;
  string outputPath;
  Mat image;

  void config();
  void validate();
  void saveImage();
  void previewImage();

public:
  Interface(string inputImagePath, string outputImagePath, vector<string> pFilters, vector<string> pFlags);
  void handleFilters();
};

#endif