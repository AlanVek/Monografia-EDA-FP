#include <iostream>
#include "Turn.h"
#include <vector>
#include <chrono>
#include <functional>
#ifdef TURN4
template<class T, typename F>
void apply(T& iter, const F& func) {
	for (auto i = iter.begin(); i != iter.end(); i++)
		*i = func(*i);
}

int add1(int num) {
	return num + 1;
}

#define MAXVAL 200
#define REP 1000
using namespace std::chrono;
int main() {
	long long timeTaken = 0;

	//Lambda function to apply.
	std::function<int(int)> factorial = [&](int num) {if (num <= 1) return num; else return num * factorial(num - 1); };

	for (int j = 0; j < REP; j++) {
		auto start = steady_clock::now();	//Empieza el timer.
		for (int i = 0; i < MAXVAL; i++)
			factorial(i);

		auto end = steady_clock::now();		//Termina el timer.

		timeTaken += duration_cast<microseconds> (end - start).count();	//Suma el tiempo que tardó a timeTaken.
	}

	std::cout << "Time taken (microseconds): " << timeTaken / REP << std::endl;	//Imprime el promedio de tiempo. (Alrededor de 7,5seg).
}

#endif