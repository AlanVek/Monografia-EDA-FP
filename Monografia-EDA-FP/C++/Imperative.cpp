#include <iostream>
#include "Turn.h"
#include <vector>

#ifdef TURN5
using namespace std;

int main() {
	int value = 0;

	//Lambda que recibe por referencia a value. Equivalente, en este caso, a poner sólo &.
	auto func = [&value](auto& x) {
		cout << x << endl;
		if (value)
			x = x + x;
		return x + x;
	};

	string s = "Hola";
	int num = 3;

	/*Imprime 3.
	res1 = 6. */
	auto res1 = func(num);

	//Modificar value modifica a func.
	value = 1;

	/*Imprime "Hola".
	s = "HolaHola".
	res2 = "HolaHolaHolaHola".*/
	auto res2 = func(s);
}

#endif