#include "Filters.hpp"

void Filters::validate(Mat &image)
{
  if (image.empty())
  {
    throw runtime_error("Imagem inválida");
  }
}

void Filters::blur(Mat &image)
{
  validate(image);
  cout << "Aplicando filtro blur..." << endl;
  cv::blur(image, image, Size(15, 15));
}

void Filters::gaussianBlur(Mat &image)
{
  validate(image);
  cout << "Aplicando filtro GaussianBlur..." << endl;
  cv::GaussianBlur(image, image, Size(15, 15), 0);
}
void Filters::medianBlur(Mat &image)
{
  validate(image);
  cout << "Aplicando filtro medianBlur..." << endl;
  cv::medianBlur(image, image, 15);
}