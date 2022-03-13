#include "Data.h"

Data::Data() {
	dia = mes = ano = 0;
}

Data::~Data() {}

Data::Data(int _dia, int _mes, int _ano) {
	dia = _dia;
	mes = _mes;
	ano = _ano;
}

void Data::Show(void) const {
	cout << "Data: " << GetDia() << "/" << GetMes() << "/" << GetAno() << "\n";
}

void Data::ReadK(void) {

	cout << "Dia: ";
	cin >> this->dia;
	cout << "Mes: ";
	cin >> this->mes;
	cout << "Ano: ";
	cin >> this->ano;
}

void Data::Update(int _dia, int _mes, int _ano) {
	SetDia(_dia);// dia = _dia;
	SetMes(_mes);//	mes = _mes;
	SetAno(_ano);//	ano = _ano;
}

bool Data::Igual(const Data data) const {
	if (data.ano != ano || data.mes != mes || data.dia != dia)
		return(false);
	return(true);
}

ostream & operator << (ostream &os, const Data data) {
	os << "Data:" << data.GetDia() << "/" << data.GetMes() << "/" << data.GetAno() << ";";

	return os;
}

istream & operator >> (istream &is, Data &data) {
	//métodos friend têm acesso direto aos membros da classe

	cout << "Dia: ";
	is >> data.dia;		//acesso direto		
	cout << "Mes: ";
	is >> data.mes;		//acesso direto
	cout << "Ano: ";
	is >> data.ano;		//acesso direto

	return is;
}

bool Data::operator == (const Data data) const {
	//if (data.ano != ano || data.mes != mes || data.dia != dia)
	//	return(false);
	//return(true);
	return this->Igual(data); // pode fazer-se uso de outro método da classe
}

bool Data::operator!=(const Data data) const {
	return !(this->operator==(data));
}

bool Data::operator < (const Data data) const {
	if (data.ano < ano)
		return(false);
	else	if (data.ano == ano && data.mes < mes)
		return(false);
	else	if (data.ano == ano && data.mes == mes && data.dia < dia)
		return(false);
	return(true);
}

bool Data::operator > (const Data data) const {
	if (data.ano > ano)
		return(false);
	else	if (data.ano == ano && data.mes > mes)
		return(false);
	else	if (data.ano == ano && data.mes == mes && data.dia > dia)
		return(false);
	return(true);
}

Data Data::operator+(const Data data) const {
	//efetua a soma de duas datas e devolve a soma num objeto data

	Data aux;
	aux.ano = this->GetAno() + data.GetAno();
	aux.mes = this->GetMes() + data.GetMes();
	aux.dia = this->GetDia() + data.GetDia();

	return Data();
}

Data Data::operator-(const Data data) const {
	//efetua a soma de duas datas e devolve a soma num objeto data

	Data aux;
	aux.ano = this->GetAno() - data.GetAno();
	aux.mes = this->GetMes() - data.GetMes();
	aux.dia = this->GetDia() - data.GetDia();

	return Data();
}

void Data::SaveFile(ofstream& os) const {
	os << "Data:" << GetDia() << "/" << GetMes() << "/" << GetAno() << ";";
}

void Data::ReadFile(ifstream& is) {
	char aux[10];

	is.getline(aux, sizeof(aux), ':');	// lê até ':' e remove ':'

	is.getline(aux, sizeof(aux), '/');	// lê até '/' e remove '/'
	this->dia = atoi(aux);				//string para inteiro
	is.getline(aux, sizeof(aux), '/');	// lê até '/' e remove '/'
	this->mes = atoi(aux);				//string para inteiro
	is.getline(aux, sizeof(aux), ';');	// lê até ';' e remove ';'
	this->ano = atoi(aux);				//string para inteiro
}
