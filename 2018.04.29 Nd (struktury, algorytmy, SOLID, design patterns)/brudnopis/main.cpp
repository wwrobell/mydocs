#include <assert.h>
#include <map>
#include <iostream>

using namespace std;

int powNToK(int n, int k)
{
    assert(k >= 0);
    if (k == 0) return 1;
    else return n * powNToK(n, k-1);
}

long fib(int n)
{
    assert(n >= 0);
    if (n <= 1) return n;
    else return fib(n-1) + fib(n-2);
}

long fibCached(int n)
{
    assert(n >= 0);
    if (n <= 1) return n;
    else {
        static map<int,long> fibs;
        auto it = fibs.find(n);
        long fibN;
        if (it == fibs.end()) {
            fibN = fibCached(n - 1) + fibCached(n - 2);
            fibs[n] = fibN;
        }
        else {
           fibN = it->second;
        }
        return fibN;
    }
}

int main()
{
    cout << "Running misc functions..." << endl;

    for (int i = 0; i < 45; ++i) {
       cout << "fib(" << i << ") = " << fib(i) << endl;
    }

    cout << endl;

    for (int i = 0; i < 8; ++i) {
       cout << "pow2ToK(" << i << ") = " << powNToK(2, i) << endl;
    }

    cout << endl;

    for (int i = 0; i < 50; ++i) {
       cout << "fibCached(" << i << ") = " << fibCached(i) << endl;
    }
}
