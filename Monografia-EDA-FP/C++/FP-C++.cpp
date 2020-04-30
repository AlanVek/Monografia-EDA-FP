#include <iostream>
#include <functional>
#include <vector>
using namespace std;
#define CANT 5
#define TEST 5
int main() {
	/*Creamos tres vectores de funciones que reciben un int y devuelven un int.*/
	vector<function<int(int)>> v_value;
	vector<function<int(int)>> v_ref;
	vector<function<int(int)>> v_no_capture;
	int i;
	for (i = 0; i < CANT; i++) {
		v_value.emplace_back([=](int num) {return num + i; }); //Cargamos v_value con lambdas que reciben i por valor.
		v_ref.emplace_back([&](int num) {return num + i; }); //Cargamos v_ref con lambdas que reciben i por referencia.
		//v_no_capture.emplace_back([](int num) {return num + i; }) No compila, i no está definida.
	}
	cout << "Value: ";
	for (auto x : v_value)
		cout << x(TEST) << '\t'; //Imprime las distintas funciones de v_value aplicadas a TEST.

	cout << "\nReference: ";
	for (auto x : v_ref)
		cout << x(TEST) << '\t'; //Imprime siempre el mismo valor, porque i fue tomado por referencia.
	cout << endl;

	i = 0;

	cout << "\nNew reference: ";
	for (auto x : v_ref)
		cout << x(TEST) << '\t';  //Imprime siempre TEST, porque ahora i vale 0.
	cout << endl;
}

//using tt = chrono::steady_clock;
//
//template <class T>
//void print2(T& iter) {
//	for (auto x : iter)
//		cout << x << '\t';
//	cout << endl;
//}
//
//template<class T, typename F>
//T apply2(T& iter, const F& func) {
//	T temp = iter;
//	for (auto i = temp.begin(); i != temp.end(); i++)
//		*i = func(*i);
//	return temp;
//}
//
//auto add1 = [](auto& num) {return num + 1; };
//auto retfunc(int num) {
//	return [=](int num2) {return num + num2; };
//}
//
//class functor {
//public:
//
//	functor(void) {};
//	auto operator () (int num) {
//		return [=](int num2) {return num + num2; };
//	}
//};
//template <class T>
//class v2 : public vector<T> {
//public:
//	v2() : vector<T>() {}
//	v2(T* args) : vector<T>(args) {};
//	v2(T& args) : vector<T>(args) {};
//	v2(T args) : vector<T>(args) {};
//	v2(vector<T> args) : vector<T>(args) {};
//
//	template <typename F>
//	void apply(F& func) {
//
//		for (auto i = this->begin(); i != this->end(); i++)
//			func(*i);
//
//	}
//};
//
//int main() {
//	vector<int> v{ 1,2,3 };
//
//	auto apply = [](auto& vect, auto& func, bool inpl = false)
//	{
//		if (inpl) {
//			for (auto j = vect.begin(); j != vect.end(); j++)
//				*j = func(*j);
//			return vect;
//		}
//		else {
//			auto temp = vect;
//			for (auto i = temp.begin(); i != temp.end(); i++)
//				*i = func(*i);
//			return temp;
//		}
//	};
//
//	/*auto temp = apply(v, add1_2, false);
//	print_2(temp);
//	print_2(v);*/
//	for (auto x : v) {
//		v = apply2(v, [](auto value) {return value * 3; });
//		print2(v);
//	}
//	//auto print = [](auto& iter) {for (auto x : iter) cout << x << '\t'; cout << endl; };
//
//	//auto add1 = [](auto& num) {num++; };
//
//	//vector<int> vect{ 1,2,3 };
//	//array<int, 3> arr{ 5,6,7 };
//
//	//auto start = tt::now();
//	//cout << "Original vector values: " << endl;
//	//print(vect);
//	//apply(vect, add1);
//	//cout << "\nNew vector values: " << endl;
//	//print(vect);
//	//cout << "\nOriginal array values:\n";
//	//print(arr);
//
//	//apply(arr, add1);
//
//	//cout << "\nNew array values:\n";
//	//print(arr);
//	//auto end = tt::now();
//	////cout << "\nFP time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << endl;
//
//	//start = tt::now();
//	//cout << "Original vector values: " << endl;
//	//print_2(vect);
//	//apply_2(vect, add1_2);
//	//cout << "\nNew vector values: " << endl;
//	//print_2(vect);
//	//cout << "\nOriginal array values:\n";
//	//print_2(arr);
//
//	//apply_2(arr, add1_2);
//
//	//cout << "\nNew array values:\n";
//	//print_2(arr);
//	//end = tt::now();
//
//	//cout << "\nTemplate time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << endl;
//
//	/*vector<function<int(int)>> vf_value;
//	vector<function<int(int)>> vf_reference;
//
//	int i;
//	for (i = 0; i < 5; i++)
//		vf_value.emplace_back([=](int a) {return a + i; });
//
//	for (i = 0; i < 5; i++)
//		vf_reference.emplace_back([&](int a) {return a + i; });
//
//	for (auto x : vf_value)
//		cout << x(4) << '\t';
//	cout << endl;
//	for (auto x : vf_reference)
//		cout << x(4) << '\t';*/
//}