#include <iostream>
#include <stdarg.h>
#include "Turn.h"
#include <string>
using namespace std;
#ifdef TURN9

//Recibe letras y devuelve la palabra junta.
string join(int cant, ...) {
	va_list args;
	va_start(args, cant);
	string res;
	for (int i = 0; i < cant; i++) {
		res.append(args);

		va_arg(args, const char*);
	}

	va_end(args);
	return res;
}

int main() {
	//Imprime "Hola".
	cout << join(4, 'H', 'o', 'l', 'a') << ' ';

	//Imprime "Mundo".
	cout << join(5, 'M', 'u', 'n', 'd', 'o') << endl;
}

#endif