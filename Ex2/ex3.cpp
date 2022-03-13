#include <fstream>
#include <iostream>

struct alunos
{
	int num=0, idade=0;
	char nome[30]="";
}aluno;
using namespace std;
int main()
{
	ifstream is; // objecto is para abrir o ficheiro em modo de leitura INPUT
	ofstream os; // objecto os para abrir o ficheiro em modo de escrita OUTPUT
	// para abrir o ficheiro em modo de escrita e leitura
	// deve usar-se a class fstream
	is.open("alunos.txt");
	if (!is) {
		cout << "ERRO: não é possível abrir o ficheiro alunos.txt" << '\n';
		system("pause");
		exit(1);
	}
	os.open("alunos.txt");
	if (!os) {
		cout << "ERRO: não é possível abrir o ficheiro alunos.txt" << '\n';
		system("pause");
		exit(1);
	}
	
	//COM TYPEDEF aluno lista[3]

	for (int i=0; i < 3; i++)
	{
		cout <<"Insira o nome do aluno: ";
		cin >> aluno.nome;
		cout << "Insira a idade do aluno: ";
		cin >> aluno.idade;
		cout << "Insira o numero do aluno: ";
		cin >> aluno.num;
		cout << endl;
		os << aluno.nome << ";" << aluno.idade << ";" << aluno.num << endl;
	}
	for (int j=0; j < 3; j++)
	{
		is.getline(aluno.nome, sizeof(aluno.nome),';');
		is >> aluno.idade; 
		is.get();
		is >> aluno.num; 
		is.get();
		cout << "Aluno " << j+1 <<": "<< aluno.nome<<";" << aluno.idade <<";" << aluno.num << endl;
	}
	is.close(); // fecha o ficheiro associado a is
	os.close(); // fecha o ficheiro associado a os
	system("pause");
	return 0;
}