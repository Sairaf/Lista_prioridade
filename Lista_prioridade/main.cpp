/* 
 * File:   main.cpp
 * Author: ABGerson
 *
 * Created on 20 de Novembro de 2014, 23:07
 */

#include <cstdlib>
#include <stdio.h>
#include <string>
#include <vector>
#include "Paciente.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int tamanho_Lista;
    return 0;
}

void Subir(Paciente * vetor[],int pos){
 Paciente aux;
 int pos_pai = pos/2;
 if(pos_pai >= 1){
  if(vetor[pos] > vetor[pos_pai])   {
     aux = vetor[pos] ;
     vetor[pos] = vetor[pos_pai];
     vetor[pos_pai] = aux;
     Subir(vetor, pos_pai);
  }
 }
}


void Descer(Paciente * vetor[], int pos, int MAX){
    int pos_filho = pos *2, aux;
    if(pos_filho < MAX){
      if(pos_filho <= MAX){
          if(vetor[pos_filho+1] > vetor[pos_filho])
              pos_filho++;
          if(vetor[pos]->getPrioridade() < vetor[pos_filho]->getPrioridade()){
              aux = vetor[pos] ;
              
              vetor[pos] = vetor[pos_filho];                                           
              vetor[pos_filho]'' = aux;
              Subir(vetor, pos_filho, MAX);
          }
          
          
    }  
   }
}  

