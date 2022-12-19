#include <iostream>
using namespace std;
#define tab "\t"
void FillRand(int arr[], const int n);
void Print(int* arr, const int n);

int* push_back(int* arr, const int& n,int value);
int* push_front(int* arr, const int& n, int value);
void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите количество элементов "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);
	

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	
	Print(arr, n);

	delete[]arr;
	// Memory leak
}
void FillRand(int arr[], const int n)
{
	cout << typeid(arr).name() << endl;
	for (int i = 0; i < n; i++)
	{
		//через арифметику указателей и оператор разыменования
		*(arr + i) = rand() * 100;
	}
}
void Print(int arr[], const int n)
{
	cout << typeid(arr).name() << endl;
	for (int i = 0; i < n; i++)
	{
		//через оператор индексирования
		// [] -оператор индексирования (Subscript operator)
		cout << arr[i] << tab;
	}
	cout << endl;
}
int* push_back(int* arr,int& n, int value)
{
	//Создаем новый массив нужного размера:
	int* buffer = new int[n + 1];
	//2) копируем все содержимое исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) удаляем исходный массив:
	delete[]arr;
	// 4) подменяем адрес в указателе 'arr' адресом нового массива:
	arr = buffer;
	// 5) только после всего этого в конец массива 'arr' можно добавить значение
	arr[n] = value;
	//после добавления в массив 'arr'элемента ,количество его элементов увеличилось
	n++;
	// 7) Mission complete- элемент добавлен!
	return arr;
}
int* push_front(int* arr, const int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n;i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}