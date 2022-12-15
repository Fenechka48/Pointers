#include <iostream>
using namespace std;

using std::cin;
using std::cout;
using std::cin;

//#define POINTERS
void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello Pointers" << endl;
#ifdef POINTERS
	int a = 2;
	int* pa = &a; //pointer to a
	cout << a << endl; // взятие переменной а
	cout << &a << endl; // взятие адреса переменнопрямо при выводе < endl;
	cout << pa << endl; // вывод адреса переменнорй а, хранящегося в указателе ра
	cout << *pa << endl; //hfpsvtyjdfybt erfpfntkz hf b dsdjl y f'rhfy pyfxtybz gj flhtce 
#endif //Pointers

	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + 1) << "\t";
	}
	cout << endl;
}
