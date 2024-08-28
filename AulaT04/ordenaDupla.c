#include <stdio.h>
int *pa, *pb;

int ordena1(int a, int b){
    if(a > b){
        int temp = a;
        a = b;
        b = temp;
        return 1;
    }
    return 0;
}   

void ordena2(int a, int b){
    if(a > b){
        int temp = a;
        a = b;
        b = temp;
    }
}
 

int ordena3(int *a, int *b){
    if(*a > *b){
        int temp = *a;
        *a = *b;
        *b = temp;
        return 1;
    }
    return 0;
}



int ordena4(int *a, int *b){
    if(*a > *b){
        int *temp = a;
        a = b;
        b = temp;
        return 1;
    }
    return 0;
}

int ordena5(){
    if(*pa > *pb){
        int *temp = pa;
        pa = pb;
        pb = temp;
        return 1;
    }
    return 0;
}

int main(void){
    int a = 5, b = 3;
    int c, d;
    pa = &c;
    pb = &d;
    printf("Antes: %d, %d\n", a, b);
    *pa = a;
    *pb = b;
    ordena5();
    a = *pa;
    b = *pb;
    printf("Depois: %d, %d\n", a, b);
    return 0;
}