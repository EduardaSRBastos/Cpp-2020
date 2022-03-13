#include "Pessoa.h"



Pessoa::Pessoa()
{
	nome = "";
	morada = "";
	datan=Data(1,1,1);
}


Pessoa::~Pessoa()
{
}

Pessoa::Pessoa(string _nome, Data _datan, string _morada)
{
	nome = _nome;
	morada = _morada;
	datan = _datan;
}