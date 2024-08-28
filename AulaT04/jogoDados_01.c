#include <stdio.h>
#include <stdlib.h>
void func1();
int x = 5;

int main(void){
    printf("Valor de x: %d\n", x);
    float x = 3.0;
    printf("Valor de x: %f\n", x);
    func1();
    return 0;
}

void func1(){
    printf("Valor de x: %d\n", x);
}