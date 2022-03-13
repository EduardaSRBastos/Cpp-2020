//		Exercicio 5
//	x	Considere que uma f�brica de autom�veis pretende desenvolver uma aplica��o para fazer 
//	x	a gest�o dos seus funcion�rios.S�o modeladas 3 classes: Data, Pessoa e Funcionario.
//
//	x	.1.Defina a classe Funcionario, de acordo com o diagrama apresentado.
//	x	.2.Implemente os construtores por defeito e com par�metros da classe Funcionario.
//	x	.3.Implemente os m�todos assessores da classe.
//		.4.Num programa, defina 2 objetos do tipo Funcionario com os seguintes atributos :
//			a) Joca Gaio; 20 / 9 / 1987; Rua da direita n 2; 25023; Pintura.
//			b) Ana Rola; 4 / 2 / 1990; Rua da esquerda n 3; 25024; Comercial.
//		.5.Mostre no ecr� os dados dos funcion�rios criados na al�nea anterior.
//		.6.Atualize a morada do �Joca Gaio� para �Rua do meio n 4� e o setor para �Ferragem�.
//		.7.Na data de nascimento da �Ana Rola�, altere o dia para �23�.
//	x	.8.Implemente a sobrecarga do m�todo � >> � para ler a informa��o de um funcion�rio, 
//			inserida pelo teclado.
//		.9.Defina mais 2 objetos do tipo Funcionario e leia os seus dados atrav�s do teclado.
//	x	.10.Implemente o m�todo SaveFile()para guardar os dados de um funcion�rio em ficheiro.
//		.11.No programa principal, crie um ficheiro, cujo nome seja lido atrav�s do teclado e 
//			guarde a informa��o dos 4 funcion�rios, um por linha, com os campos separados por �;�.
//	x	.12.Implemente o m�todo ReadFile()para ler os dados de um funcion�rio a partir de um 
//			ficheiro.
//		.13.No programa principal, leia do ficheiro, criado na al�nea 5.10, os dados de todos 
//			os funcion�rios para um vetor de objetos.
//		.14.Mostre, no ecr�, os dados de todos os Funcion�rios, ordenados pela data de nascimento.
//
// x - m�todo implementado (total ou parcialmente) na classe Funcionario


#include <iostream>
#include <fstream>
#include <string>

#include "Data.h"
#include "Pessoa.h"
#include "Funcionario.h"

using namespace std;
void atencao() {
	char aux[50];
	string file;

	//.....
	//Esta sequ�ncia n�o funciona: o getline apenas l� um 'enter'
	cin >> file;
	cin.getline(aux, sizeof(aux), '\n');
	//.....


	//a seguir: usar cin.ignore() l� o 'enter'ap�s o 'cin >>...'
	cin.getline(aux, sizeof(aux), '\n');
	cin >> file;		cin.ignore();
	//...assim estas duas sequ�ncias j� funcionam
	cin >> file;		cin.ignore();
	cin.getline(aux, sizeof(aux), '\n');
	//...
}
int main()
{
	// 5.4 a) e b)
	Funcionario
		Joca("Joca Gaio", Data(20, 9, 1987), "Rua da direita n 2", 25023, "Pintura"),
		Ana("Ana Rola", Data(4, 2, 1990), "Rua da esquerda n 3", 25024, "Comercial");

	// 5.5
	cout << endl << Ana.GetNome()
		<< endl << Ana.GetData()
		<< endl << Ana.GetMorada()
		<< endl << Ana.GetNumFunc()
		<< endl << Ana.GetSetor();
	Joca.Show();

	// 5.6
	Joca.SetMorada("Rua do meio n 4");
	Joca.SetSetor("Ferragem");
	// 5.7
	Ana.GetData().SetDia(23);

	// 5.9

	//Funcionario A("a",Data(20,6,1800), "Mor A", 123, "s A"), 
	//	B("b", Data(1,1,2000), "Mor B", 123, "s B");
	Funcionario A, B;
	cout << endl << "Func A: "; cin >> A;
	cout << endl << "Func B: "; cin >> B;

	// 5.11
	string file = "funcionarios.txt";;
	ofstream os;

	cout << endl << "Introduza o nome do ficheiro: ";
	cin >> file;		cin.ignore();
	os.open(file);
	if (!os) {
		cout << "Erro" << endl;
	}
	else {
		Joca.SaveFile(os);	os << endl;
		Ana.SaveFile(os);	os << endl;
		A.SaveFile(os);		os << endl;
		B.SaveFile(os);		os << endl;

		os.close();
	}

	// 5.13
	Funcionario VF[10];
	int n = 0;
	//	char aux[5];

	ifstream is;
	is.open(file);
	if (!is) {
		cout << "Erro" << endl;
	}
	else {

		while (is.peek() != EOF) {
			VF[n].ReadFile(is);
			is.get(); //is.getline(aux, sizeof(aux), '\n');
			n++;
		}
		is.close();
	}

	// 5.14
	// Ordenar um vetor de funcion�rios pela data nascimento
	Funcionario aux;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (VF[j].MaisNovo(VF[i])) {
				aux = VF[i];
				VF[i] = VF[j];
				VF[j] = aux;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << endl << endl << VF[i];
	}

	//////////////
	cout << endl << endl;
	std::system("pause");
	return (0);
}