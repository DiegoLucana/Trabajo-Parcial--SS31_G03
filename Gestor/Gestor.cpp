#include "pch.h"
#include <iostream>
#include <fstream>
#include "string"
#include "Controladora.h"

using namespace System;
using namespace std;

int main()
{
   // cout << l1("Ingrese su nombre: ");
   // abrir();
   // menu();
   // Usuario* u = new Usuario("Pedro");
    Controladora<Usuario>* c = new Controladora<Usuario>();
    c->CargarUsuarios();
    c->menu();
   // Archivo* a = new Archivo("hola","adios");
    //cout << a->getnarch() << endl;
   // a->modArch();
    //a->modArch();
    //cout << a->getCom();
   // a->menu();
    //u->crearArch();
    //u->crearArch();
    //u->crearArch();
    //u->crearArch();
    //u->mostrarArchivos();
    //u->Filtrado();
    //u->menuUser();
    //string a1, b1;
    //a1 = "Carlos"; b1 = "a";
    ////if (l4(a1, b1)) cout << "Funciona";
    ////else cout << "No funciona";
    //if (l5(a1, b1)) cout << "Funciona";
    //else cout << "No Funciona";

    system("pause");
    return 0;
}
