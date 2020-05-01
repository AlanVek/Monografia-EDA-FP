#include "Turn.h"
#ifdef TURN3
#include <iostream>

using namespace std;
int factorial_recursivo(int num) {
	if (num <= 1)
		return 1;

	return num * factorial_recursivo(num - 1);
}

int factorial(int num) {
	int tot = 1;

	for (int i = 2; i <= num; i++)
		tot *= i;
	return tot;
}

int main() {
	cout << factorial_recursivo(6) << endl;
	cout << factorial(6) << endl;
}

#endif