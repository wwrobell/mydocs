#include <iostream>

using namespace std;

template <typename T>
class Complex{
    T re, im;
public:
    Complex(T re, T im): re(re), im(im) { }

    template<typename U>
    friend std::ostream& operator<< (std::ostream& os, Complex<U> z); //deklaracja
};

template<typename T>
std::ostream& operator<< (std::ostream& os, Complex<T> z){
    return os<<z.re<<" + i" <<z.im;
}

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    return 0;
}
