/*
 * File:   main.cpp
 * Author: ABGerson
 *
 * Created on 20 de Novembro de 2014, 23:07
 */
#ifndef MAIN_H
#define MAIN_H
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <vector>
#include "Paciente.h"

const int MAX = 10;

using namespace std;

void Menu(){
 cout <<"================================================="	;
 cout << "Bem vindo ao Sistema do Hospital" << endl;
 cout << "Por favor escolha uma das opcoes abaixo:" << endl;
 cout << "1 - Adicionar Paciente" << endl;
 cout << "2 - Verificar Lista de paciente a espera" << endl;
 cout << "3 - Informar que um novo coracao chegou" << endl;
 cout << "0 - Sair" << endl;
 cout << endl<<"Por favor escolha uma opcao" << endl;
 cout <<"================================================="	;
}


void Subir(Paciente * vetor[],int pos){
 Paciente* aux;
 int pos_pai = pos/2;
 if(pos_pai >= 1){
  if(vetor[pos] > vetor[pos_pai])   {
     aux = vetor[pos] ;
     vetor[pos] = vetor[pos_pai];
     vetor[pos_pai] = aux;
  }
  Subir(vetor, pos_pai);
 }
}


void Descer(Paciente * vetor[], int pos, int MAX){
    int pos_filho = pos *2;
    Paciente* aux;
    if(pos_filho < MAX){
      if(pos_filho <= MAX){
          if(vetor[pos_filho+1] > vetor[pos_filho])
              pos_filho++;
          if(vetor[pos]->getPrioridade() < vetor[pos_filho]->getPrioridade()){
              aux = vetor[pos] ;

              vetor[pos] = vetor[pos_filho];
              vetor[pos_filho] = aux;

          }
    }
     Descer(vetor, pos_filho, MAX);
   }
}

void Escrever(Paciente* vetor[], int tamanho){
 int i;
 for(i = 0; i < tamanho;i++){
  cout << vetor[i];
 }
}

void Inserir(Paciente* vetor[], int pos, Paciente* novo){
	if(pos >= MAX){
	 cout << "Lista cheia."	 <<endl;
	}else{
	 vetor[pos]	= novo;
	 pos++ ;
	 Subir(vetor, pos);	 	
	}
}

Paciente* Buscar_Prioridade(Paciente* vetor[], int tamanho, int prioridade){
	int i;
	int pos_Atendido = 0;
	for(i = 1; i < tamanho; i++){
	if(vetor[i]->getPrioridade() > vetor[i-1]->getPrioridade())	{
	  pos_Atendido = i;	
	}else if(vetor[i]->getPrioridade() == vetor[i-1]->getPrioridade())	{
		if(vetor[i]->getNome() < vetor[i-1]->getNome()){
		 pos_Atendido = i;		
		}else{
		 pos_Atendido = i-1;	 	
		}
	}
	return vetor[pos_Atendido];
  }
	
}

void Remocao(Paciente* vetor[], int tamanho){
  if(tamanho == 0)	{
   cout <<"A lista esta vazia" << endl;
  }else{
   vetor[0]	=vetor[tamanho];
   free(vetor[tamanho]);
   tamanho--;
   Descer(vetor, 0, tamanho);
  }
}



int main(int argc, char** argv) {

    Paciente* lista[2*MAX+1], aux;
    int tamanho_Lista , opcao, prioridade, pos = 0;
    string nome, telefone;
    Menu();
    cin >> opcao;
    
    switch(opcao){
    	case 1:
    	system("cls");	
    	cout << "Digite o nome do paciente" << endl;	
    	cin >> nome;
    	cout << "Digite o telefone do paciente" << endl;
    	cin >> telefone;
    	cout << "Digite a prioridade dopaciente" << endl;
    	cin >> prioridade;
        aux.setNome(nome);
        aux.setTelefone(telefone);
        aux.setPrioridade(prioridade);
    	Inserir(lista, pos, &aux);
    	tamanho_Lista++;
    	system("cls");	
    	cout << "Paciente adicionado na lista " << endl;
    	Menu();
        cin >> opcao;
        break;
    	case 0:
    	system("cls");	
    	system("pause");
    	return 0;
    	default:
    	system("cls");
    	cout << "Opcao invalida" << endl	;
    	Menu();
    	cin >> opcao;
    	break;
    }
    return 0;
}

#endif // MAIN_H
