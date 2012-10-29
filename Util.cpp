#include "Util.h"
double frand(double min, double max){
    double rnd =(rand()/(double)RAND_MAX);
    rnd *= (max-min);
    return rnd+min;
}
void seed(long l){
    srand(l);
}
