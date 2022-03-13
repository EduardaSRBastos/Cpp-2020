#include "Pessoa.h"
#include "Data.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{
	Pessoa jonas("Jonas Culatra", Data(20,9,1987), "Rua da direita n 2");
	Pessoa joni("Joni Rato",Data(4,2,1990),"Rua da esquerda n 3");

	jonas.show();
	joni.show();
	cout << endl;
	system("pause");
	return 0;
}