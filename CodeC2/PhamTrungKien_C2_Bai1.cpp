//Chuong 2 : Cau truc du lieu co ban - bai 1 - PHAM TRUNG KIEN - Nhom 5 - IT81
#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX 100
int a[MAX];
int n;

void nhap(int a[], int& n)
{
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	cout << "Nhap cac phan tu: ";
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
}

void xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " \t";
	}
	cout << endl;
}

int tim(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
	{
		i++;
		if (i == n)
			return -1;
	}
		return i;
}

int chen(int a[], int& n, int x)
{
	if (n < MAX)
	{
		a[n] < x;
		n++;
		return 1;
	}
	else
		return i;
}

int xoaCuoiDS(int a[], int& n)
{
	if (n > 0)
	{
		n--;
		return 1;
	}
	return 0;
}

int xoa(int a[], int& n, int i)
{
	if (i >= 0 && i <= n)
	{
		for (int j = i; j < n - 1; j++)
		{
			a[j] = a[j + 1];
		}
	n--;
	return 1;
	}
	return 0;
}

int main()
{
	int i, x;
	nhap(a, n);
	xuat(a, n);
	cout << "Nhap so can tim: ";
	cin >> x;
	i=tim(a, n, x);
	if (i == -1)
		cout << "Khong tim thay!" << endl;
	else
		cout << "Tim thay " << x << " tai vi tri " << i << endl;
	cout << "Nhap so can them vao cuoi: ";
	cin >> x;
}