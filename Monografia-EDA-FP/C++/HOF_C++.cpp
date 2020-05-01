#include <iostream>
#include <vector>
#include <array>
#include "Turn.h"

#ifdef TURN2
using namespace std;

template <class T>
void print_iter(const T& iter) {
	for (auto x : iter)
		cout << x << '\t';
	cout << endl;
}

template<class T, typename F>
T apply_copy(const T& iter, const F& func) {
	T temp = iter;
	for (auto i = temp.begin(); i != temp.end(); i++)
		*i = func(*i);
	return temp;
}

template<class T, typename F>
void apply(T& iter, const F& func) {
	for (auto i = iter.begin(); i != iter.end(); i++)
		*i = func(*i);
}

int main() {
	vector<int> v{ 1,2,3 };

	auto temp = apply_copy(v, [](int num) {return num + 1; }); //Devuelve un vector con los números de v incrementados en 1.
	print_iter(temp);

	array<int, 3> arr{ 5,6,7 };
	apply_inplace(arr, [](int num) {return num * 2; }); //Multiplica por dos a los valores de arr.

	print_iter(arr);
}

#endif