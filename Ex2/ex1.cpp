#include <fstream>
#include <iostream>

using namespace std;
int main2()
{
	ifstream is; // objecto is para abrir o ficheiro em modo de leitura INPUT
	ofstream os; // objecto os para abrir o ficheiro em modo de escrita OUTPUT
	// para abrir o ficheiro em modo de escrita e leitura
	// deve usar-se a class fstream
	is.open("dados_ent.txt");
	if (!is) {
		cout << "ERRO: não é possível abrir o ficheiro dados_ent.txt" << '\n';
		exit(1);
	}
	os.open("dados_saida.txt");
	if (!os) {
		cout << "ERRO: não é possível abrir o ficheiro dados_saida.txt" << '\n';
		exit(1);
	}
	int a=0, b=0;
	is >> a >> b;
	cout << a << endl << b << endl; //console output
	os << a * a << ' ' << b * b;
	is.close(); // fecha o ficheiro associado a is
	os.close(); // fecha o ficheiro associado a os
	system("pause");
	return 0;
}