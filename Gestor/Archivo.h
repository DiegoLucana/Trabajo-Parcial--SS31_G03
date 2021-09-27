#pragma once
#include "Helper.h"
class Archivo {
	string nArch;
    string Comentario;
public:
    Archivo(string a, string c = " ") :nArch(a), Comentario(c) {
        ofstream arch("Archivos/Archivos de Usuarios/" +a + ".txt"); //Cuando se crea un objeto Archivo, se crea el txt correspondiente
    }
    ~Archivo(){}
    string getnarch() { return nArch; }
    string getCom() { return Comentario; }
    // ----Abrir Archivo ----
    void abrirArch() {
        system("cls");
        cout << "Imprimiendo contenidos del archivo " << nArch<< ".txt" << endl;
        cout << "Comentario: " << Comentario << endl;
        string linea, texto;
        ifstream archivo(nArch + ".txt");
        while (getline(archivo, linea))
        {
            texto = texto + linea;
        }
        cout << texto;
        cin.get();
    }
    // ---- Modificar Comentario ----
	void modComentario() {
        Comentario = l1("Ingrese su comentario (el antiguo comentario sera borrado): ");
	}
    // ----Modificar Archivo -----
    void modArch() {
        fstream archivo;
        archivo.open(nArch + ".txt", ios::app);
        archivo << "\n" + l1("Ingrese el nuevo contenido para el archivo: \n");
    }
    void menu() {
        int opcion;
        bool run = true;
        while (run)
        {
            system("cls");
            cout << "Nombre del archivo: " << nArch << endl;
            cout << "Comentario: " << Comentario << endl << endl;
            cout << "1. - Leer archivo" << endl;
            cout << "2. - Modificar comentario" << endl;
            cout << "3. - Modificar archivo" << endl;
            cout << "4. - Regresar" << endl;
            cin >> opcion;
            switch (opcion)
            {
            case 1: {
                abrirArch();
                cin.get();
                break; }
            case 2: {
                modComentario();
                break; }
            case 3: {
                modArch();
                break; }
            case 4: {
                run = false;
                break; }
            }
        }
    }
};