#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

int main()
{
    const int SIZE = 20;
    char buf[SIZE];
    string line;

    //gcount ile udalo sie przeczytac
    ifstream myfile ("toCopy");
    ofstream copiedFile;

    copiedFile.open("copiedFile.txt", ios::app);

    if (myfile.is_open())
      {
        while ( getline (myfile,line) )
        {
          copiedFile << line << '\n';
        }
        myfile.close();
        copiedFile.close();
      }

    for (int i = 0;i<SIZE;++i){
        buf[i] = 'x';
    }


    ////////
    //std::ifstream in;
    //std::ostream out;
    //char buf[SIZE];
    //
    //while(...){
    //    in.read(...)
    //    int size = in.gcount();
    //    out.write(...);
    //}
    return 0;
}
