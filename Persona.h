/*
  Archivo: Persona.h
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

#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>

using namespace std;


class Persona
{
protected:
    int id;
    string nombre;
    string apellidos;
    int edad;
    bool vivo;
    bool casado;
    bool hombre;
    Persona *papa;
    Persona *mama;
    Persona *sig;
    Persona *ant;
public:
    Persona();
    Persona(int id, string nombre, string apellidos, int edad, bool vivo, bool hombre, Persona *mama, Persona *papa, bool casado);
    Persona crearPersona();
    void mostrarPersona();
    ~Persona();
    void setId(int id);
    int getId();
    void setNombre(string nombre);
    string getNombre();
    void setApellidos(string apellidos);
    string getApellidos();
    void setEdad(int id);
    int getEdad();
    void setVivo(bool vivo);
    bool getVivo();
    void setSig(Persona *sig);
    Persona *getSig();
    void setAnt(Persona *ant);
    Persona *getAnt();
    void setPapa(Persona *papa);
    Persona *getPapa();
    void setMama(Persona *mama);
    Persona *getMama();
    void setCasado(bool casado);
    bool getCasado();
    void setHombre(bool hombre);
    bool getHombre();

};

#endif //PERSONA_H
