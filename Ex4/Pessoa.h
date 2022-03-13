#pragma once
#include "Data.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
class Pessoa
{
private:
	string nome, morada;
	Data datan;
public:
	Pessoa();
	virtual ~Pessoa();
	Pessoa(string _nome, Data _datan, string _morada);

	void setNome(string _nome) { nome = _nome; }
	void setDatan(Data _datan) { datan = _datan; }
	void setMorada(string _morada) { morada = _morada; }
	string getNome(void) { return nome; }
	Data getDatan(void) { return datan; }
	string getMorada(void) { return morada; }

	void show(void)const { cout <<"Nome: "<< nome << " | Data Nascimento: "<< datan <<" | Morada"<< morada<<endl; }
};

