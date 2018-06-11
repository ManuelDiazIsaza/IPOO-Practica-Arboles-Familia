/*
  Archivo: Persona.cpp
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

#include <iostream>
#include "Persona.h"

Persona::Persona()
{
    id = 0;
    nombre = " ";
    apellidos = " ";
    edad = 0;
    vivo = true;
    sig = nullptr;
    ant = nullptr;
    mama = nullptr;
    papa = nullptr;
    casado = false;
    hombre = true;
}

Persona::Persona(int id, string nombre, string apellidos, int edad, bool vivo, bool hombre, Persona *mama, Persona *papa, bool casado)
{
    this -> id = id;
    this -> nombre = nombre;
    this -> apellidos = apellidos;
    this -> edad = edad;
    this -> vivo = vivo;
    this -> sig = nullptr;
    this -> ant = nullptr;
    this -> mama = mama;
    this -> papa = papa;
    this -> hombre = hombre;
    this -> casado = casado;
}

Persona Persona::crearPersona()
{
    int id,edad;
    string nombre,apellidos,hombre;
    Persona persona;
    bool hombre2;
    bool generoValido=false;

    cout<<"Nombre: ";
    cin>>nombre;
    cout<<"Apellido: ";
    cin>>apellidos;
    cout<<"ID: ";
    cin>>id;
    cout<<"Edad: ";
    cin>>edad;
    while(!generoValido)
    {
        cout << "Es hombre: " ;
        cin >> hombre;
        if(hombre == "si")
        {
            hombre2 = true;
            generoValido = true;
        }
        else if(hombre == "no")
        {
            hombre2 = false;
            generoValido = true;
        }
        else
        {
            cout << "ingresaste una opcion incorrecta." << endl;
        }
    }


    persona.setHombre(hombre2);
    persona.setNombre(nombre);
    persona.setApellidos(apellidos);
    persona.setId(id);
    persona.setEdad(edad);

    return persona;
}

void Persona::mostrarPersona()
{
    cout << "Nombre: " << this->nombre << endl;
    cout << "Apellido: " << this->apellidos << endl;
    cout << "Edad: "<< this->edad << endl;
    cout << "ID: " << this->id << endl;
    //cout<<"Sexo: "<<hombre<<endl;
}

Persona::~Persona()
{
    //MC)todo destructor
}

void Persona::setId(int id)
{
    this -> id = id;
}

int Persona::getId()
{
    return id;
}

void Persona::setNombre(string nombre)
{
    this -> nombre = nombre;
}

string Persona::getNombre()
{
    return nombre;
}

void Persona::setApellidos(string apellidos)
{
    this -> apellidos = apellidos;
}

string Persona::getApellidos()
{
    return apellidos;
}

void Persona::setEdad(int edad)
{
    this -> edad = edad;
}

int Persona::getEdad()
{
    return edad;
}

void Persona::setVivo(bool vivo)
{
    this -> vivo = vivo;
}

bool Persona::getVivo()
{
    return vivo;
}

void Persona::setSig(Persona *sig){
    this -> sig = sig;
}

Persona* Persona::getSig(){
    return this -> sig;
}

void Persona::setAnt(Persona *ant){
    this -> ant = ant;
}

Persona* Persona::getAnt(){
    return this -> ant;
}
void Persona::setPapa(Persona *papa){
    this -> papa = papa;
}

Persona* Persona::getPapa(){
    return this -> papa;
}

void Persona::setMama(Persona *mama){
    this -> mama = mama;
}

Persona* Persona::getMama(){
    return this -> mama;
}

void Persona::setCasado(bool casado)
{
    this -> casado = casado;
}

bool Persona::getCasado()
{
    return casado;
}

void Persona::setHombre(bool hombre)
{
    this -> hombre = hombre;
}

bool Persona::getHombre()
{
    return hombre;
}


