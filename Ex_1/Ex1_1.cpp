#include <iostream>
#include <iomanip>
using namespace std;
int main0()
{
	int idade = 0;
	float nota = 0; //ou double
	char nome[30] = "",a = 'p';
	cout << "Escreva o seu nome:" << endl; //cout==printf, endl==\n, cin==scanf, <<==inserir, >>==extrair
	cin >> nome;
	cout << "Insira a sua idade:" << endl;
	cin >> idade;
	cout << "Insira a nota do 1o teste:" << endl;
	cin >> nota;
	cout << "Insira a inicial:" << endl;
	cin >> a;
	//cout.setf(ios::floatfield,ios::fixed); apenas parte decimal. setprecision(2) == 2 decimais
	cout << "O seu nome: " <<setw(10)<< nome <<endl<< "A sua idade: " <<setw(10)<< idade << " anos." << endl
	<< "A inicial: " << setw(10)<<a <<endl<< "A nota: " << setw(10)<< setprecision(4) << nota << "." << endl; //setprecision(4)==4num

	system("pause");
	return (0);
}