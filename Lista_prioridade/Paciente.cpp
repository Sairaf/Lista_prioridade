/* 
 * File:   Paciente.cpp
 * Author: ABGerson
 * 
 * Created on 20 de Novembro de 2014, 23:08
 */

#include "Paciente.h"

Paciente::Paciente() {  
  this->nome = "Desconhecido"  ;
  this->telefone = "1234-5678";
  this->num_Prioridade = 1;    
}

Paciente::Paciente(const Paciente& orig) {
}

Paciente::~Paciente() {
}

Paciente operator&(const Paciente& orig){
 Paciente aux();
 aux->setNome(orig->getNome());
 aux->setPrioridade(orig->setPrioridade());
 aux->setTelefone(orig->getTelefone());
 return aux;
}
ostream operator<<(ostream& output, const Paciente&){
 
    output << "Nome do Paciente: " << Paciente->getNome() << endl;
    output << "Telefone do Paciente: " << Paciente->getTelefone() << endl;
    output << "Prioridade" << Paciente->getNome() << endl;
    return output;
}