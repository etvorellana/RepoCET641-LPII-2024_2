//Q1
unsigned char gerarGreyPixel (int tipo){
    int valor;
    int proba= rand() % 100; //gera um número entre 0 e 100;
    if(tipo<0){
       if(proba < 80){      //80% de gerar um número entre 0 e 127.
            valor= rand() % 128;
       }else{               //20% de gerar um número de qualquer intensidade.
            valor= rand() % 256;
        }
    }else if(tipo>0){
        if(proba < 80){     //80% de gerar um número entre 128 e 255.
            valor = 128 + rand() % 128;
        }else{
            valor = rand() % 256; //20% de gerar um número de qualquer intensidade.
        }
    }else{
        valor = rand() % 256; //gera um número entre 0 e 255.
    }
return (unsigned char) valor;
}
//Q2
void geraImgGreyFull ( unsigned char img [640][480], unsigned char pixel){
    int i,j;
    for(i=0;i<640;i++){
        for(j=0;j<480;j++){
            img[i][j]= pixel;
        }
    }
}
//Q3
void geraImgGreyB(unsigned char img[640][480]){
    int i, j;

    for(i = 0; i < 640; i++){
        for(j = 0; j < 480; j++){
            img[i][j] = 0;
        }
    }
}

//Q4
void geraImgGreyW(unsigned char img[640][480]){
    for(int i = 0; i < 640; i++){
        for(int j = 0; j < 480; j++){
          img[i][j] = 255;
        }
    }
}
//Q6
void drwRect(unsigned char img[640][480], int x, int y, int larg, int alt, unsigned char pixel){
    for(int i = y; i < y+alt; i++){
        for(int j = x; j < x+larg; j++) img[i][j] = pixel;
    }
}
//Q7
void drwCirc(unsigned char img[640][480], int x, int y, int rad, unsigned char pixel){
    int m, i, j, n;
    for(i = 0; i < 640; i++){
        n = (i - x)*(i - x);
        for(j = 0; j < 480; j++){
            m = sqrt(n + (j - y)*(j - y));
            if(m <= rad){
                img[j][i] = pixel;
            }
        }
    }
}
//Q9
int pixelMax(unsigned char img[640][480]) {
    int max = 0; // Inicializa o valor máximo com 0
    // Percorre todos os pixels da imagem
    for (int i = 0; i < 480; i++) {
        for (int j = 0; j < 640; j++) {
            if (img[i][j] > max) {
                max = img[i][j]; // Atualiza o valor máximo se encontrar um pixel com intensidade maior
            }
        }
    }

    return max;
}
//Q10
int pixelMin(unsigned char img[640][480]) {
    int min = 255; // Inicializa o valor mínimo com o maior valor possível para um unsigned char
    // Percorre todos os pixels da imagem
    for (int i = 0; i < 640; i++) {
        for (int j = 0; j < 480; j++) {
            if (img[i][j] < min) {
                min = img[i][j]; // Atualiza o valor mínimo se encontrar um pixel com intensidade menor
            }
        }
    }
    return min;
}
//Q11
void media_desvio (unsigned char img [640][480], double *desviop, double *media) {
    double soma=0, diferenca=0;
    //Soma de todos as intensidades dos pixels
    for (i = 0; i<640; i++) {
        for (j = 0; j<480; j++) {
            soma += img [i][j];
        }
    }
    *media = soma/(640*480);

    //Desvio padrão = raiz de {[(img [i][j] - media)²]/total]}
    for (i = 0; i<640; i++) {
        for (j = 0; j<480; j++) {
            diferenca +=  (img [i][j] - *media)*(img [i][j] - *media);
        }
    }
    *desviop = sqrt (diferenca/(640*480));
}
//Q12
void imgHistogram(unsigned char img[640][480], int hist[256]){
    int i,j;
    for(i=0;i<640;i++){
        for(j=0;j<480;j++){
            hist[img[i][j]]++;
        }
    }
}
