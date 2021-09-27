#pragma once
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <functional>
using namespace std;

// Lambda le das texto y devuelve el input
auto l1 = [](string s) {cin.get(); cout << endl << s << endl;
getline(cin,s); 
return s;
};
// Lambda de comparación
auto l2 = [](string a, string b) { return  a == b ? true : false; };
// Lambda de busqueda al inicio
auto l3 = [](string a, string b) { return  a.rfind(b, 0) == 0 ? true:false; };
				// a = "Ornitorrinco" b = "Orni"
// Lambda de busqueda desde el final
auto l4 = [](string a, string b) { return (0 == a.compare(a.length() - b.length(), b.length(), b)); };
// Lambda de busqueda 
auto l5 = [](string a, string b) { return a.find(b) != string::npos ? true : false; };