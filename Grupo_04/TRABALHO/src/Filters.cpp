#include "Filters.hpp"

void Filters::blur(Mat &image)
{
  cout << "Aplicando filtro blur..." << endl;
  cv::blur(image, image, Size(15, 15));
}

void Filters::gaussianBlur(Mat &image)
{
  cout << "Aplicando filtro GaussianBlur..." << endl;
  cv::GaussianBlur(image, image, Size(15, 15), 0);
}
void Filters::medianBlur(Mat &image)
{
  cout << "Aplicando filtro medianBlur..." << endl;
  cv::medianBlur(image, image, 15);
}