#include <iostream>
#include <cstring>


class MyString {
    char* buf;
public:
    MyString(const char* str): buf{new char[strlen(str) + 1]} {
        std::strcpy(buf, str);
    }

    //MyString(const MyString& other): buf{new char[strlen(other) + 1]} {
    //    std::strcpy(buf, other);
    //}

    MyString(const MyString& other): MyString{other.buf} {}

    ////Nie dziala dobrze (utrata zasobow):
    //MyString& operator = (const MyString& other){
    //    buf = other.buf;
    //    return *this;
    //}

    ////Poprawne:
    //MyString& operator = (const MyString& other){
    //    //delete[] buf;
    //    char* temp = new char[strlen(other.buf) + 1];
    //    std::strcpy(temp, other.buf);
    //    delete[] buf;
    //    buf = temp;
    //    return *this;
    //}

    ////Lepiej: Uniwersalne "Copy-and-swap"
    //MyString& operator = (const MyString& other){
    //    MyString tmp{other};
    //    std::swap(buf, tmp.buf);
    //    return *this;
    //}

    //Jeszcze Lepiej?
    MyString& operator = (MyString other){
        std::swap(buf, other.buf);
        return *this;
    }

    ~MyString() {
        if (buf){
            std::cout<<buf;
            delete[] buf;
            buf = nullptr;
        }
    }
};

//Przykladowy szablon dla klasy wektora (sprobowac przerobic nasze struktury na szablony)
template <typename T>
class Vector{
    T* buf;
public:
    Vector(int n): buf{new T[n]} { }
    ~Vector() {delete [] buf;}

    T& operator [](int a) {return buf[a];}
    //w funkcji (Vector&, int)
    const T& operator [] (int a) const {return buf[a]; }
    //w funkcji (const Vector&, int)

    template <typename U>
    Vector(const Vector<U>& v){
        //alokacja
        for (int i=0;i<v.size();++i){
            buf[i]=v[i];
        }
    }
};
//

int main() {
    MyString a{"Ala"};
    MyString b{a};
    MyString c{"Kot"};
    c = a;
    return 0;
}
