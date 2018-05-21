#include <iostream>
#include "list.h"

using namespace std;

int main(int argc, char *argv[])
{
    List mojalista;
    mojalista.insert(5);
	mojalista.insert(7);
	mojalista.insert(2);
	mojalista.print();
	
	int tablica[] = { 4,2,6,5,1 };
	List mojaListaZTablicy = List(tablica, 5);
	std::cout << "Lista stworzona z tablicy: \n";
	mojaListaZTablicy.print();
	
	//int liczba(9);
	//std::cout << "Zawiera: " << liczba << "\n" << mojaListaZTablicy.contains(liczba) <<"\n";
	std::cout << "Reversed: \n";
	mojaListaZTablicy.reverse();
	mojaListaZTablicy.print();
	//std::string test = mojaListaZTablicy.toString();
	//std::cout << test << std::endl;
    return 0;
}
