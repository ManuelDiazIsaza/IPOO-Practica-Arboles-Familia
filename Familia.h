/*
  Archivo: Familia.h
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