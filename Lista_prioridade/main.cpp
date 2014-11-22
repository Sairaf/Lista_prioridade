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
 cout <<"===============================================" << endl	;
 cout << "Bem vindo ao Sistema do Hospital" << endl;
 cout << "Por favor escolha uma das opcoes abaixo:" << endl;
 cout << "1 - Adicionar Paciente" << endl;
 cout << "2 - Verificar Lista de paciente a espera" << endl;
 cout << "3 - Informar que um novo coracao chegou" << endl;
 cout << "0 - Sair" << endl;
 cout << endl<<"Por favor escolha uma opcao" << endl;
 cout <<"===============================================" <<endl	;
}


void Subir(Paciente * vetor[],int& pos){
 Paciente* aux = new Paciente();
 int pos_pai = pos/2;
 //cout << pos_pai << endl;;
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
 Paciente aux;
 for(i = 1; i < tamanho;i++){
  cout << "Paciente "<< i << ": " << endl;
  cout << vetor[i]->getNome() << endl;
  cout << vetor[i]->getTelefone() << endl;
  cout << vetor[i]->getPrioridade() << endl;
  cout << endl;
 }
}

void Inserir(Paciente* vetor[], int pos, Paciente* novo){
	if(pos >= 2*MAX+1){
	 cout << "Lista cheia."	 <<endl;
	}else{
	 vetor[pos]	= novo;
	 Subir(vetor, pos);
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

int Buscar_Prioridade(Paciente* vetor[], int tamanho){
	int i;
	int pos_Atendido = 0;
	for(i = 1; i < tamanho; i++){
	if(vetor[i]->getPrioridade() > vetor[i-1]->getPrioridade())	{
	  pos_Atendido = i;
	}
   }
    Remocao(vetor, tamanho);
	return pos_Atendido;
  }


int main(int argc, char** argv) {

    Paciente* lista[2*MAX+1];// = new Paciente;
    Paciente aux;

    int t;
    int tamanho_Lista = 1 , opcao, prioridade, pos = 0, aux_Busca;
    string nome, telefone;

    for(int t = 0; t < 2*MAX+1; t++)
      lista[t]= new Paciente;

    Menu();
    cin >> opcao;
   do{

    switch(opcao){
    	case 1:
    	if(tamanho_Lista <MAX){
         prioridade = -1;
    	 system("cls");
    	 cout << "Digite o nome do paciente" << endl;
    	 cin >> nome;
    	 cout << "Digite o telefone do paciente" << endl;
    	 cin >> telefone;

    	while(prioridade <= 0 || prioridade >=6){
      	    cout << "Digite a prioridade do paciente (de 1 a 5 )" << endl;
         	cin >> prioridade;
    	 }
    	 aux.setNome(nome);
    	 aux.setPrioridade(prioridade);
    	 aux.setTelefone(telefone);
         Inserir(lista, tamanho_Lista, &aux);
    	 tamanho_Lista++;
    	}


    	//system("cls");
    	cout << "Paciente adicionado na lista " << endl;
    	Menu();
        cin >> opcao;
        break;
        case 2:
        	system("cls");
        	if(tamanho_Lista > 0){
        	 Escrever(lista, tamanho_Lista);
        	}else{
        	 cout << endl<< "Lista vazia " << endl;
        	}

    	    Menu();
            cin >> opcao;
            break;
        case 3:
              system("cls");
              aux_Busca =Buscar_Prioridade(lista, tamanho_Lista);
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
}while(opcao != 0);
    return 0;
}

#endif // MAIN_H
