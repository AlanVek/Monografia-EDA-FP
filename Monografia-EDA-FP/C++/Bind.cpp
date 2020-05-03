#include <iostream>
#include "Turn.h"
#include <functional>
using namespace std;
#ifdef TURN10

////Recibe dos números y devuelve su suma.
//int adder(const int& num1, const int& num2) { return num1 + num2; }
//
////Recibe un número y devuelve adder con primer parámetro fijo en num.
//auto HOF(const int& num) {
//	return bind(adder, num, placeholders::_1);
//}
//
//int main() {
//	auto increment = HOF(1);
//
//	auto add5 = HOF(5);
//
//	//Imprime 6.
//	cout << increment(5) << endl;
//
//	//Imprime 10.
//	cout << add5(5) << endl;
//}

//void printer(const int& num1, const int& num2, const function<int(void)>& f) {
void printer(const function<int(int)>& f, int num) {
	cout << f(num) << endl;
	//cout << num1 << num2 << f() << endl;
}

int adder(const int& num1) { return num1 + 10; }

int main() {
	//auto first_fixed = bind(printer, 5, placeholders::_1, placeholders::_2);

	////Imprime 5 1 2.
	//first_fixed(1, 2);

	//auto second_fixed = bind(printer, placeholders::_1, 5, placeholders::_2);

	////Imprime 1 5 2.
	//second_fixed(1, 2, 3, 4);

	//auto all_first = bind(printer, placeholders::_1, placeholders::_1, placeholders::_1);

	////Imprime 1 1 1.
	//all_first(1, 2, 5);

	//auto all_binded = bind(printer, 1, 2, 5);

	////Imprime 1 2 5.
	//all_binded(4, 5, 6, 7);

	//function<void(int,int)> nested = bind(printer, placeholders::_1, placeholders::_2, bind(adder,3));

	function<int(int)> f = bind(adder, 1);

	auto nested = bind(printer, bind(adder, placeholders::_2), placeholders::_1);

	nested(5, 6);
}

#endif