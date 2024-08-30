// exemplo de uso de cada função
#include "procimg.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

  /*####### Implementar 1 ########*/

  // srand(time(NULL));
  // for (int i = 0; i < 10; i++)
  // {
  //   printf("%d\n", geraGreyPixel(1));
  // }

  /*####### Implementar 2 ########*/

  // unsigned char img[640][480];
  // unsigned char pixel = 128;

  // geraImgGreyFull(img, pixel);

  // for (int j = 0; j < 480; j++)
  // {
  //   for (int i = 0; i < 640; i++)
  //     printf(" %d |", img[i][j]);

  //   printf("\n");
  // }

  /*####### Implementar 3 e 4 ########*/

  /*####### Implementar 5 ########*/
  // unsigned char img[640][480] = {0};
  // unsigned char pixel = 255;

  // drwLin(img, 10, 10, 50, 50, pixel);

  // for (int j = 480; j > 0; j--)
  // {
  //   for (int i = 0; i < 640; i++)
  //     if (img[i][j] == 255)
  //       printf("#");
  //     else
  //       printf(" ");

  //   printf("\n");
  // }

  /*####### Implementar 6 ########*/
  // unsigned char img[640][480] = {0};

  // drwRect(img, 2, 2, 10, 10, 255);

  // for (int i = 480; i > 0; i--)
  // {
  //   for (int j = 0; j < 640; j++)
  //   {
  //     if (img[j][i] > 0)
  //       printf("#");
  //     else
  //       printf(" ");
  //   }
  //   printf("\n");
  // }
  /*####### Implementar 7 ########*/
  // unsigned char img[640][480] = {0};
  // for (int i = 0; i < 640; i++)
  // {
  //   for (int j = 0; j < 480; j++)
  //   {
  //     if (img[i][j])
  //     {
  //       printf("#");
  //     }
  //     else
  //     {
  //       printf(" ");
  //     }
  //   }
  // }
  /*####### Implementar 8 ########*/
  unsigned char img[640][480] = {0};
  unsigned char pixel = 255;

  drwTriang(img, 2, 2, 10, 20, 20, 5, pixel);

  for (int j = 480; j > 0; j--)
  {
    for (int i = 0; i < 640; i++)
      if (img[i][j] == 255)
        printf("#");
      else
        printf(" ");

    printf("\n");
  }
  /*####### Implementar 9 ########*/
  /*####### Implementar 10 ########*/
  /*####### Implementar 11 ########*/
  // unsigned char img[640][480];
  // float med, desv;
  // for (int i = 0; i < 640; i++)
  // {
  //   for (int j = 0; j < 480; j++)
  //   {
  //     img[i][j] = (unsigned char)((i * 255) / 639);
  //   }
  // }

  // pixelMedEDesv(img, &med, &desv);
  // printf("Media: %.2f\n", med);
  // printf("Desvio Padrao: %.2f\n", desv);

  /*####### Implementar 12 ########*/
  // unsigned char img[640][480];

  // for (int y = 0; y < 480; y++)
  // {
  //   for (int x = 0; x < 640; x++)
  //   {
  //     img[x][y] = (x + y) % 256;
  //   }
  // }

  // int hist[256];

  // imgHistogram(img, hist);

  // for (int i = 0; i < 256; i++)
  // {
  //   if (hist[i] > 0)
  //   {
  //     printf("Intensidade %d: %d pixels\n", i, hist[i]);
  //   }
  // }

  return 0;
}
