/*
  Archivo: Arbol.h
  Autor: Manuel Diaz COD 1741652 - Jeffrey Rios COD 1744831
  Email: manuel.isaza@correounivalle.edu.co - jeffrey.rios@correounivalle.edu.co
  Fecha creacion: 2018-06-01
  Fecha ultima modificacion: 2018-06-09
  Version: 0.1
  Licencia: GPL
*/

// Clase: Familia
// Responsabilidad:
// Colaboracion: ninguna

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
    void abuelosPersona();
    void padresHermanosPersona();
    void familiaresHastaTercer();
};
#endif //ARBOL_H
