#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define linha 420
#define coluna 20
#define N 640
//Q1
unsigned char geraGreyPixel (int tipo) {
    unsigned char num;
    int probabilidade = rand() % 100;
    if(tipo < 0){
       if (probabilidade < 80)      //80% de chance de cor escura
            num = rand() % 128;
       else                        //20% de chance de todas as cores
            num = rand() % 256;
    }
    else if (tipo > 0) {
        if (probabilidade < 80)             //80% de chance de cor clara
            num = 128 + rand() % 128;       
        else                            //20% de chance de todas as cores
            num = rand() % 256;
    }
    else
        num = rand() % 256;          //100% de chance de todas as cores
    return num;
}

int indice = N-1;

void geraLinhaR(unsigned char array [], int tipo) {
    if (indice < 0) return;                   // para quando o array está totalmente preenchido
    array [indice] = geraGreyPixel (tipo);   //preenche o array de N-1 até 0;
    indice--;
    geraLinhaR (array, tipo);
}
//Q2
int num2 = linha * coluna;

void geraImgGreyFull_R(unsigned char img[linha][coluna], unsigned char pixel){
    if(num2 == 0){                     //testa se num2 chegou a 0
        num2 = linha * coluna;          //reseta num2 para que a função possa ser chamada novamente
        return;                      //encerra a função
    }
    num2--;                            //decrementa num2 para controlar a quantidade de vezes que a função foi chamada
    img[0][0] = pixel;              //atribui o valor 0 ao pixel atual
    geraImgGreyFull_R(&img[0][1], pixel);     //chama a função novamente, passando o endereço do próximo pixel
}
//Q3
int num3 = linha*coluna;
void geraImgGreyB_R(unsigned char img[linha][coluna]){
      if(num3 == 0){           //testa se num3 chegou a 0
        num3 = linha * coluna;     //reseta num3 para que a função possa ser chamada novamente
        return;             //encerra a função
    }
    num3--;                    //decrementa num3 para controlar a quantidade de vezes que a função foi chamada
    img[0][0] = 0;          //atribui o valor 0 ao pixel atual
    geraImgGreyB_R(&img[0][1]);     //chama a função novamente, passando o endereço do próximo pixel
}

//Q4
void preencherimg(unsigned char img[480][640],int pixel,int i,int j){
    if(i>=480 || j>=640) return; //condição de parada

    img[i][j]=pixel; //preenche com o valor inserido
    preencherimg(img,pixel,i,j+1); //preenche até o valor máximo de j
    if(j==0)   preencherimg(img,pixel,i+1,0); //quando j chega no limite, vai para próxima linha
}
void geraImgGreyW_R(unsigned char img[480][640]){
    preencherimg(img,255,0,0);
}
//Q5
void geraImgGrey_R(unsigned char img[480][640],int tipo){
    unsigned char k= geraGreyPixel(tipo);
    preencherimg(img,k,0,0);
}
//Q6
int aux_pixelMax_R(unsigned char img[linha][coluna], int row, int col, int maxValue){
        if (row > linha - 1) // 480
        {
            return maxValue;
        }
        /*
            IF para verificar a condição de saída da recursividade, nesse caso, o método de saída será quando row(linha) for igual a 480, pois a matriz vai de 0 a 479, se chegar em 480
            irá passar do tamanho da matriz.

            Quando o caso for positivo, então ele deve retornar o valor maxValue, que foi modificado ao decorrer do código para ter o maior valor da matriz.
        */
        if(col > coluna - 1) // 639
        {
            return aux_pixelMax_R(img, row + 1, 0, maxValue);
        }
        /*
            IF para verficar se a coluna(col) passou de 639, que é o valor máximo que uma coluna pode ter nessa matriz.
            
            Quando col == 640, ele irá chamar a função novamente chamando a matriz img, mas agora a row(linha) será adicionada +1, portanto a próxima linha. A col receberá o valor 0, para
            começar a repetição novamente, e o valor maxValue irá passar para a função a ser chamada.
        */
        else // ELSE para caso col seja menor que 639, ocorrerá na maioria das vezes
        {
            if(maxValue < img[row][col])
            {
                maxValue = img[row][col];
            }
            /* 
                IF para verificar se o valor da matriz img de posição [linha][coluna], row e col respectivamente, é maior que o maxValue atual.
                
                Caso o IF seja positivo maxValue recebe o valor img[row][col], portanto o maior valor atualmente.
            */
            
            return aux_pixelMax_R(img, row, col + 1, maxValue); // Chama a função auxiliar novamente, mas agora atualizando o valor da coluna, adicionando +1.
        }
    }

