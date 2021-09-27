#pragma once
#include "Usuarios.h"
template <typename Tipo>
class Controladora {
	Lista<Tipo*> U;
public:
	Controladora() {}
	~Controladora() {}

	void CrearUsuario(string a ="") {
		if (a != "") U.insertar(new Tipo(a));
		else {
			string uname;
			uname = l1("Ingrese nombre del nuevo usuario");
			U.insertar(new Tipo(uname));
		}
	}
	void CargarUsuarios() {
		string linea;
		ifstream arch("Archivos/Usuarios/Usuarios.txt");
		while (getline(arch,linea))
		{
			U.insertar(new Tipo(linea));
		}
	}
	void GuardarUsuarios() {
		ofstream arch("Archivos/Usuarios/Usuarios.txt");
		while (U.It->siguiente != nullptr)
		{
			arch << U.getIt()->getname() << "\n";
			U.iterar();
		}arch << U.getFin()->getname();
	}
	void SelecUsuario() {
		U.resetit();
		string temp = l1("\nIngresar nombre del usuario a seleccionar : ");
		while (U.It->siguiente != nullptr)
		{
			if (U.getIt()->getname() == temp) { U.getIt()->menuUser(); break; }
			U.iterar();
		} if (U.getFin()->getname() == temp) U.getFin()->menuUser();
	}
	void menu() {
		bool run = true;
		short opcion;
		while (run)
		{
			system("cls");
			cout << " || BIENVENIDO ||" << endl;
			cout << "1. - Crear nuevo usuario" << endl;
			cout << "2. - Seleccionar usuario " << endl;
			cout << "3. - Salir" << endl;
			cin >> opcion;

			switch (opcion)
			{
			case 1: {
				CrearUsuario();
				break; }
			case 2: {
				SelecUsuario();
				break;
			}
			case 3: {
				GuardarUsuarios();
				run = false;
				break;
			}
			}
		}
	}



};