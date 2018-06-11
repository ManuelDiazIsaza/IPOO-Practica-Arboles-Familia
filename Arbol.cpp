/*
  Archivo: Arbol.cpp
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
#include <iostream>

using namespace std;

Arbol::Arbol()
{
    cab = nullptr;
}

Arbol::~Arbol()
{
    Familia *desplaza = cab;
    Familia *borrar;
    while (desplaza != nullptr)
    {
        borrar = desplaza;
        desplaza = desplaza->getSig();
        delete borrar;
        borrar = nullptr;
    }
}

void Arbol::matrimonio()
{

    Familia *familia = new Familia();
    Persona *persona2 = new Persona();

    int id;

    if(cab == nullptr)
    {
        Persona *persona = new Persona();

        cout << "Ingrese los datos de las personas que se van a casar: " << endl;
        *persona = persona->crearPersona();

        cout << "Ingrese los datos de la otra persona que se va a casar: " << endl;
        *persona2 = persona2->crearPersona();

        if(persona->getEdad()<18 || persona2->getEdad()<18)
        {
            cout << "No se pueden casar ya que uno de los dos es menor de edad." << endl;
        }
        else
        {
            persona->setCasado(true);
            persona2->setCasado(true);
            if(persona->getHombre())
            {
                familia->setPadre(persona);
                familia->setMadre(persona2);
            }
            else
            {
                familia->setPadre(persona2);
                familia->setMadre(persona);
            }

            insertaFinal(familia);
        }
    }
    else
    {

        Persona *persona3 = nullptr;
        do
        {
            cout << "Ingrese el ID de la persona que se va a casar: ";
            cin >> id;
            persona3 = buscarPersona(id);
            if (persona3 == nullptr)
            {
                cout << "Persona no encontrada" << endl;
            }
            else if(persona3->getCasado())
            {
                cout << "Esta persona ya esta casada" << endl;
            }
        } while (persona3 == nullptr || persona3->getCasado());

        cout << "Ingrese los datos de la persona con la que se va a casar: " << endl;
        *persona2 = persona2->crearPersona();

        if(persona3->getEdad()<18 || persona2->getEdad()<18)
        {
            cout << "No se pueden casar ya que uno de los dos es menor de edad." << endl;
        }
        else
        {
            persona3->setCasado(true);
            persona2->setCasado(true);
        if(persona2->getHombre())
        {
            familia->setPadre(persona2);
            familia->setMadre(persona3);
        }
        else
        {
            familia->setMadre(persona2);
            familia->setPadre(persona3);
        }
        insertaFinal(familia);
        }
    }

}

Persona* Arbol::buscarPersona(int id)
{
    Familia *desplazaF = cab;

    while(desplazaF != nullptr)
    {
        if(desplazaF->getPadre()->getId() == id)
        {
            return desplazaF->getPadre();
        }
        else if(desplazaF->getMadre()->getId() == id)
        {
            return desplazaF->getMadre();
        }
        else
        {
        Persona *desplazaH = desplazaF->getHijosCab();
        while(desplazaH != nullptr)
        {
            if(desplazaH->getId() == id)
            {
                return desplazaH;
            }
            else
            {
                desplazaH = desplazaH->getSig();
            }
        }}
        desplazaF = desplazaF->getSig();
    }
    return nullptr;
}

void Arbol::insertaFinal(Familia *familia)
{
    Familia *desplaza = cab;
    if(cab==nullptr)
    {
        cab = familia;
    }
    else
    {
        while(desplaza!= nullptr)
        {
            if(desplaza->getSig()== nullptr)
            {
                desplaza->setSig(familia);
                familia->setAnt(desplaza);
                desplaza= nullptr;
            }
            else
            {
                desplaza=desplaza->getSig();
            }
        }
    }
    //cout << familia->getMadre()->getNombre() << " - " << familia->getPadre()->getNombre();
}

void Arbol::imprimir()
{
    Familia *desplaza = cab;
    int i=1;
    while (desplaza != nullptr)
    {

        cout<<"\nFamilia "<<i<<endl;
        cout<<"Padre: " << desplaza->getPadre()->getNombre() << " " << desplaza->getPadre()->getApellidos() << endl;
        cout<<"Madre: " << desplaza->getMadre()->getNombre() << " " << desplaza->getMadre()->getApellidos() << endl;
        desplaza->imprimirHijos();
        desplaza = desplaza->getSig();
        i++;
    }
    cout << endl <<endl;
}

void Arbol::nacimiento()
{
    bool encontro = false;
    Familia *pos1;
    int id=0;
    do
    {
    Familia *desplaza = cab;
    cout << "Ingrese el id de la persona que tuvo hijo(s): " ;
    cin >> id;

    while (desplaza != nullptr)
    {
        if(desplaza->getPadre()->getId() == id || desplaza->getMadre()->getId() == id)
        {
            pos1 = desplaza;
            encontro = true;
            desplaza = desplaza->getSig();
        }
        else
        {
            desplaza = desplaza->getSig();
        }
    }
    if(!encontro)
    {
        cout << "Esta persona no esta casada o no pertenece a la familia." << endl;
    }
    }while(!encontro);

    int cantidad;
    cout << "Cuantos hijos tuvo: " ;
    cin >> cantidad;

    for(int i=0;i<cantidad;i++)
    {
    pos1->nacimiento();
    }
}

void Arbol::fallecimiento()
{
    int id;
    cout << "Ingrese el id de la persona que fallecio:";
    cin >> id;
    Persona *persona =  buscarPersona(id);
    if(persona== nullptr)
    {
        cout << "No se encontro la persona. Compruebe el ID de la persona" << endl;
    }
    else
    {
    if(persona->getVivo())
    {
        persona->setVivo(false);
        cout << "Se ha registrado el fallecimiento." << endl;
    }
    else
    {
        cout << "Esta persona ya habia fallecido anteriormente." << endl;
    }
    }
}

void Arbol::hijosPersona()
{
    int id;
    cout << "Ingrese el id de la persona de la cual quiera consultar sus hijos:";
    cin >> id;
    Persona *persona =  buscarPersona(id);
    if(persona == nullptr)
    {
        cout << "No se encontro la persona. Compruebe el ID de la persona" << endl;
    }
    else
    {
        if(!persona->getCasado())
        {
            cout << "Esta Persona no esta casada, por lo tanto no es padre o madre en una familia" << endl;
        }
        else
        {
            Familia *desplaza = cab;
            Familia *pos1;
            while (desplaza != nullptr)
            {
                if(desplaza->getPadre()->getId() == id || desplaza->getMadre()->getId() == id)
                {
                    pos1 = desplaza;
                    desplaza = desplaza->getSig();
                }
                else
                {
                    desplaza = desplaza->getSig();
                }
            }
            pos1->imprimirHijos();
        }
    }
}

void Arbol::estadoCivil()
{
    int id;
    cout << "Ingrese el id de la persona que desea consultar su estado civil:";
    cin >> id;
    Persona *persona =  buscarPersona(id);
    if(persona== nullptr)
    {
        cout << "No se encontro la persona. Compruebe el ID de la persona" << endl;
    }
    else
    {
        if(persona->getCasado())
        {
            cout << "Esta persona se encuentra casado(a)." << endl;
        }
        else
        {
            cout << "Esta persona es soltera o viudo(a)." << endl;
        }
    }
}

void Arbol::nietosPersona()
{
    int id;

    cout << "Ingrese el id de la persona que desea consultar sus nietos:";
    cin >> id;
    Persona *persona =  buscarPersona(id);
    bool nonietos = true;


    if(persona== nullptr)
    {
        cout<< "No se encontro el id de esa persona, por favor verifique los datos" << endl;
    }
    else if(!persona->getCasado())
    {
        cout<<"Esta persona no esta casado, no tiene nietos" << endl;
    }
    else
    {
        Familia *desplazaF = cab;

        while(desplazaF != nullptr){

            if(desplazaF->getPadre()->getId() == id || desplazaF->getMadre()->getId() == id)
            {
                Persona *desplazaH = desplazaF->getHijosCab();

                while(desplazaH!= nullptr)
                {

                    if(desplazaH->getCasado())
                    {
                    Familia *desplazaF2 = cab;
                    while(desplazaF2!= nullptr)
                    {
                        if(desplazaF2->getPadre()->getId() == desplazaH->getId() || desplazaF2->getMadre()->getId() == desplazaH->getId())
                        {
                            if(desplazaF2->getHijosCab()== nullptr)
                            {
                                desplazaF2 = desplazaF2->getSig();
                            }
                            else
                            {
                            cout << "Nietos de " << persona->getNombre() << " por parte de "<< desplazaH->getNombre() << ": ";
                            desplazaF2->imprimirNietos();
                            desplazaF2 = desplazaF2->getSig();
                            nonietos = false;
                            }
                        }
                        else
                        {
                            desplazaF2 = desplazaF2->getSig();
                        }
                    }
                    desplazaH = desplazaH->getSig();
                    }
                    else
                    {
                        desplazaH = desplazaH->getSig();
                    }
                }
                desplazaF = desplazaF ->getSig();
            }
            else
            {
                desplazaF = desplazaF->getSig();
            }
        }


    }

    if(nonietos)
    {
        cout << "Esta persona no tiene nietos." << endl;
    }

}

void Arbol::abuelosPersona()
{
    int id;

    cout << "Ingrese el id de la persona que desea consultar sus abuelos:";
    cin >> id;
    Persona *persona =  buscarPersona(id);


    if(persona == nullptr)
    {
        cout << "Este ID no corresponde a ningun miembro de la familia." << endl;
    }
    else if(persona->getId()== cab->getPadre()->getId() || persona->getId()== cab->getMadre()->getId())
    {
        cout << "Este es el papa o mama de la familia Genesis por lo tanto no tienen abuelos registrados." << endl;
    }
    else if(persona->getPapa()== nullptr && persona->getMama()== nullptr)
    {
        cout << "Este es el esposo o esposa de uno de los miembros de la familia por lo tanto no tienen abuelos registrados." << endl;
    }
    else if(persona->getPapa()->getPapa()!= nullptr)
    {
        cout << "Los abuelos por parte de papa son: " << endl;
        cout << "Abuelo: " <<persona->getPapa()->getPapa()->getNombre() << " " << persona->getPapa()->getPapa()->getApellidos() << endl;
        cout << "Abuela: " <<persona->getPapa()->getMama()->getNombre() << " " << persona->getPapa()->getMama()->getApellidos() << endl;
    }
    else if(persona->getMama()->getMama()!= nullptr)
    {
        cout << "Los abuelos por parte de mama son: " << endl;
        cout << "Abuelo: " <<persona->getMama()->getPapa()->getNombre() << " " << persona->getMama()->getPapa()->getApellidos() << endl;
        cout << "Abuela: " <<persona->getMama()->getMama()->getNombre() << " " << persona->getMama()->getMama()->getApellidos() << endl;
    }
    else
    {
        cout << "Esta persona no tiene abuelos registrados en el arbol genealogico." << endl;
    }
}

void Arbol::padresHermanosPersona()
{
    int id;

    cout << "Ingrese el id de la persona que desea consultar sus padres y hermanos:";
    cin >> id;
    Persona *persona = buscarPersona(id);
    Familia *familia;

    Familia *desplazaF = cab;

    while(desplazaF != nullptr)
    {
            Persona *desplazaH = desplazaF->getHijosCab();
            while(desplazaH != nullptr)
            {
                if(desplazaH->getId() == id)
                {
                    familia = desplazaF;
                    desplazaH = desplazaH->getSig();
                }
                else
                {
                    desplazaH = desplazaH->getSig();
                }
            }
        desplazaF = desplazaF->getSig();
    }

    if(persona == nullptr)
    {
        cout << "Este ID no corresponde a ningun miembro de la familia." << endl;
    }
    else if(persona->getId()== cab->getPadre()->getId() || persona->getId()== cab->getMadre()->getId())
    {
        cout << "Este es el papa o mama de la familia Genesis por lo tanto no tiene hermanos ni padres registrados." << endl;
    }
    else if(persona->getPapa()== nullptr && persona->getMama()== nullptr)
    {
        cout << "Este es el esposo o esposa de uno de los miembros de la familia por lo tanto no tiene hermanos ni padres registrados." << endl;
    }
    else
    {
        cout << "El papa es: " << familia->getPadre()->getNombre() << " " << familia->getPadre()->getApellidos() << endl;
        cout << "La mama es: " << familia->getMadre()->getNombre() << " " << familia->getMadre()->getApellidos() << endl;
        cout << "Los hermanos son:" << endl;

        bool hermanos = false;
        Persona *desplaza = familia->getHijosCab();
        while(desplaza!= nullptr)
        {
            if(desplaza->getId() == id)
            {
                desplaza = desplaza->getSig();
            }
            else
            {
                hermanos = true;
                cout << desplaza->getNombre() << " " << desplaza->getApellidos() << endl;
                desplaza = desplaza->getSig();
            }
        }
        if(!hermanos)
        {
            cout << "No tiene hermanos." << endl;
        }
    }
}

void Arbol::familiaresHastaTercer()
{
    int id;

    cout << "Ingrese el id de la persona que desea consultar sus familiares:";
    cin >> id;
    Persona *persona =  buscarPersona(id);

    // padres e hijos
    if(persona == nullptr)
    {
        cout << "Este ID no corresponde a ningun miembro de la familia." << endl;
    }
    else
    {
        cout << endl << "Familiares de " << persona->getNombre() << " " << persona->getApellidos() << endl << endl;
        cout << "Primer Grado de Consanguinidad. (Padres,Hijos)" << endl;
        //padres
        if (persona->getPapa() != nullptr) {
            cout << "Padres: " << endl;
            cout << "Papa: " << persona->getPapa()->getNombre() << " " << persona->getPapa()->getApellidos();
                 if(persona->getPapa()->getVivo() == 1)
                     cout << " - vivo" << endl;
                 else cout << " - fallecido" << endl;
            cout << "Mama: " << persona->getMama()->getNombre() << " " << persona->getMama()->getApellidos();
            if(persona->getMama()->getVivo() == 1)
                cout << " - vivo" << endl;
            else cout << " - fallecido" << endl;
        }
        //hijos
        Familia *desplazaF = cab;

        while (desplazaF != nullptr) {
            if (desplazaF->getPadre()->getId() == id || desplazaF->getMadre()->getId() == id) {
                desplazaF->imprimirHijos2();
                desplazaF = desplazaF->getSig();
            } else {
                desplazaF = desplazaF->getSig();
            }
        }
    }

    cout << endl;
    // abuelos, hermanos, nietos
    if(persona == nullptr)
    {
    }
    else
    {
        cout << "Segundo Grado de Consanguinidad.(Abuelos,Hermanos,Nietos)" << endl;

        // abuelos
        if(persona->getId()== cab->getPadre()->getId() || persona->getId()== cab->getMadre()->getId())
        {
        }
        else if(persona->getPapa()== nullptr && persona->getMama()== nullptr)
        {
        }
        else if(persona->getPapa()->getPapa()!= nullptr)
        {
            cout << "Abuelos" << endl;
            cout << "Los abuelos por parte de papa son: " << endl;
            cout << "Abuelo: " <<persona->getPapa()->getPapa()->getNombre() << " " << persona->getPapa()->getPapa()->getApellidos();
            if(persona->getPapa()->getPapa()->getVivo() == 1)
                cout << " - vivo" << endl;
            else cout << " - fallecido" << endl;
            cout << "Abuela: " <<persona->getPapa()->getMama()->getNombre() << " " << persona->getPapa()->getMama()->getApellidos();
            if(persona->getPapa()->getMama()->getVivo() == 1)
                cout << " - vivo" << endl;
            else cout << " - fallecido" << endl;
        }
        else if(persona->getMama()->getMama()!= nullptr)
        {
            cout << "Abuelos" << endl;
            cout << "Los abuelos por parte de mama son: " << endl;
            cout << "Abuelo: " <<persona->getMama()->getPapa()->getNombre() << " " << persona->getMama()->getPapa()->getApellidos();
            if(persona->getMama()->getPapa()->getVivo() == 1)
                cout << " - vivo" << endl;
            else cout << " - fallecido" << endl;
            cout << "Abuela: " <<persona->getMama()->getMama()->getNombre() << " " << persona->getMama()->getMama()->getApellidos();
            if(persona->getMama()->getMama()->getVivo() == 1)
                cout << " - vivo" << endl;
            else cout << " - fallecido" << endl;
        }
        else
        {
        }

        //hermanos
        Familia *desplazaF = cab;
        Familia *familia = nullptr;


        while(desplazaF != nullptr)
        {
            Persona *desplazaH = desplazaF->getHijosCab();
            while(desplazaH != nullptr)
            {
                if(desplazaH->getId() == id)
                {
                    familia = desplazaF;
                    desplazaH = desplazaH->getSig();
                }
                else
                {
                    desplazaH = desplazaH->getSig();
                }
            }
            desplazaF = desplazaF->getSig();
        }

        bool hermanos = false;

        if(familia!= nullptr)
        {
        Persona *desplaza = familia->getHijosCab();
        cout << "Hermanos: " << endl;

        while(desplaza!= nullptr)
        {
            if(desplaza->getId() == id)
            {
                desplaza = desplaza->getSig();
            }
            else
            {
                hermanos = true;
                cout << desplaza->getNombre() << " " << desplaza->getApellidos();
                if(desplaza->getVivo() == 1)
                    cout << " - vivo" << endl;
                else cout << " - fallecido" << endl;
                desplaza = desplaza->getSig();
            }
        }

        if(!hermanos)
        {
            cout << "No tiene hermanos." << endl;
        }
        }

        //nietos

        if(!persona->getCasado())
        {
        }
        else
        {
            Familia *desplazaF = cab;

            while(desplazaF != nullptr){

                if(desplazaF->getPadre()->getId() == id || desplazaF->getMadre()->getId() == id)
                {
                    Persona *desplazaH = desplazaF->getHijosCab();

                    while(desplazaH!= nullptr)
                    {

                        if(desplazaH->getCasado())
                        {
                            Familia *desplazaF2 = cab;
                            while(desplazaF2!= nullptr)
                            {
                                if(desplazaF2->getPadre()->getId() == desplazaH->getId() || desplazaF2->getMadre()->getId() == desplazaH->getId())
                                {
                                    if(desplazaF2->getHijosCab()== nullptr)
                                    {
                                        desplazaF2 = desplazaF2->getSig();
                                    }
                                    else
                                    {
                                        cout << "Nietos por parte de "<< desplazaH->getNombre() << ": ";
                                        desplazaF2->imprimirNietos2();
                                        desplazaF2 = desplazaF2->getSig();
                                    }
                                }
                                else
                                {
                                    desplazaF2 = desplazaF2->getSig();
                                }
                            }
                            desplazaH = desplazaH->getSig();
                        }
                        else
                        {
                            desplazaH = desplazaH->getSig();
                        }
                    }
                    desplazaF = desplazaF ->getSig();
                }
                else
                {
                    desplazaF = desplazaF->getSig();
                }
            }

        }
    }

    cout << endl;
    //tios sobrinos

    if(persona == nullptr)
    {
    }
    else {
        cout << "Tercer Grado de Consanguinidad.(Tios, Sobrinos)" << endl;

        // tios
        Familia *familia = nullptr;

        if(persona->getPapa()!= nullptr && persona->getMama()!= nullptr)
        {
        Persona *papa = persona->getPapa();
        Persona *mama = persona->getMama();

        Familia *desplazaF = cab;



        while (desplazaF != nullptr) {
            Persona *desplazaH = desplazaF->getHijosCab();
            while (desplazaH != nullptr) {
                if (desplazaH->getId() == papa->getId() || desplazaH->getId() == mama->getId()) {
                    familia = desplazaF;
                    desplazaH = desplazaH->getSig();
                } else {
                    desplazaH = desplazaH->getSig();
                }
            }
            desplazaF = desplazaF->getSig();
        }
        }

        if(familia!= nullptr)
        {
        Persona *papa = persona->getPapa();
        Persona *mama = persona->getMama();
        Persona *desplaza = familia->getHijosCab();
        cout << "Tios: " << endl;

        while (desplaza != nullptr)
        {
            if (desplaza->getId() == papa->getId() || desplaza->getId() == mama->getId())
            {
                desplaza = desplaza->getSig();
            }
            else
            {
                cout << desplaza->getNombre() << " " << desplaza->getApellidos();
                if(desplaza->getVivo() == 1)
                    cout << " - vivo" << endl;
                else cout << " - fallecido" << endl;
                desplaza = desplaza->getSig();
            }
        }
        }

        //sobrinos

        Familia *desplazaF2 = cab;
        Familia *familia2 = nullptr;


        while(desplazaF2 != nullptr)
        {
            Persona *desplazaH = desplazaF2->getHijosCab();
            while(desplazaH != nullptr)
            {
                if(desplazaH->getId() == id)
                {
                    familia2 = desplazaF2;
                    desplazaH = desplazaH->getSig();
                }
                else
                {
                    desplazaH = desplazaH->getSig();
                }
            }
            desplazaF2 = desplazaF2->getSig();
        }

        if(familia2!= nullptr)
        {
        bool sobrinos = false;
        Persona *desplaza2 = familia2->getHijosCab();
        cout << endl << "Sobrinos: " << endl;

        while(desplaza2!= nullptr)
        {
            if(desplaza2->getId() == id)
            {
                desplaza2 = desplaza2->getSig();
            }
            else
            {
                cout << "Sobrinos por parte de " << desplaza2->getNombre() << " " << desplaza2->getApellidos() << endl;

                Familia *desplazaF3 = cab;
                while(desplazaF3!= nullptr)
                {
                    if(desplazaF3->getPadre()->getId() == desplaza2->getId() || desplazaF3->getMadre()->getId() == desplaza2->getId())
                    {
                        sobrinos = true;
                        desplazaF3->imprimirNietos2();
                        desplazaF3 = desplazaF3->getSig();
                        cout << endl;
                    }
                    else
                    {
                        desplazaF3 = desplazaF3->getSig();
                    }
                }
                desplaza2 = desplaza2->getSig();
            }
        }

        if(!sobrinos)
        {
            cout << "No tiene sobrinos." << endl;
        }

        cout << endl;
    }
    }

cout << endl;

}

void Arbol::interfazPPal()
{
    int opcion = 0;

            do
            {
                cout << ":::::::::::::::: MENU PRINCIPAL ::::::::::::::::" << endl;
                cout << "-------------- Arbol Genealogico --------------" << endl;
                cout << "1: Nuevo Matrimonio" << endl;
                cout << "2: Nuevo Nacimiento" << endl;
                cout << "3: Fallecimiento" << endl;
                cout << "4: Mostrar todas las familias." << endl;
                cout << "5: Consultar hijos de una persona" << endl;
                cout << "6: Consultar estado civil de una persona." << endl;
                cout << "7: Consultar nietos de una persona." << endl;
                cout << "8: Consultar abuelos de una persona." << endl;
                cout << "9: Consultar padres y hermanos de una persona." << endl;
                cout << "10: Consultar Familiares hasta con tercer grado de consanguinidad." << endl;
                cout << "11: Salir." << endl;

                cout << "Su opcion: " << endl;
                cin >> opcion;
                switch (opcion) {
                    case 1:
                        matrimonio();
                        break;
                    case 2:
                        nacimiento();
                        break;
                    case 3:
                        fallecimiento();
                        break;
                    case 4:
                        imprimir();
                        break;
                    case 5:
                        hijosPersona();
                        break;
                    case 6:
                        estadoCivil();
                        break;
                    case 7:
                        nietosPersona();
                        break;
                    case 8:
                        abuelosPersona();
                        break;
                    case 9:
                        padresHermanosPersona();
                        break;
                    case 10:
                        familiaresHastaTercer();
                        break;
                    default:
                        if (opcion != 11)
                            cout << endl << "=== Opcion no valida ===" << endl;
                }

            } while (opcion != 11);
}