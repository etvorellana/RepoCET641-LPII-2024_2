#include "Interface.hpp"
#include "Filters.hpp"

Interface::Interface(string inputImagePath, string outputImagePath, vector<string> pFilters, vector<string> pFlags)
{
  inputPath = inputImagePath;
  outputPath = outputImagePath;
  filters = pFilters;
  flags = pFlags;

  config();
}

void Interface::config()
{
  image = imread(inputPath, IMREAD_COLOR);
  validate();
}

void Interface::validate()
{
  if (image.empty())
  {
    throw runtime_error("Caminho da imagem de entrada é inválido: " + inputPath);
  }
}

void Interface::saveImage()
{
  if (imwrite(outputPath, image))
  {
    cout << "Imagem salva com sucesso em: " << outputPath << endl;
  }
  else
  {
    cerr << "Erro ao salvar a imagem!" << endl;
  }
}

void Interface::previewImage()
{
  imshow("Preview", image);
  cout << "Pressione qualquer tecla para continuar..." << endl;
  waitKey(0);
  destroyAllWindows();
}

void Interface::handleFilters()
{
  Filters appFilters;

  for (const string &filter : filters)
  {
    if (filter == "-blur")
    {
      appFilters.blur(image);
    }
    else if (filter == "-medianBlur")
    {
      appFilters.medianBlur(image);
    }
    else if (filter == "-gaussianBlur")
    {
      appFilters.gaussianBlur(image);
    }
    else
    {
      cerr << "Filtro desconhecido: " << filter << endl;
      exit(0);
    }
  }

  if (find(flags.begin(), flags.end(), "--preview") != flags.end())
  {
    previewImage();
  }

  saveImage();
}
