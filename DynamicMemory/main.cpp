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
	cout << "������� ���������� ��������� "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);
	

	int value;
	cout << "������� ����������� ��������: "; cin >> value;
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
		//����� ���������� ���������� � �������� �������������
		*(arr + i) = rand() * 100;
	}
}
void Print(int arr[], const int n)
{
	cout << typeid(arr).name() << endl;
	for (int i = 0; i < n; i++)
	{
		//����� �������� ��������������
		// [] -�������� �������������� (Subscript operator)
		cout << arr[i] << tab;
	}
	cout << endl;
}
int* push_back(int* arr,int& n, int value)
{
	//������� ����� ������ ������� �������:
	int* buffer = new int[n + 1];
	//2) �������� ��� ���������� ��������� ������� � ��������:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ������� �������� ������:
	delete[]arr;
	// 4) ��������� ����� � ��������� 'arr' ������� ������ �������:
	arr = buffer;
	// 5) ������ ����� ����� ����� � ����� ������� 'arr' ����� �������� ��������
	arr[n] = value;
	//����� ���������� � ������ 'arr'�������� ,���������� ��� ��������� �����������
	n++;
	// 7) Mission complete- ������� ��������!
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