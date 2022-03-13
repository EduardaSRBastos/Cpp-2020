//	EXERCICIO 5
//		.	Considere que uma f�brica de autom�veis pretende desenvolver uma aplica��o para fazer 
//			a gest�o dos seus funcion�rios.S�o modeladas 3 classes: Data, Pessoa e Funcionario.
//
//		.1.Defina a classe Funcionario, de acordo com o diagrama apresentado.
//		.2.Implemente os construtores por defeito e com par�metros da classe Funcionario.
//		.3.Implemente os m�todos assessores da classe.
//		.4....
//			a) ...
//			b) ...
//		.5....
//		.6....
//		.7....
//		.8.Implemente a sobrecarga do m�todo � >> � para ler a informa��o de um funcion�rio, 
//			inserida pelo teclado.
//		.9.Defina mais 2 objetos do tipo Funcionario e leia os seus dados atrav�s do teclado.
//		.10.Implemente o m�todo SaveFile()para guardar os dados de um funcion�rio em ficheiro.
//		.11.No programa principal, crie um ficheiro, cujo nome seja lido atrav�s do teclado e 
//			guarde a informa��o dos 4 funcion�rios, um por linha, com os campos separados por �;�.
//		.12.Implemente o m�todo ReadFile()para ler os dados de um funcion�rio a partir de um 
//			ficheiro.
//		.13.No programa principal, leia do ficheiro, criado na al�nea 5.10, os dados de todos 
//			os funcion�rios para um vetor de objetos.
//		.14.Mostre, no ecr�, os dados de todos os Funcion�rios, ordenados pela data de nascimento.
#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Data.h"
#include "Pessoa.h"

using namespace std;
class Funcionario: public Pessoa
{
private:
	int num_func;
	string setor;
public:
	Funcionario();
	Funcionario(string _nome, Data _dn, string _mor, int _num, string _s);
	virtual ~Funcionario();

	//M�todos de acesso
	int		GetNumFunc(void) const	{ return num_func; }
	string	GetSetor(void)	const	{ return setor; }
	void	SetNumFunc(int _num)	{ num_func = _num; }
	void	SetSetor(string _s)		{ setor = _s; }

	//Outros m�todos
	virtual void Show(void) const;
	virtual void ReadK(void);

	friend istream& operator >> (istream& is, Funcionario& F);
	friend ostream& operator << (ostream& os, const Funcionario& F);

	virtual void SaveFile(ofstream& os) const;
	virtual void ReadFile(ifstream& is); 
};

