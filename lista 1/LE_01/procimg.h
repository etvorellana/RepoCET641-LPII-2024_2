#ifndef _MODULE_H
#define _MODULE_H

unsigned char geraGreyPixel(int type);
void geraImgGreyFull(unsigned char img[640][480], unsigned char pixel);
void geraImgGreyB(unsigned char img[640][480]);
void geraImgGreyW(unsigned char img[640][480]);
void drwLin(unsigned char img[640][480], int xA, int yA, int xB, int yB, unsigned char pixel);
void imgHistogram(unsigned char img[640][480], int hist[255]);
int pixelMin(unsigned char img[640][480]);
int pixelMax(unsigned char img[640][480]);
void pixelMedEDesv(unsigned char img[640][480], float *med, float *desv);
void drwRect(unsigned char img[640][480], int xA, int yA, int xB, int yB, unsigned char pixel);
void drwCirc(unsigned char img[640][480], int x, int y, int rad, unsigned char pixel);
void drwTriang(unsigned char img[640][480], int xA, int yA, int xB, int yB, int xC, int yC, unsigned char pixel);
#endif