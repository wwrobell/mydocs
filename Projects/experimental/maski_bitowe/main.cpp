#include <iostream>

using namespace std;

//example: return_n_bit(0b0010, 2) = 1

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

int return_n_bit(int bitstring, int n = 1){
    int mask = pow2(n - 1);
    if ((bitstring & mask) == 0)
        return 0;
    else
        return 1;
}

int main()
{
    int n_bit = return_n_bit(0b1111010, 3);
    cout<<n_bit<<endl;

    for (int i = 0; i<10; i++)
        cout << "2 do " << i << " = " << pow2(i) << endl;

    return 0;
}
