/* 
 * File:   Paciente.h
 * Author: ABGerson
 *
 * Created on 20 de Novembro de 2014, 23:08
 */

#ifndef PACIENTE_H
#define	PACIENTE_H
#define <iostream>
#define <cstdlib>
#define <string>

using namespace std;


class Paciente {
    
    
    friend ostream &operator<<(ostream&, const Paciente&);
public:
    Paciente();
    Paciente(const Paciente& orig);
    virtual ~Paciente();
    
    string getNome(){
      return this->nome;  
    }
    
    string getTelefone(){
     return this->telefone;   
    }
    
    int getPrioridade(){
     return this->num_Prioridade;
    }
    
    void setNome(const string& nome){
        this.nome = nome;
    }
    
    void setTelefone(const string& telefone){
        this->telefone = telefone;
    }
    
    void setPrioridade(const int& priori){
        this->num_Prioridade = priori;
    }
    
    Paciente operator&(const Paciente&);
    
protected:
    string nome;
    int num_Prioridade;
    string telefone;
    
};

#endif	/* PACIENTE_H */

