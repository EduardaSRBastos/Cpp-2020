#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS 1
#endif

#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
	FILE *f1=NULL, *f2=NULL;
	int a=0, b=0,c=0,d=0,num=1;
	// abre o ficheiro dados_ent.txt no modo de leitura e associa-o a f1
	if ((f1 = fopen("dados_ent.txt", "r")) == NULL) {
		printf("ERRO: não é possível abrir o ficheiro dados_ent.txt\n");
		exit(1);
	}
	// abre o ficheiro dados_saida.txt no modo de escrita e associa-o a f2
	if ((f2 = fopen("dados_saida.txt", "w")) == NULL) {
		printf("ERRO: não é possível abrir o ficheiro dados_saida.txt\n");
		exit(1);
	}
	fscanf(f1, "%d", &a); // leitura e escrita
	fscanf(f1, "%d", &b);
	printf("%d %d\n", a, b);
	fprintf(f2, "Este ficheiro foi alterado na aula Nº .%d\n",num);
	c = a * a;
	d = b * b;
	fprintf(f2, "%d\n", c);
	fprintf(f2, "%d\n", d);
	fclose(f1); // fecha o ficheiro associado a f1
	fclose(f2); // fecha o ficheiro associado a f2
	printf("Valores alterados: %d %d\n", c, d);
	system("pause");
	return 0;
}