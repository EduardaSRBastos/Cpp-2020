#include "Funcionario.h"


Funcionario::Funcionario() : Pessoa() {
	num_func = 0;
	setor = "";
}
Funcionario::Funcionario(string nome, Data dn, string mor, int num, string s) : Pessoa(nome, mor, dn) {
	num_func = num;
	setor = s;
}
Funcionario::~Funcionario() {}

void Funcionario::Show(void) const {
	Pessoa::Show();
	cout << " Num: " << GetNumFunc() << endl
		<< " Setor: " << GetSetor();
}
void Funcionario::ReadK(void) {
	Pessoa::ReadK();
	cout << "Num:";
	cin >> this->num_func;	cin.ignore();
	cout << "Setor:";
	cin >> this->setor; 	cin.ignore();
}

istream& operator >> (istream& is, Funcionario& F) {
	is >> (Pessoa&)F;

	cout << "Numero: ";
	is >> F.num_func;		/*acesso direto	*/		cin.ignore();
	cout << "Setor: ";
	is >> F.setor;			/*acesso direto	*/		cin.ignore();

	return is;
}
ostream& operator << (ostream& os, const Funcionario& F) {
	os << (Pessoa&)F;
	os << "Numero: " << F.GetNumFunc() << endl;
	os << "Setor: " << F.GetSetor() << endl;

	return os;
}

void Funcionario::SaveFile(ofstream& os) const {
	Pessoa::SaveFile(os);
	os << num_func << ";" << setor << ";";
}
void Funcionario::ReadFile(ifstream& is) {
	Pessoa::ReadFile(is);

	char aux[50];
	is.getline(aux, 100, ';');
	num_func = atoi(aux);
	is.getline(aux, 100, ';');
	setor = aux;
}