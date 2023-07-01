#include<iostream>
#include<string>
#include "Person.h"
using namespace std;
#define N 10
void sort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i+1; j < n ;j++)
		{
			if (a[i] > a[j])
			{
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}
void print(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}
int main()
{
	int a[N];
	cout << "输入10个数字" << endl;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	print(a, N);
	sort(a, N);
	print(a, N);
	Person p1;
	Person p2( "Person", 20, 'm');
	Person p3;
	p3 = p2;//赋值运算符函数
	Person p4(p2);//拷贝构造函数
	p1.inputData();
	p1.outData();
	cout << p1;
	p2.outData();
	cout << p3;
	p3.inputData();
	p3.outData();
	p4.outData();
	system("pause");
	return 0;
}