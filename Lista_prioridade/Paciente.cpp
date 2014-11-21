#include "Paciente.h"

Paciente::Paciente(){
 this->setNome("desconhecido")	;
 this->setPrioridade(1);
 this->setTelefone("00000000") ;	
}

Paciente::~Paciente(){
	
}

ostream& operator<<(ostream& output, Paciente& paciente){
 output << "Nome: "	     << paciente.getNome() << endl;
 output << "Telefone: "	 << paciente.getTelefone() << endl;
 output << "Prioridade: "<< paciente.getPrioridade() << endl;
 return output;
}

Paciente* Paciente::operator=(Paciente& paciente){
 Paciente* aux;
 aux->setNome(paciente.getNome());
 aux->setTelefone(paciente.getTelefone());	
 aux->setPrioridade(paciente.getPrioridade());
 return aux;
}

void Paciente::setNome(const string& nome){
 if(nome.empty() == false)	{
  this->nome = nome;	
 }else{
  this->nome = "nao informado";		
 }
}

void Paciente::setTelefone(const string& telefone){
 if(telefone.empty() == false)	{
  this->telefone = telefone;	
 }else{
  this->telefone = "nao informado";		
 }
}

void Paciente::setPrioridade(const int& prioridade){
 if(prioridade > 0 && prioridade < 6)	{
  this->num_Prioridade = prioridade;	
 }else{
  this->num_Prioridade = 1;
 }
}

string Paciente::getNome() const{
	return this->nome;
}

int Paciente::getPrioridade() const{
	return this->num_Prioridade;
}

string Paciente::getTelefone() const{
	return this->telefone;
}
