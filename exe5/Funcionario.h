//	EXERCICIO 5
//		.	Considere que uma fábrica de automóveis pretende desenvolver uma aplicação para fazer 
//			a gestão dos seus funcionários.São modeladas 3 classes: Data, Pessoa e Funcionario.
//
//		.1.Defina a classe Funcionario, de acordo com o diagrama apresentado.
//		.2.Implemente os construtores por defeito e com parâmetros da classe Funcionario.
//		.3.Implemente os métodos assessores da classe.
//		.4....
//			a) ...
//			b) ...
//		.5....
//		.6....
//		.7....
//		.8.Implemente a sobrecarga do método ‘ >> ’ para ler a informação de um funcionário, 
//			inserida pelo teclado.
//		.9.Defina mais 2 objetos do tipo Funcionario e leia os seus dados através do teclado.
//		.10.Implemente o método SaveFile()para guardar os dados de um funcionário em ficheiro.
//		.11.No programa principal, crie um ficheiro, cujo nome seja lido através do teclado e 
//			guarde a informação dos 4 funcionários, um por linha, com os campos separados por ‘;’.
//		.12.Implemente o método ReadFile()para ler os dados de um funcionário a partir de um 
//			ficheiro.
//		.13.No programa principal, leia do ficheiro, criado na alínea 5.10, os dados de todos 
//			os funcionários para um vetor de objetos.
//		.14.Mostre, no ecrã, os dados de todos os Funcionários, ordenados pela data de nascimento.
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

	//Métodos de acesso
	int		GetNumFunc(void) const	{ return num_func; }
	string	GetSetor(void)	const	{ return setor; }
	void	SetNumFunc(int _num)	{ num_func = _num; }
	void	SetSetor(string _s)		{ setor = _s; }

	//Outros métodos
	virtual void Show(void) const;
	virtual void ReadK(void);

	friend istream& operator >> (istream& is, Funcionario& F);
	friend ostream& operator << (ostream& os, const Funcionario& F);

	virtual void SaveFile(ofstream& os) const;
	virtual void ReadFile(ifstream& is); 
};

