    #include <stdlib.h>

    unsigned char geraGreyPixel(int tipo){
        int i = rand() % 100 + 1;
        if(tipo < 0){
            if(i <= 75){
                return rand() % 128;
            }
            else{
                return 128 + rand() % (255 - 128 + 1);
            }
        }
        if(tipo > 0){
            if(i<=75){
                return 128 + rand() % (255 - 128 + 1);
            }
            else{
                return rand() % 128;
            }
        }
        if(tipo == 0){
            return rand() % 255 + 1;
        }
    }

    void geraImgGreyFull(unsigned char img[640][480], unsigned char pixel){
        int i, j;
        for(i = 0; i < 640; i++){
            for(j = 0; j < 480; j++){
                img[i][j] = pixel;
            }
        }
    }

    void geraImgGreyB(unsigned char img[640][480]){
        int i, j;
        for(i = 0; i < 640; i++){
            for(j = 0; j < 480; j++){
                img[i][j] = 0;
            }
        }
    }

    void geraImgGreyW(unsigned char img[640][480]){
        int i, j;
        for(i = 0; i < 640; i++){
            for(j = 0; j < 480; j++){
                img[i][j] = 255;
            }
        }
    }

    void drwLin(unsigned char img[640][480], int xA, int yA, int xB, int yB, unsigned char pixel){}

    void drwRect(unsigned char img[640][480], int x, int y, int larg, int alt, unsigned char pixel){}

    void drwCirc(unsigned char img[640][480], int x, int y, int rad, unsigned char pixel){}

    void drwTriang(unsigned char img[640][480], int xA, int yA, int xB, int yB, int xC, int yC, unsigned char pixel){}

    int pixelMax(unsigned char img[640][480]){
        
        int maior = -1;

        for(int i = 0; i < 640; i++){
            for(int j = 0; j < 480; j++){
                if(img[i][j] > maior)
                    maior = img[i][j];
            }
        }

        return maior;
    }

    int pixelMin(unsigned char img[640][480]){
        
        int menor = 256;

        for(int i = 0; i < 640; i++){
            for(int j = 0; j < 480; j++){
                if(img[i][j] < menor)
                    menor = img[i][j];
            }
        }

        return menor;
    }

    void imgHistogram(unsigned char img[640][480], int hist[256]){
        for(int i = 0; i < 640; i++){
            for(int j = 0; j < 480; j++){
                hist[(img[i][j])] += 1;
            }
        }
    }

    void imgRandom(unsigned char img[640][480]){
        for(int i = 0; i < 640; i++){
            for(int j = 0; j < 480; j++){
                img[i][j] = rand()%256;
            }
        }
    }