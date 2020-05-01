#include <iostream>
#include <functional>
#include <vector>
#include "Turn.h"

#ifdef TURN1
using namespace std;
#define CANT 5
#define TEST 5
int main() {
	/*Creamos tres vectores de funciones que reciben un int y devuelven un int.*/
	vector<function<int(int)>> v_value;
	vector<function<int(int)>> v_ref;
	vector<function<int(int)>> v_no_capture;
	int i;
	for (i = 0; i < CANT; i++) {
		v_value.emplace_back([=](int num) {return num + i; }); //Cargamos v_value con lambdas que reciben i por valor.
		v_ref.emplace_back([&](int num) {return num + i; }); //Cargamos v_ref con lambdas que reciben i por referencia.
		//v_no_capture.emplace_back([](int num) {return num + i; }) No compila, i no está definida.
	}
	cout << "Value: ";
	for (auto x : v_value)
		cout << x(TEST) << '\t'; //Imprime las distintas funciones de v_value aplicadas a TEST.

	cout << "\nReference: ";
	for (auto x : v_ref)
		cout << x(TEST) << '\t'; //Imprime siempre el mismo valor, porque i fue tomado por referencia.
	cout << endl;

	i = 0;

	cout << "\nNew reference: ";
	for (auto x : v_ref)
		cout << x(TEST) << '\t';  //Imprime siempre TEST, porque ahora i vale 0.
	cout << endl;
}

#endif