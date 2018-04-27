#include <iostream>

using namespace std;

// napisac funkcje
// int x=1,y=2;
// swap2ints(x,y)
// cout<<"x= "<<x...
// wersja z referencjami lub wskaznikami

void swap2ints_ref(int &x,int &y){
    int y_temp = y;
    y = x;
    x = y_temp;
}

void swap2ints_ptr(int *xp,int *yp){
    int y_temp = *yp;
    *yp = *xp;
    *xp = y_temp;
}

int main()
{
    int x=1,y=2;
    cout << "Before swap: x = "<< x << " y = "<< y << endl;
    //swap2ints_ref(x, y);
    swap2ints_ptr(&x, &y);
    cout << "After swap: x = "<< x << " y = "<< y << endl;
    return 0;
}
