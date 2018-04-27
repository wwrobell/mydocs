#include <iostream>

using namespace std;

struct IEE{
    unsigned int mantissa : 23, cecha : 8, sign : 1; //od lewej: 23 bity na mantyse; kolejne 8 na exponente; kolejny (ostatni) znak
};

int main()
{
    float dN = 1.5399896E-36;

    // reprezentacja wg. standardu opisujacego reprezentacje liczb zmienno-przecinkowych using bitfields
    IEE * ptr = (IEE *) &dN;
    cout << "mantisa: "<< ptr->mantissa << endl;
    cout << "wykladnik: "<< ptr->cecha << endl;
    cout << "znak: "<< ptr->sign << endl;


    // using bitmasks
    unsigned int FloatAsUint = *(unsigned int *) &dN;
    unsigned int sign_mask = 0x1;
    cout << "sign: " << ((FloatAsUint >> 31) & sign_mask) << endl;

    unsigned int exponent_mask = 0xFF;
    cout << "exponent: " << ((FloatAsUint >> 23) & exponent_mask) << endl;

    unsigned int mantissa_mask = 0x7FFFFF;
    cout << "mantissa: " << (FloatAsUint & mantissa_mask) << endl;

    cout << "liczba: " << dN;
}
