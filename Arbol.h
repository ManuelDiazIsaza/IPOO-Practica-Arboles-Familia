//
// Created by Manuel Diaz on 5/06/2018.
//

#ifndef ARBOL_H
#define ARBOL_H

#include "Familia.h"
#include <iostream>

using namespace std;

class Arbol
{
protected:
    Familia *cab;
public:
    Arbol();
    ~Arbol();
    void matrimonio();
    Persona* buscarPersona(int); // Busca en hijos y padres de todas las familias.
    void insertaFinal(Familia *familia);
    void imprimir();
    void nacimiento();
    void fallecimiento();
    void hijosPersona();
    void estadoCivil();
    void interfazPPal();
    void nietosPersona();
};
#endif //ARBOL_H
