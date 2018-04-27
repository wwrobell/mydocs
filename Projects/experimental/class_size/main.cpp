#include <iostream>

using namespace std;

class Prostokat{
    int dlugosc;
    int szerokosc;
public:
    Prostokat(){dlugosc = 4; szerokosc = 2;}

    void zwieksz_dlugosc(){
        dlugosc = dlugosc + 2;
    }

    void print_size(){
        cout << dlugosc << " x " << szerokosc << endl;
    }

};

int main()
{
    Prostokat prostokat_A = Prostokat();
    cout << "Size of Prostokat: " << sizeof(Prostokat) <<endl;
    cout << "Size of prostokat_A: " << sizeof(prostokat_A) <<endl;
    prostokat_A.print_size();
    prostokat_A.zwieksz_dlugosc();
    prostokat_A.print_size();

    //wsk do referencji? referencja do wskaznika?
    int i = 2;
    int ii = 22;
    int * ptr = &i; //wsk do referencji
    int * ptr2 = &ii;

    int ** ptr_ref = &ptr; //referencja do wsk

    return 0;
}
