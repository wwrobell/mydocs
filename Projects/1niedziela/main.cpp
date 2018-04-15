#include <iostream>

using namespace std;

float f(){
    float x = 0;
    float dx = 0.1;
    while (x <= 1.0){ //x != 1.0  petla nieskonczona [0.1 nie jest prawdziwym 0.1 w float , jak 1/3 = 0.3333.. w dziesietnym]
        x+=dx;
        cout<<"x = "<<x<<endl;
    }
    return x;
}

int f1(double x){
    return x;
}
int main()
{
    //cout << "f() = " << f() << endl;
    cout << sizeof(double); //size of to operator, nie funkcja --> dziala na etapie kompilacji

    float y = 0.5;
    const float* p1 = &y;

    const float z = 5.3;
    const float * p3 = &z;
    float * const p5 = &y;

    int tablica [] = {1,2,3,4,5};
    int * pA[4]; //tablica wskaznikow
   // int (*p)[] = tablica; //wskaznik do tablicy
   // int ** p10 = tablica;

    //wskaznik do funkcji
    int (*p11) (double);
    p11 = f1;

    //float * p7 = &z; //invalid conversion
    return 0;
}
