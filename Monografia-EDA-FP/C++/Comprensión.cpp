#include <vector>
#include <iostream>
#include <list>
#include "Turn.h"
using namespace std;
#ifdef TURN8

template <class T, typename F>
T for_every(const T& itr, const F& func) {
	T res = itr;

	for (auto i = res.begin(); i != res.end(); i++)
		*i = func(*i);

	return res;
}
template <class T>
vector<T> operator+ (const vector<T>& first, const vector<T>& second) {
	auto res = first;
	for (T x : second)
		res.emplace_back(x);
	return res;
}
template <class T>
void operator+= (vector<T>& first, const vector<T>& second) {
	auto temp = second;
	for (T x : temp)
		first.emplace_back(x);
}

int main() {
	vector<int> v{ 1,2,3,4 };
	list <int> l{ 1,2,3,4 };

	auto v_comp = for_every(v, [](const int& n) {if (n % 2)return n + 1; else return 0; });
	auto l_comp = for_every(l, [](const int& n) {return n * n; });
	v += v;
	auto c = v;

	for (auto x : c)
		cout << x << ' ';
	cout << endl;
}

#endif