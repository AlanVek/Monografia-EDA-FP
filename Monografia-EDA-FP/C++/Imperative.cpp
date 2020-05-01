#include <iostream>
#include "Turn.h"
#include <vector>

#ifdef TURN5
using namespace std;

int main() {
	int value = 0;
	auto func = [&value](auto& x) {		//Recibe por referencia a value. Equivalente, en este caso, a poner sólo &.
		cout << x << endl;
		if (value)
			x = x + x;
		return x + x;
	};

	string s = "Hola";
	int num = 3;

	auto res1 = func(num);	//Imprime 3 y devuelve 6.

	value = 1;
	auto res2 = func(s);	//Imprime "Hola", modifica a s para que valga "HolaHola" y devuelve "HolaHolaHolaHola".

	cout << "num is: " << num << endl;	//Imprime 3.

	cout << "s is: " << s << endl;		//Imprime "HolaHola".

	cout << "first result is: " << res1 << endl;	//Imprime 6.
	cout << "second result is: " << res2 << endl;	//Imprime "HolaHolaHolaHola".
}

#endif