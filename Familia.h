/*
  Archivo: Nodo.h
  Autor: Luis Yovany Romo
  Email: luis.romo@correounivalle.edu.co
  Fecha creaciC3n: 2018-02-09
  Fecha Cltima modificaciC3n: 2018-02-09
  VersiC3n: 0.1
  Licencia: GPL
*/

// Clase: Nodo
// Responsabilidad: elemento (nodo) de un arbol
// ColaboraciCB3n: ninguna


#ifndef FAMILIA_H
#define FAMILIA_H

#include "Persona.h"

using namespace std;


class Familia
{
protected:
    Persona *padre;
    Persona *madre;
    Persona *hijoscab;
    Familia *sig;
    Familia *ant;
public:
    Familia();
    Familia(Persona *padre, Persona *madre); // este constructor se usa solo para pruebas
    ~Familia();
    void setPadre(Persona *padre);
    Persona *getPadre();
    void setMadre(Persona *madre);
    Persona *getMadre();
    void nacimiento();
    void nacimiento(int id,string nombre, string apellido, bool hombre, int edad, bool casado); // este nacimiento se usa solo para pruebas
    void imprimirHijos();
    void imprimirNietos();
    Persona *getHijosCab();
    void setSig(Familia *sig);
    Familia *getSig();
    void setAnt(Familia *ant);
    Familia *getAnt();
};

#endif