#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
  string path = "test.png";
  string output = "blur.png";

  Mat image = imread(path, IMREAD_COLOR);
  if (image.empty())
    cerr << "Erro ao abri imagem" << endl;

  // GaussianBlur(image, image, Size(10, 10), 0);
  medianBlur(image, image, 15);
  blur(image, image, Size(15, 15), Point(5, 5));
  imwrite(output, image);

  return 0;
}