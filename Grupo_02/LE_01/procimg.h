#ifndef PROCIMG_H
#define PROCIMG_H

#define largura 640
#define altura 480

//1 a 4
unsigned char geraPixelCinza(int tipo);
void preencheImgCinza(unsigned char img[640][480], unsigned char pixel);
void preencheImgPreto(unsigned char img[640][480]);
void preencheImgBranco(unsigned char img[640][480]);

// 5 e 6
void drwLin(unsigned char img[largura][altura], int xA, int yA, int xB, int yB, unsigned char pixel);
void drwRect(unsigned char img[largura][altura], int x, int y, int larg, int alt, unsigned char pixel);

// 7
void drwCirc(unsigned char img[altura][largura], int x, int y, int rad, unsigned char pixel);

//9 e 10
int pixelMax(unsigned char img[640][480]);
int pixelMin(unsigned char img[640][480]);

//11 e 12
void calculardadosimagem(unsigned char img[largura][altura], double *media, double *desvioPadrao);
void imgHistogram(unsigned char img[largura][altura], int hist[256]);

#endif
