#ifndef PACIENTE_H
#define PACIENTE_H

#include <iostream>
#include <cstdlib>
#include<string>
using namespace std;


class Paciente {


    friend ostream &operator<<(ostream&,  Paciente&);
public:
    Paciente();
    //Paciente(const Paciente& orig);
    virtual ~Paciente();

    void setNome(const string&);
    string getNome() const;

    void setTelefone(const string&);
    string getTelefone() const;

    void setPrioridade(const int&);
    int getPrioridade() const;

    Paciente operator=(const Paciente&);
    //Paciente* operator=(Paciente*);

protected:
    string nome;
    int num_Prioridade;
    string telefone;

};

#endif	/* PACIENTE_H */

