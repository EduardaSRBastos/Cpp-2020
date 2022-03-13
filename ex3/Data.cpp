#include "Data.h"



Data::Data()
{
	dia = 1; mes = 1; ano = 2020;
}

Data::Data(int _dia, int _mes, int _ano)
{
	dia = _dia;
	mes = _mes;
	ano = _ano;
}


Data::~Data()
{
}

void Data::setDia(int _dia)
{
	dia = _dia;
}

void Data::setMes(int _mes)
{
	this->mes = _mes;
}

void Data::setAno(int _ano)
{
	ano = _ano;
}

void Data::show(void) const
{
	cout <<"Data: "<< dia << "/" << mes << "/" << ano << endl;
}

void Data::update(int _dia, int _mes, int _ano)
{
	dia = _dia;
	mes = _mes;
	ano = _ano;
}

bool Data::igual(const Data outra) const
{
	if ((ano == outra.ano) && (mes == outra.mes) && (dia == outra.dia))
		return true;

	return false;
}

bool Data::operator==(const Data outra) const
{
	return igual(outra);
}

void Data::save(ofstream& os) const
{
	os << "Data: " << getDia() << "/" << getMes() << "/" << getAno() << ".";
}

void Data::read(ifstream& is)
{
	char aux[10] = "";
	is.getline(aux, sizeof(aux), ':'); //Data
	is.getline(aux, sizeof(aux), '/'); //dia
	this->dia = atoi(aux); //char to int
	//this->setDia(atoi(aux)); IGUAL
	is.getline(aux, sizeof(aux), '/'); //mes
	this->mes = atoi(aux);
	is.getline(aux, sizeof(aux), '.'); //ano
	this->ano = atoi(aux);
}

ostream& operator << (ostream& os, const Data _data)
{
	os << "Data: " << _data.getDia() << "/" << _data.getMes() << "/" << _data.getAno();
	return os;
}

istream& operator >> (istream& is, Data& _data)
{
	cout << "Dia: ";
	is >> _data.dia;
	cout << "Mes: ";
	is >> _data.mes;
	cout << "Ano: ";
	is >> _data.ano;

	return is;
}

