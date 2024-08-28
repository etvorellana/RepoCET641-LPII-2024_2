#include <stdio.h>

int func1(int a)
{
    if (a < 100)
        a = 100 + func2(a);
    return a + 1
}

int func2(int a)
{
    if (a < 100)
        a = 100 + func1(a);
    return a + 2;
}

int main(void)
{
    int a = 10;
    printf("O valor de a é %d\n", func1(a));
    return 0;
}