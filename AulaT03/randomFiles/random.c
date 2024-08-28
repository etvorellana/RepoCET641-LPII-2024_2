
#include <stdlib.h>

int geraInt(int min, int max)
{
    return min + rand() % (max - min + 1);
}

double geraRand()
{
    return (double)rand() / RAND_MAX;
}

double geraReal(double min, double max)
{
    return min + (max - min) * geraRand();
}
