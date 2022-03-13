#pragma once
#include <iostream>
#include <fstream>

using namespace std;
class Data
{
private:
	int ano, mes, dia;

public:
	Data();										// a) Construtor por defeito

	Data(int _dia, int _mes, int _ano);			// a) Construtor com parâmetros
	virtual ~Data();

	void SetDia(int _dia) { dia = _dia; }		// b)	método inline
	void SetMes(int _mes) { mes = _mes; }		// b)	método inline
	void SetAno(int _ano) { ano = _ano; }		// b)	método inline

	int GetDia(void) const { return dia; }		// b)	método inline
	int GetMes(void) const { return mes; }		// b)	método inline
	int GetAno(void) const { return ano; }		// b)	método inline

	void Show(void) const;						// c)
	void Update(int _dia, int _mes, int _ano);	//	d)	
	void ReadK(void);							//	e) método que aumenta a funcionalidade da classe

	bool Igual(const Data data) const;			//	f)	

	bool operator == (const Data data) const;	//	g)	
	bool operator != (const Data data) const;	//	sobrecarga de operadores
	bool operator < (const Data data) const;	//	sobrecarga de operadores
	bool operator > (const Data data) const;	//	sobrecarga de operadores

	Data operator + (const Data data) const;	//	sobrecarga de operadores
	Data operator - (const Data data) const;	//	sobrecarga de operadores

	friend ostream & operator << (ostream &os, const Data data);//	sobrecarga de operadores
	friend istream & operator >> (istream &is, Data &data);		//	sobrecarga de operadores

	void SaveFile(ofstream& os) const;	
	void ReadFile(ifstream& is);
};

