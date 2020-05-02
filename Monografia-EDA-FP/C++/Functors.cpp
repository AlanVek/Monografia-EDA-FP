#include <iostream>
#include <vector>
#include "Turn.h"
using namespace std;
#ifdef TURN7
template <class T, typename F>
void apply(T& iter, const F& func) {
	for (auto i = iter.begin(); i != iter.end(); i++)
		*i = func(*i);
}

//Functor.
template<typename T>
class Adder {
public:
	Adder(const T& num_) : num(num_) {};

	T operator()(const T& nn) const { return nn + num; }

private:
	T num;
};

int increment(int num) { return num + 1; }

int main() {
	vector<int> v{ 1,2,3,4 };

	//v = {2,3,4,5}
	//apply(v, increment);

	apply(v, Adder<float>(1.2));			//Suma uno a cada elemento de v. Ahora v = {2,3,4,5,6}

	apply(v, Adder<int>(5));			//Suma cinco a cada elemento de v. Ahora v = {7,8,9,10,11}

	//for (auto x : v) {
	//	cout << x << endl;
	//}
}

#endif