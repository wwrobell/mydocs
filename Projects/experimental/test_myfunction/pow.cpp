#include "pow.h"

int pow2(int power){
    if (power == 0)
        return 1;

    int output = 2;
    while((power - 1) != 0){
        output = output * 2;
        --power;
    }
    return output;
}
