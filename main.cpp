/*
  Archivo: main.cpp
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

#include "Arbol.h"
#include "Familia.h"
#include <iostream>
#include <string>


using namespace std;

int main()
{
    //Creacion de datos para pruebas
    Persona *gerardo = new Persona(04,"Gerardo","Diaz",60,false,true,nullptr,nullptr,true);
    Persona *pilar = new Persona(05,"Pilar","Isaza",55,false,false,nullptr, nullptr,true);

    Persona *jeffrey = new Persona(31,"Jeffrey","Rios",27,true,true, nullptr, nullptr,true);
    Persona *paola = new Persona(03,"Paola","Diaz",34,true,false,pilar,gerardo,true);
    Persona *ricardo = new Persona(02,"Ricardo","Diaz",37,true,true,pilar,gerardo,false);

    Persona *manuel = new Persona(01,"Manuel","Diaz",31,true,true,pilar,gerardo,true);
    Persona *jennifer = new Persona(96,"Jennifer","Mino",29,true,false, nullptr, nullptr,true);
    Persona *santiago = new Persona(78,"Santiago","Diaz",21,true,true,jennifer,manuel,true);
    Persona *carolina = new Persona(55,"Carolina","Hernandez",20,true,false, nullptr, nullptr,true);

    Familia *familia1 = new Familia();
    familia1->setPadre(gerardo);
    familia1->setMadre(pilar);
    familia1->nacimiento(02,"Ricardo","Diaz",true,37,false);
    familia1->nacimiento(03,"Paola","Diaz",false,34,true);
    familia1->nacimiento(01,"Manuel","Diaz",true,31,true);

    Familia *familia2 = new Familia(manuel,jennifer);
    familia2->nacimiento(78,"Santiago","Diaz",true,21,true);
    familia2->nacimiento(95,"Lara","Diaz",false,19,false);

    Familia *familia3 = new Familia(santiago,carolina);
    familia3->nacimiento(265,"Andres","Diaz",true,15,false);

    Familia *familia4 = new Familia(jeffrey,paola);
    familia4->nacimiento(47,"Juanma","Rios",true,12,false);

    auto *arbol = new Arbol;

    arbol->insertaFinal(familia1);
    arbol->insertaFinal(familia2);
    arbol->insertaFinal(familia3);
    arbol->insertaFinal(familia4);

    arbol->interfazPPal();

    return 0;
}