int pixelMax_R(unsigned char img[linha][coluna]){
    int max = aux_pixelMax_R(img, 0, 0, 0); // Inicializa a função auxliar, dentro da função principal, com os valores row(0), col(0), maxValue(0). Para que o laço de repetição seja feito da esquerda para a direita e que o maxValue seja o menor possível(0).
    return max; 
}
//Q7
int aux_pixelMin_R(unsigned char img[linha][coluna], int row, int col, int minValue)
{
    if (row > linha - 1) // 480
    {
        return minValue;
    }
    /*
        IF para verificar a condição de saída da recursividade, nesse caso, o método de saída será quando row(linha) for igual a 480, pois a matriz vai de 0 a 479, se chegar em 480
        irá passar do tamanho da matriz.

        Quando o caso for positivo, então ele deve retornar o valor minValue, que foi modificado ao decorrer do código para ter o menor valor da matriz.
    */

    if(col > coluna - 1) // 639
    {
        return aux_pixelMin_R(img, row + 1, 0, minValue);
    }
    /*
        IF para verficar se a coluna(col) passou de 639, que é o valor máximo que uma coluna pode ter nessa matriz.

        Quando col == 640, ele irá chamar a função novamente chamando a matriz img, mas agora a row(linha) será adicionada +1, portanto a próxima linha. A col receberá o valor 0, para
        começar a repetição novamente, e o valor minValue irá passar para a próxima função a ser chamada.
    */
    else // ELSE para caso col seja menor que 639, ocorrerá na maioria das vezes
    {
        if(minValue > img[row][col])
        {
            minValue = img[row][col];
        }
        /* 
            IF para verificar se o valor da matriz img de posição [linha][coluna], row e col respectivamente, é menor que o minValue atual.
                
            Caso o IF seja positivo minValue recebe o valor img[row][col], portanto o menor valor atualmente.
        */
        return aux_pixelMin_R(img, row, col + 1, minValue); // Chama a função auxiliar novamente, mas agora atualizando o valor da coluna, adicionando +1.
    }
}
int pixelMin_R(unsigned char img[linha][coluna])//Entrada da matriz
{
    int min = aux_pixelMin_R(img, 0, 0, 255);// Inicializa a função auxliar, dentro da função principal, com os valores row(0), col(0), minValue(0). Para que o laço de repetição seja feito da esquerda para a direita e que o minValue seja o maior possível(255).
    return min;
}

//Q8
int flag8 = -1; //usei flag = -1 para na primeira iteração flag ser igual a 0, pra ficar igual ao primeiro elemento dos arrays
void somaPorLinhas_R(unsigned char img[linha][coluna], int soma[linha]){
    flag8++;   //Essa flag conta as iterações, ajuda marcar coluna e linha, e marca o momento de mudança de posição do ponteiro soma.
    if(flag8 == linha * coluna){
        flag8 = -1; //reseta o flag para a função poder ser chamada de novo
        return;   //Quando todas as posições forem preenchidas, as iterações acabam
    }
    //(flag / linha): marca em qual linha está, só vai para a próxima linha quando soma todas os elementos da mesma linha
    //(flag % coluna): marca em qual coluna está, vai para a próximo elemento da linha até atingir o valor "coluna", quando alcança, volta a 0
    //A posição do ponteiro soma só deve mudar quando a linha mudar
    soma[flag8 / linha] += img[flag8 / linha][flag8 % coluna]; //Realiza a soma em cada posição do vetor soma
    somaPorLinhas_R(img, soma);  //Pula para a próxima iteração
}
//Q9
int flag9 = -1; //usei flag = -1 para na primeira iteração flag ser igual a 0, pra ficar igual ao primeiro elemento dos arrays
void somaPorColunas_R(unsigned char img[linha][coluna], int soma[]){
    flag9++;   //Essa flag conta as iterações, ajuda marcar coluna e linha, e marca o momento de mudança de posição do ponteiro soma.
    if(flag9 == linha * coluna){
        flag9 = -1; //reseta o flag para a função poder ser chamada de novo
        return;   //Quando todas as posições forem preenchidas, as iterações acabam
    }
    //(flag / coluna): marca em qual coluna está, só vai para a próxima coluna quando soma todas os elementos da mesma coluna
    //(flag % linha): marca em qual linha está, vai para o próximo elemento da coluna até atingir o valor "linha", quando alcança, volta a 0
    //A posição do ponteiro soma só deve mudar quando a coluna mudar
    soma[flag9 / coluna] += img[flag9 % linha][flag9 / coluna]; //Realiza a soma em cada posição do vetor soma
    somaPorColunas_R(img, soma);   //Pula para a próxima iteração
}
//Q10
int somaPorTotal_R(unsigned char img[linha][coluna]) {
    static int L = linha-1, C = coluna-1, soma = 0;

    // Se a L é menor que 0, significa que a soma de todos os elementos foi calculada
    if (L < 0) {
        return soma;
    }

    // Adiciona o valor do elemento atual à soma
    soma += img[L][C];

    // Move para a próxima coluna à esquerda
    C--;

    // Se a coluna é menor que 0, reseta a coluna para o último índice e move para a linha anterior
    if (C < 0) {
        C = coluna - 1;
        L--;
    }

    // Chama a função recursivamente para processar a próxima posição
    return somaPorTotal_R(img);
}
//Q11
int L = 0, C = 0;  // declaração de variáveis globais para manipular na função

