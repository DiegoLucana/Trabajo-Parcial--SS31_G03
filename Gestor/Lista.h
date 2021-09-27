#pragma once
#include <iostream>
#include <cstdlib>
#include <functional>
using namespace std;
template <typename Tipo>
struct Nodo {
    Tipo elemento;
    Nodo<Tipo>* siguiente;
    Nodo(Tipo e) { elemento = e; siguiente = nullptr; }
};
template <typename Tipo>
class Lista {
    Nodo<Tipo>* inicio;
    Nodo<Tipo>* fin;
public:
    Lista() {
        It = fin = inicio = nullptr;
    }
    Nodo<Tipo>* It;              // Iterador
    void insertar(Tipo e) {      // Insercion al final O(1)
        Nodo<Tipo>* n = new Nodo<Tipo>(e);
        if (inicio == nullptr)
            It = inicio = fin = n;
        else {
            fin->siguiente = n;
            fin = n;
        }
    }
    void mostrar() {
        Nodo<Tipo>* aux = inicio;
        while (aux->siguiente != nullptr) {
            cout << aux->elemento << " ";
            aux = aux->siguiente;
        }
        cout << aux->elemento << " ";
    }          // { 1, 2, 3, 4, 5} 

    void iterar() { if (It->siguiente != nullptr) It = It->siguiente; else It = inicio; }//Funciona como un aux, cuando llega al final regresa al inicio
    void resetit() { It = inicio; }         // Reinicia la posicon del iterador al comienzo
    Tipo getIt() { return It->elemento; }   // Obtienes el Archivo en la posicion del iterador
    Tipo getFin() { return fin->elemento; } // Obtienes el Archivo en la ultima posicion
};