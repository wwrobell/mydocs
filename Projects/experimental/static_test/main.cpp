#include <iostream>

using namespace std;

void print_static(){
    static int liczba = 5;
    liczba += 1;
    cout << liczba << endl;
}

int main()
{
    print_static();
    print_static();
    print_static();
    return 0;
}
