#pragma once
#include <iostream>
#include <fstream>

using namespace std;
class Data
{
private: //nao se inicializa
	int dia, mes, ano;
public:
	//Construtor
	Data();
	Data(int _dia, int _mes, int _ano);
	~Data();

	//Métodos de acesso
	void setDia(int _dia);
	void setMes(int _mes);
	void setAno(int _ano);
	int getDia(void) const{ return dia; } //inline-só vale a pena com 1/2linhas
	int getMes(void) const{ return mes; }
	int getAno(void) const{ return ano; }

	//outros métodos
	void show(void) const; //const=ler, nao modifica variaveis
	void update(int _dia, int _mes, int _ano);
	bool igual(const Data outra) const;
	bool operator == (const Data outra) const;

	friend ostream& operator << (ostream& os, const Data _data);
	friend istream& operator >> (istream& is, Data& _data);

	void save(ofstream& os) const;
	void read(ifstream& is);
};

