//Q1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "procimg.h"

int main(){
    srand(time(NULL)); //Inicializa o gerador de números aleatórios.

    printf("Pixel de cor mais escura: %d\n",gerarGreyPixel(-1));       //Imprime as intensidades de cor mais escura
    printf("Pixel de cor mais clara: %d\n",gerarGreyPixel(1));         //Imprime as intensidades de cor mais clara
    printf("Pixel de intensidade qualquer: %d\n",gerarGreyPixel(0));   //Imprime qualquer intensidade
return 0;
}
//Q2
#include <stdio.h>
#include "procimg.h"
int main(){
    unsigned char img[640][480],pixel;
    int i,j;

    printf("Digite o valor que vai preencher os pixels: ");
    scanf("%d",&pixel);
    geraImgGreyFull(img,pixel);
    for(i=0;i<640;i++){
        for(j=0;j<480;j++){
            printf("%3d",img[i][j]);
        }printf("\n");
    }
return 0;
}
//Q3
#include <stdio.h>
#include "procimg.h"
int main(){
 unsigned char img[640][480];

 geraImgGreyB(img);
    
 for( i = 0; i < 640; i++){
     for( j = 0; j < 480; j++){
         printf("%u ", img[i][j]);
        }
     printf("\n");
    }
    return 0;
}
//Q4
#include <stdio.h>
#include "procimg.h"
int main(){
 unsigned char img[640][480];

 geraImgGreyW(img);
    
 for( i = 0; i < 640; i++){
   printf("\n");
     for( j = 0; j < 480; j++){
         printf("%c", img[i][j]);
         }
    }
    return 0;
}
//Q6
#include <stdio.h>
#include "procimg.h"
int main(){
    int i, j;
    unsigned char img[640][480], pixel = 255;

    for( i = 0; i < 640; i++){
        for( j = 0; j < 480; j++){
            img[i][j] = 70;
        }
    }
    drwRect(img, 2,2,400,400,pixel);

    for( i = 0; i < 640; i++){
        printf("\n");
        for( j = 0; j < 480; j++){
            printf("%c", img[i][j]);
        }
    }
    return 0;
}
//7
#include <stdio.h>
#include <math.h>
#include "procimg.h"
int main(){
    unsigned char img[640][480], pixel = 178;
    int i, j;
  
    for( i = 0; i < 640; i++){
        for( j = 0; j < 480; j++){
            img[i][j] = 176;
        }
    }
    drwCirc(img,50, 50, 28, pixel);

    for( i = 0; i < 640; i++){
        printf("\n");
        for( j = 0; j < 480; j++){
            printf("%c", img[i][j]);
        }
    }
    return 0;
}
//Q9
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "procimg.h"
int main() {
    int i, j;
    unsigned char img[640][480];
    
    srand(time(NULL));
    
    for(i = 0; i < 640; i++){
        for(j = 0; j < 480; j++) img[i][j] = rand()%255;
    }
    printf("Valor maximo: ", pixelMax(img);

    return 0;
}
//Q10
#include <stdlib.h>
#include <stdio.h>
#include "procimg.h"

int main() {
     int i, j;
    unsigned char img[640][480];
    
    srand(time(NULL));
    
    for(i = 0; i < 640; i++){
        for(j = 0; j < 480; j++) img[i][j] = rand()%255;
    }
    pixelMin(img);
    
    for(i = 0; i < 640; i++){
        printf("\n");
        for(j = 0; j < 480; j++) printf("%c", img[i][j]);
    }
    return 0;
}
//Q11
#include <stdio.h>
#include <math.h>

int i, j;
int main () {
    unsigned char img [640][480];
    double media=0, desviop=0;
    printf ("Digite as intensidades de cada pixel (0-255)\n");
    //Leitura das intensidades dos pixels da imagem
    for (i = 0; i<640; i++) {
        for (j = 0; j<480; j++) {
            printf ("[%d][%d]: ", i, j);
            scanf ("%hhu", &img [i][j]);
        }
    }
    media_desvio (img, &desviop, &media);
    printf ("\nMedia: %.2lf\nDesvio padrao: %.2lf\n", media, desviop);
}

//Q12
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "procimg.h"

int main(){
    unsigned char img[640][480];
    int i,j;
    int hist[256];
    srand(time(NULL));

    for(i=0;i<640;i++){
        for(j=0;j<480;j++){
            img[i][j]= rand() % 256;
        }
    }

    imgHistogram(img, hist);
    for(i=0;i<256;i++){
        printf("Intensidade %d: %d pixels\n",i,hist[i]);
    }
return 0;
}
