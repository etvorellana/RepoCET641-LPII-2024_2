#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "Interface.hpp"

using namespace std;
using namespace cv;

// Input: ./TRABALHO <inputFile> <outputFile> [...filters] [...flags]
// Filters: { -blur, -gaussianBlur, -medianBlur }
// Flags: { --preview, ...}

// Example: ./TRABALHO test.png output.png -blur -gaussianBlur --previews

int main(int argc, char *argv[])
{
  try
  {
    Mat image;
    string inputFile;
    string outputFile;
    vector<string> filters;
    vector<string> flags;

    if (argc <= 1 || !argv[2] || !argv[1])
      cerr
          << "Erro na chamada, deve ser de acordo:\n"
          << argv[0] << " <inputFile> <outputFile> [...filters] [...flags]\n"
          << "-help para ajuda" << endl;

    inputFile = argv[1];
    outputFile = argv[2];

    for (int i = 3; i < argc; i++)
    {
      string arg = argv[i];
      if (arg.rfind("--") == 0)
      {
        flags.push_back(arg);
      }
      else if (arg.rfind("-") == 0)
      {
        filters.push_back(arg);
      }
    }

    Interface app(inputFile, outputFile, filters, flags);
    app.handleFilters();
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }

  return 0;
}