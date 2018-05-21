#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> primes(int i){
    vector<int> v(i);
    int count = 0;
    for (auto it = v.begin(); it!=v.end();++it)
        *it = ++count;

    for (auto it = v.begin()+1; it!=v.end();++it){
        //std::cout<<"...............";
        for (auto j = v.begin()+1; j!=it;++j){
            cout<< *j <<"\n";
            if ((*it % *j) == 0)
                v.erase(std::remove(v.begin(), v.end(), *it),v.end());
        }
    }
    return v;
}

void print(vector<int> v){
    for (auto it = v.begin(); it!=v.end();++it)
        cout<<*it<<",";
}

int main()
{
    print(primes(30));
    return 0;
}
