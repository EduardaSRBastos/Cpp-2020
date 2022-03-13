#include <stdio.h>
#include <iostream>
#include "Data.h"
#include <fstream>

using namespace std; //standard
int main(void)
{
	int dia=0, mes=0, ano=0;
	Data duda;
	Data joe(20,2,1972);

	cout << "Duda:" << endl;
	duda.show();
	cout << "Joe:" << endl;
	joe.show();
	cout << endl;
	cout << "Insira o dia da Duda: ";
	cin >> dia;
	duda.setDia(dia);
	cout << "Insira o mes da Duda: ";
	cin >> mes;
	duda.setMes(mes);
	cout << "Insira o ano da Duda: ";
	cin >> ano;
	duda.setAno(ano);
	
	cout << endl;
	joe.update(17, 2, 1972);
	duda.update(duda.getDia(), duda.getMes(), duda.getAno());
	cout << "Duda:" << endl;
	duda.show();
	cout << "Joe:" << endl;
	joe.show();
	cout << endl;

	if (duda==joe)
	{
		cout << "As datas sao iguais." << endl;
	}
	else
	{
		cout << "As datas sao diferentes." << endl;
	}

	ifstream is;
	is.open("data.txt");
	if (!is) return 1; //Erro de abertura
	joe.read(is);
	is.close();
	cout << endl << "Joe read: " << joe;

	cout << endl << "Duda: " << duda;
	ofstream os;
	os.open("data.txt");
	if (!os) return 1; //Erro de abertura
	duda.save(os);
	os.close();

	cout << endl;
	system("pause");
	return 0;
}