#pragma once
#include "Lista.h"
#include "Archivo.h"
class Usuario {
	string nombre;
	Lista<Archivo*> arch;
public:
	Usuario(string n):nombre(n){}
	~Usuario(){}

    string getname() { return nombre; }
    void crearArch(string a = "", string b ="") {      //Creacion de objeto archivo
        if (a != "" && b != "") {
            arch.insertar(new Archivo(a, b));
        }
        else {
            string archname, archcom;
            archname = l1("Ingrese el nombre de su nuevo archivo: ");
            archcom = l1("Ingrese un comentario para su nuevo archivo: ");
            arch.insertar(new Archivo(archname, archcom));
        }
    }
	void mostrarArchivos(){     //Uso de Iterador, va mostrando los nombres de los archivos que recorre
        while (arch.It->siguiente != nullptr)
        {
            cout << "\t" << arch.getIt()->getnarch()<<endl;
            arch.iterar();
        }
        cout << "\t" << arch.getIt()->getnarch() << endl;
        arch.iterar();        
    }
    void menuUser() {       //Aqui se me desordenó todo un poco
        int opcion;
        bool run = true;
        while (run)
        {
            system("cls");
            cout << "Bienvenido " << nombre << "\n \nEstos son sus archivos: " << endl;
            if (arch.It != nullptr) mostrarArchivos();
            cout << "1. - Crear nuevo archivo" << endl;
            cout << "2. - Seleccionar archivo " << endl;
            cout << "3. - Filtrar" << endl;
            cout << "4. - Salir" << endl;
            cin >> opcion;
            switch (opcion)
            {
            case 1: {
                crearArch();
                break; }
            case 2: {
                string aux;
                aux = l1("\nEscriba el nombre del archivo a seleccionar: \n"); cout << endl;
                while (arch.It->siguiente != nullptr)
                {
                    if (l2(aux, arch.getIt()->getnarch())) { 
                        arch.getIt()->menu();
                        break;
                    }
                    else arch.iterar();
                }
                if (l2(aux, arch.getFin()->getnarch())) arch.getFin()->menu();
                else cout << "\nNombre de archivo no valido";
                arch.resetit();
                break; }
            case 3: {
                Filtrado();
                break; }
            case 4: {
                run = false;
                break; }
            }
        }
    }
	//------FILTRADO DE ARCHIVOS-----------

	void Filtrado() {
        int opcion;
        bool run = true;
        while (run)
        {
            cout << "\nSeleccione el filtro a aplicar: " << endl;
            cout << "1. - Igual a" << endl;
            cout << "2. - Inicia con" << endl;
            cout << "3. - Finaliza con" << endl;
            cout << "4. - Esta contenido en" << endl;
            cout << "5. - No esta contenido en" << endl;
            cout << "6. - Regresar" << endl;
            cin >> opcion;                
            arch.resetit();
            switch (opcion)
            {
            case 1: {
                string aux;
                aux = l1("\nEscriba el nombre del archivo a buscar: \n"); cout << endl;
                while (arch.It->siguiente != nullptr)
                {
                    if (l2(aux, arch.getIt()->getnarch())) {
                        cout << "\t" << arch.getIt()->getnarch() << endl;
                    }
                    arch.iterar();
                }
                if (l2(aux, arch.getFin()->getnarch())) cout << "\t" << arch.getFin()->getnarch() << endl;
                else cout << "\nNombre de archivo no valido";

                break; }
            case 2: {
                string aux;
                aux = l1("\nEl nombre del archivo inicia con: \n"); cout << endl;
                while (arch.It->siguiente != nullptr)
                {
                    if (l3(arch.getIt()->getnarch(), aux)) {                        
                        cout << "\t" << arch.getIt()->getnarch() << endl;
                    }
                    arch.iterar();
                }
                if (l3(arch.getFin()->getnarch(), aux)) cout << "\t" << arch.getFin()->getnarch() << endl;
                else cout << "\nNombre de archivo no valido";
                break; }
            case 3: {
                arch.resetit();
                string aux;
                aux = l1("\nEl nombre del archivo termina con: "); cout << endl;
                while (arch.It->siguiente != nullptr)
                {
                    if (l4(arch.getIt()->getnarch(), aux))
                    {
                        cout << "\t" << arch.getIt()->getnarch() << endl;
                    }
                    arch.iterar();
                }
                if (l4(arch.getFin()->getnarch(), aux)) cout << "\t" << arch.getFin()->getnarch() << endl;
                else cout << "\nNombre de archivo no valido";
                break; }
            case 4: {
                arch.resetit();
                string aux;
                aux = l1("\nEl nombre del archivo contiene: "); cout << endl;
                while (arch.It->siguiente != nullptr)
                {
                    if (l5(arch.getIt()->getnarch(), aux))
                    {
                        cout << "\t" << arch.getIt()->getnarch() << endl;
                    }
                    arch.iterar();
                }
                if (l5(arch.getFin()->getnarch(), aux)) cout << "\t" << arch.getFin()->getnarch() << endl;
                else cout << "\nNombre de archivo no valido";
                break; }
            case 5: {
                arch.resetit();
                string aux;
                aux = l1("\nEl nombre del archivo no contiene: "); cout << endl;
                while (arch.It->siguiente != nullptr)
                {
                    if (!(l5(arch.getIt()->getnarch(), aux)))
                    {
                        cout << "\t" << arch.getIt()->getnarch() << endl;
                    }
                    arch.iterar();
                }
                if (!l5(arch.getFin()->getnarch(), aux)) cout << "\t" << arch.getFin()->getnarch() << endl;
                else cout << "\nNombre de archivo no valido";
                break; }
            case 6: {
                run = false;
                break; }
            }
        }
	}
    };