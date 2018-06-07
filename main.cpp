//
// Created by Manuel Diaz on 5/06/2018.
//
#include "Arbol.h"
#include "Familia.h"
#include <iostream>
#include <string>


//using namespace std;

int main()
{
    //Creacion de datos para pruebas
    Persona *gerardo = new Persona(04,"Gerardo","Diaz",60,false,true,nullptr,nullptr,true);
    Persona *pilar = new Persona(05,"Pilar","Isaza",55,false,false,nullptr, nullptr,true);
    Persona *manuel = new Persona(01,"Manuel","Diaz",31,true,true,pilar,gerardo,true);
   // Persona *paola = new Persona(03,"Paola","Ceballos",34,true,false,pilar,gerardo,true);
   // Persona *ricardo = new Persona(02,"Ricardo","Ceballos",37,true,true,pilar,gerardo,false);
    Persona *jennifer = new Persona(55,"Jennifer","Mino",29,true,false, nullptr, nullptr,true);
    Persona *santiago = new Persona(78,"Santiago","Diaz",21,true,true,jennifer,manuel,true);
    Persona *carolina = new Persona(55,"Carolina","Hernandez",20,true,false, nullptr, nullptr,true);

    Familia *familia1 = new Familia();
    familia1->setPadre(gerardo);
    familia1->setMadre(pilar);
    familia1->nacimiento(02,"Ricardo","Ceballos",true,37);
    familia1->nacimiento(03,"Paola","Ceballos",false,34);
    familia1->nacimiento(01,"Manuel","Diaz",true,31);


    Familia *familia2 = new Familia(manuel,jennifer);
    familia2->nacimiento(45,"Santiago","Diaz",true,21);
    familia2->nacimiento(95,"Lara","Diaz",false,19);

    Familia *familia3 = new Familia(santiago,carolina);


    auto *arbol = new Arbol;
 //   arbol->insertaFinal(&familia1);
 //   arbol->insertaFinal(&familia2);
//    arbol->nacimiento();
//    arbol->matrimonio();
    arbol->insertaFinal(familia1);
    arbol->insertaFinal(familia2);
    arbol->insertaFinal(familia3);
  //  arbol->hijosPersona();
    arbol->estadoCivil();
 //   arbol->fallecimiento();
//   arbol->fallecimiento();
 //   arbol->hijosPersona();
  //  arbol->nacimiento();
 //   arbol->matrimonio();
  //  arbol->matrimonio();
 //   arbol->imprimir();
//    arbol->imprimir();
//    arbol->nacimiento();
  //  arbol->matrimonio();
  //  arbol->matrimonio();
 //   familia1.imprimirHijos();
  //  arbol->imprimir();
  //  familia2->imprimirHijos();
 //    arbol->insertaFinal(&familia1);
  //   arbol->insertaFinal(&familia2);


    arbol->imprimir();

 //   cout << arbol->buscarPersona(45)->getVivo();





    //cout << manuel.getMama()->getNombre() << endl;


    //familia1.nacimiento();
    //familia1.nacimiento();
    //amilia1.imprimirHijos();


    return 0;
}


