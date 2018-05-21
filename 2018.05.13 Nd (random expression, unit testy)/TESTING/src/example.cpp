#include "example.hpp"
#include <math.h>

int five() {
    return 5;
}



Solution roots(double a, double b, double c) {
    Solution s;

    if (a == 0 && b == 0 && c==0){
        s.identity = true;
        return s;
    }

    double delta = b*b - 4*a*c;
    if (delta>0){
        s.count = 2;
        s.identity = false;
        s.x1 = (-b + sqrt(delta))/2*a;
        s.x2 = (-b - sqrt(delta))/2*a;
    }
    else if(delta == 0){
        s.count = 1;
        s.identity = false;
        s.x1 = -b/2*a;
        s.x2 = -b/2*a;
    }
    else{}
    return s;
}
