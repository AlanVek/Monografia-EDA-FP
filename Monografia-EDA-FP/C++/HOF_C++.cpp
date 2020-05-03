#include <iostream>
#include <vector>
#include <array>
#include "Turn.h"
#include <functional>

#ifdef TURN2
using namespace std;

//template <class T>
//void print_iter(const T& iter) {
//	for (auto x : iter)
//		cout << x << '\t';
//	cout << endl;
//}
//
//template<class T, typename F>
//T apply_copy(const T& iter, const F& func) {
//	T temp = iter;
//	for (auto i = temp.begin(); i != temp.end(); i++)
//		*i = func(*i);
//	return temp;
//}
//
template<class T, typename F>
void apply(T& iter, const F& func) {
	for (auto i = iter.begin(); i != iter.end(); i++)
		*i = func(*i);
}
//
//int main() {
//	vector<int> v{ 1,2,3 };
//
//	auto temp = apply_copy(v, [](int num) {return num + 1; }); //Devuelve un vector con los números de v incrementados en 1.
//	print_iter(temp);
//
//	array<int, 3> arr{ 5,6,7 };
//	apply_inplace(arr, [](int num) {return num * 2; }); //Multiplica por dos a los valores de arr.
//
//	print_iter(arr);
//}

//auto print = [](const auto& iter) {for (auto x : iter)cout << x << ' '; cout << endl; };
//
//int main() {
//	/*Función que recibe un parámetro y devuelve una función que recibe un parámetro
//	y devuelve la suma del parámetro nuevo y el original.*/
//	auto HOF = [](const auto& adder) {return [&](const auto& changeable) {return changeable + adder; }; };
//
//	vector<int> v{ 1,2,3,4 };
//
//	int num = 1;
//	//v = {2,3,4,5}. Sumó 1.
//	auto increment = HOF(num);
//	apply(v, increment);
//	print(v);
//
//	num = 4;
//	//v = {7,8,9,10}. Sumó 5.
//	apply(v, increment);
//	print(v);
//}

//Adder recibe dos enteros y devuelve su suma.
int adder(const int& num1, const int& num2) { return num1 + num2; }

typedef int(*function_ints) (const int&);

/*HOF recibe un entero (num) y devuelve adder con el primer
parámetro fijado en num.*/
function_ints HOF(const int& num) {
	function<int(const int&)> temp_func = [](const int& num) {return num + 1; };

	/*No compila, porque no hay conversión definida entre
	function<int(const int&)> y function_ints.*/
	return temp_func;
}

int main() {
	auto increment = HOF(1);
	auto add5 = HOF(5);

	//Imprime 5.
	cout << increment(4) << endl;

	//Imprime 9.
	cout << add5(4) << endl;
}

#endif