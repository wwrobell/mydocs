#include <iostream>
#include <chrono>

using namespace std;

// Rozmiar klas

class C1{
    int x;
    long y;     //sizeof C = 24
    int z;
    //long y;   //sizeof C = 16 optymalizacja pod wzgledem pamieci; zalezy od kompilatora
};

class C2{       //sizeof C2 = 1 (najmniejsza jednostka, aby wskaznik mogl zawierac adres)

};

class C3{
char c;
};

// Rekursja posrednia

// void f(){
//     g();
// }

// void g(){
//     f();
// }

// Rekursja koncowa
int h1(int a){
    int x = 1;
    return h1(x + a);
}

// Przykladowe Rekursje
int ackermann(int m, int n){
    if (m==0)
        return n + 1;                               //base case
    else if ((m>0) && (n==0))
        return ackermann((m-1),1);                  //
    else if ((m>0) && (n>0))
        return ackermann((m-1),ackermann(m,n-1));
    else
        return 0;
}

long unsigned int fact(long unsigned int n){
    if (n==0){
    return 1;
    }
    else{
    return n*fact(n-1);
    }
}

long fib(long n){
    if (n<=1)
        return n;
    else
        return (fib(n-1)+fib(n-2));
}

// Rzutowanie
// static_cast<T1>(...)
// const_cast<T2> (...)         sciaganie z consta
// dynamic_cast<T3> (...)       dziala w trakcie pracy programu
// reinterpret_cast<T4> (...)   najwieksza swoboda ~ (T4) (..)

int main(int argc, char *argv[])
{
    unsigned long i = 0xFFFFFFFFFFFFFFFF;
    double x = i;

    using ns = chrono::nanoseconds;
    using get_time = chrono::steady_clock;

    auto start = get_time::now();
    long wynik = fib(5);

    auto end = get_time::now();
    auto diff = end - start;
    cout << "Elapsed time is : " << chrono::duration_cast<ns>(diff).count() << " ns " << endl;

    return 0;
}
