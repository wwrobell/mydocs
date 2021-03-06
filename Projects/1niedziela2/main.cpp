#include <iostream>

using namespace std;

void printIntsFromRawMem(const char *pCh, int size){
    for (int i = 0; i<size; ++i)
        cout << int (*(pCh + i));
}

void castDemo1()
{
    long lN = 578437695752307201; //0b 1000 00000111 00000110 00000101 00000100 00000011 00000010 00000001
    cout << "sizeof(long) = " << sizeof(long) << endl;
    cout << lN << " as a byte stream = ";
    printIntsFromRawMem((char *) &lN, sizeof(lN));
    cout << endl;
}

struct IEEE754
{
    unsigned int mantissa: 23,
                 exponent: 8,
                 sign : 1;
};

void castDemo2()
{
    int ia1[2] = {84281096, 16909060};
    cout << "int ia1[2] = {84281096, 16909060} as a byte stream = ";
    printIntsFromRawMem((char *) ia1, 8);

    int ia2[2] = {67305985, 134678021};
    cout << "int ia2[2] = {67305985, 134678021} as a byte stream = ";
    printIntsFromRawMem((char *) ia2, 8);
    cout << endl;
}

void castDemo3()
{
    float dN = 1.5399896E-36;
    cout << dN << " as a byte stream = ";
    printIntsFromRawMem((char *) &dN, 4);
    cout << endl;
}

void castDemo4()
{
    float dN = 1.5399896E-36;

    cout << "sizeof(struct IEEE754) = " << sizeof(struct IEEE754) << endl;
    cout << dN << " decomposed with the use of bitfields: ";

    struct IEEE754 *pI3E754 = (struct IEEE754 *) &dN;
    cout << "sign = " << pI3E754->sign
         << ", exponent = " << pI3E754->exponent
         << ", mantissa = " << pI3E754->mantissa << endl;
}

void castDemo5()
{
    float dN = 1.5399896E-36;

    struct IEEE754 *pI3E754 = (struct IEEE754 *) &dN;
    const unsigned int floatAsUInt = *(unsigned int *) pI3E754;

    const unsigned int signMask = 0x1;
    unsigned int sign = (floatAsUInt >> 31) & signMask;

    const unsigned int exponentMask = 0xFF;
    unsigned int exponent = (floatAsUInt  >> 23) & exponentMask;

    const unsigned int mantissaMask = 0x7FFFFF;
    unsigned int mantissa = floatAsUInt & mantissaMask;

    cout << dN << " decomposed with the use of bitmasks: ";
    cout << "sign = " << sign
         << ", exponent = " << exponent
         << ", mantissa = " << mantissa << endl;
}

void f2()
{
#define TBL_SIZE 2
    long i = 0;
    long lArr[TBL_SIZE] = {7, 15};
    for (i = 0; i <= TBL_SIZE; ++i) {
        // na MACu petla nieskonczona -> war (i <= TBL_SIZE) zawsze spelniony
        //cout << *(&lArr[TBL_SIZE - 1] - i) << endl;
        cout << "i przed zerowaniem: " << i;
        *(&lArr[TBL_SIZE - 1] - i) = 0; //&lArr[1] - 2 //wyjscie poza zakres tablicy -> wyzerowanie zmiennej long i
        cout <<  " ;po zerowaniu: " << i << endl;
    }
}

int main()
{
    //f2(); //dlaczego u nas dziala a na MACu petla nieskonczona
    int a1[] = {1,2,3,4,5};
    short * p1 = (short*) a1;
    cout << *(p1+2); //1;0;2
//    castDemo1();
//    castDemo2();
//    castDemo3();
//    castDemo4();
//    castDemo5();
    return 0;
}
