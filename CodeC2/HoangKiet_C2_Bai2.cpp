#include <iostream>
using namespace std;
#define MAX 100
int a[MAX];
int sp;

void nhap(int a[], int sp)
{
	cout << "Nhap cac phan tu trong danh sach: ";
	for (int i = 0; i < sp; i++)
	{
		cin >> a[i];
	}
	cout << endl;
}
void xuat(int a[], int sp)
{
	cout << "Danh sach vua nhap vao: \n";
	for (int i = 0; i < sp; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}

void them(int a[], int sp, int x)
{
	int t = rand() % sp + 1;
	a[t] = x;
	sp++;
	for (int i = t + 1; i < sp; i++)
	{
		a[i + 1] = a[i];
	}
}
int timTT(int a[], int sp, int x)
{
	int i = 1;
	while (i < sp && a[i] != x)
	{
		i++;
	}
	if (i == sp)
	{
		return 0;
	}
	return i;
}
int timNP(int a[], int sp, int x)
{
	int left = 0, right = sp - 1;
	
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (a[mid]==x)
		{
			return mid;
		}
		else
		{
			if (a[mid] < x)
			{
				left = mid + 1;
			}
			else
			{
				right = mid + 1;
			}
		}
	}
	return -1;
}
int tim(int a[], int sp, int x)
{
	int i = 0;
	while (a[i] != x && i < sp)
	{
		i++;
	}
	return i;
}
void timvaxoa(int a[], int sp, int x)
{
	int t = tim(a, sp, x);
	for (int i = t; i < sp; i++)
	{
		a[i] = a[i + 1];
	}
}

int main()
{
	int x, tam;
	cout << "Nhap so luong phan tu: ";
	cin >> sp;
	nhap(a, sp);
	xuat(a, sp);
	cout << "1.Them phan tu.\n ";
	cout << "2.Tim kiem bang PP Tuan Tu.\n";
	cout << "3.Tim kiem bang PP Nhi Phan.\n";
	cout << "4.Tim phan tu va xoa do.\n";
	cout << "5.Thoat.\n";
	int chon;
	cout << "Ban chon: ";
	cin >> chon;
	cout << endl;
	switch (chon)
	{
	case 1:
		cout << "Nhap phan tu them: ";
		cin >> x;
		them(a, sp, x);
		xuat(a, sp);
		break;
	case 2:
		cout << "Chon phan tu de tim kiem: ";
		cin >> x;
		tam = timTT(a, sp, x);
		if (tam == 0)
		{
			cout << "Khong tim thay x" << endl;
		}
		else
		{
			cout << "Tim thay vi tri i = " << tam + 1 << endl;
		}
		break;
	case 3:
		cout << "Chon phan tu de tim kiem: ";
		cin >> x;
		tam = timNP(a, sp, x);
		if (tam == -1)
		{
			cout << "Khong tim thay \n";
		}
		else
		{
			cout << "Tim thay phan tu vi tri i = " << tam + 1 << endl;
		}
		break;
	default:
		cout << "Nhap phan tu tim kiem va xoa khoi danh sach: ";
		cin >> x;
		timvaxoa(a, sp, x);
		xuat(a, sp);
		break;
	}

	system("pause");
	return 0;
}