int quantosPixelsNaInt_R (unsigned char img[linha][coluna], unsigned char inte) {
    int count = 0;
    if (L >= linha) return 0;          // verifica se todas as linhas estão preenchidas
    if (img [L][C]==inte)     // contador de frequência do inte na img
        count++;
    C++;
    if (C>=coluna) {        //se completar uma coluna, pula a linha e percorre as colunas dnv
        C = 0;
        L++;
    }
    // Retorna a soma da contagem de pixels encontrados no bloco atual e a contagem
    // dos pixels encontrados nas chamadas recursivas seguintes.
    return count + quantosPixelsNaInt_R (img, inte);
}
//Q12
int aux_quantosPixelsAbaixoDeInt_R(unsigned char img[linha][coluna], unsigned char Int, int row, int col, int soma){
        if(row > linha - 1) 
        {
            return soma;
        }
        /*
           IF para verificar a condição de saída da recursividade, nesse caso, o método de saída será quando row(linha) for igual a 480, pois a matriz vai de 0 a 479, se chegar em 480
           irá passar do tamanho da matriz.

           Quando o caso for positivo, então ele deve retornar o valor soma, que foi modificado ao decorrer do código para ter a soma da quantidade dos valores menores que Int da matriz.
        */

        if(col > coluna - 1) 
        {
            int abaixo = aux_quantosPixelsAbaixoDeInt_R(img, Int, row + 1, 0, soma);
            return abaixo;
        }
        /*
            IF para verficar se a coluna(col) passou de 639, que é o valor máximo que uma coluna pode ter nessa matriz.

            Quando col == 640, ele irá chamar a função novamente chamando a matriz img, mas agora a row(linha) será adicionada +1, portanto a próxima linha. A col receberá o valor 0, para
            começar a repetição novamente, e o valor soma e Int irá passar para a próxima função a ser chamada.
        */
        else // ELSE para caso col seja menor que 639, ocorrerá na maioria das vezes
        {
            if(img[row][col] < Int)
            {
                soma ++;
            }
            /* 
                IF para verificar se o valor da matriz img de posição [linha][coluna], row e col respectivamente, é menor que o valor base Int.
                
                Caso o IF seja positivo soma recebe o valor adicionado +1.
            */
            return aux_quantosPixelsAbaixoDeInt_R(img, Int, row, col + 1, soma); // Chama a função auxiliar novamente, mas agora atualizando o valor da coluna, adicionando +1.
        }
    }
    
int quantosPixelsAbaixoDeInt_R(unsigned char img[linha][coluna], unsigned char Int){
    return aux_quantosPixelsAbaixoDeInt_R(img, Int, 0, 0, 0);// Inicializa a função auxliar, dentro da função principal, com os valores row(0), col(0), soma(0). Para que o laço de repetição seja feito da esquerda para a direita.
}
//Q13
int quantosPixelsAcimaDeInt_R(unsigned char img[linha][coluna], unsigned char inteiro){
    return linha*coluna - quantosPixelsAbaixoDeInt_R(img, inteiro) - quantosPixelsNaInt_R(img, inteiro); 
}
//Q14
int flag14 = 0;
unsigned char pontoEquilibrio(unsigned char img[linha][coluna], unsigned char Int){
    flag14++;   //Contador para saber quando parar as iterações
    unsigned char reserva;  //valor reserva
    int a, b, media;
    a = pixelMax_R(img);
    b = pixelMin_R(img);
    media = (a + b)/2;  //recebe a media entre o maior e menor elemento da matriz

    reserva = img[0][0];
    if(reserva == media){
        Int = reserva;  //se reserva for igual à média, as iterações acabam e retorna Int com o mesmo valor de reserva
        return Int;
    }
    else if(abs(reserva - media) < abs(Int - media)){
        Int = reserva;  //se reserva for mais proximo da média que Int, Int será substituído pelo novo valor 
    }
    if(flag14 == linha * coluna){
        flag14 = 0;  //reseta para a função poder ser chamada de novo
        return Int;  //quando flag chega no limite de tamanho, as iterações acabam
    }
    pontoEquilibrio(*img+1, Int); //Retorna o próximo elemento da matriz
}