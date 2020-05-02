#include <iostream>
#include <functional>
#include <vector>
#include "Turn.h"

template <class T, typename F>
void apply(T& iter, const F& function) {
	for (auto i = iter.begin(); i != iter.end(); i++)
		*i = function(*i);
}

#ifdef TURN1
using namespace std;
#define CANT 5
#define TEST 5
typedef int (*testfunc)(int);
int main() {
	/*Creamos tres vectores de funciones que reciben un int y devuelven un int.*/
	vector<function<int(int)>> v_value;
	vector<function<int(int)>> v_ref;
	vector<function<int(int)>> v_no_capture;
	int i;
	for (i = 0; i < 4; i++) {
		//Cargamos v_value con lambdas que reciben i por valor.
		v_value.emplace_back([=](int num) {return num + i; });

		//Cargamos v_ref con lambdas que reciben i por referencia.
		v_ref.emplace_back([&](int num) {return num + i; });

		/*No compila, i no está definida.
		v_no_capture.emplace_back([](int num) {return num + i; });*/
	}
	cout << "Value: ";
	for (auto x : v_value)

		//Imprime 5 6 7 8, porque i fue capturado por valor.
		cout << x(5) << ' ';

	cout << endl;
	cout << "\nReference: ";
	for (auto x : v_ref)

		//Imprime 9 9 9 9, porque i fue capturado por referencia.
		cout << x(5) << ' ';

	cout << endl;

	i = 0;

	cout << "\nNew reference: ";
	for (auto x : v_ref)

		//Imprime 5 5 5 5, porque ahora i vale 0.
		cout << x(5) << ' ';

	cout << endl;
}
//
//int add1(int num) { return num + 1; }
//int main() {
//	/*Defino los vectores a aplicarles las funciones.*/
//	std::vector<int> v_function{ 1,2,3,4 };
//	std::vector<int> v_lambda{ 1,2,3,4 };
//
//	//v_function = {2,3,4,5}
//	apply(v_function, add1);
//
//	//v_lambda = {2,3,4,5}
//	apply(v_lambda, [](const int& num) {return num + 1; });
//}
//
#endif