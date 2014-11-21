#include <stdio.h>
#include <stdlib.h>
#define MAX 10
void Menu();
void Subir();
void Descer();
void Adicionar();
void Remover();

typedef struct{
 int valor;
 int prioridade;

}Paciente;

int main()
{
    Paciente vetor[MAX];
    printf("Hello world!\n");
    return 0;
}
