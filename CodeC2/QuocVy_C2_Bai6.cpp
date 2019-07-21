#include<iostream>
using namespace std;
#define MAX 100
int a[MAX];
int sp;
void init(int a[], int &sp)
{
	sp = -1;
}
int push(int a[], int &sp, int x)
{
	if (sp < MAX - 1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}
int pop(int a[], int &sp, int &x)
{
	if (sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}
int isfull(int a[], int sp)
{
	if (sp == MAX - 1)
		return 1;
	return 0;
}
int isempty(int a[], int sp)
{
	if (sp == -1)
		return 1;
	return 0;
}
void xuat(int a[], int sp)
{
	for (int i = sp; i >= 0; i--)
		cout << a[i] << endl;
}
void xuat2(int a[], int sp)
{
	for (int i = 0; i <= sp; i++)
		cout << a[i] << endl;
}
int nhiPhan(int so)
{
	init(a, sp);
	int np = 0;
	while (so != 0)
	{
		int du = so % 2;
		if (push(a, sp, du))
			so /= 2;
		else
			break;
	}
	while (!isempty(a, sp))
	{
		int x;
		if (pop(a, sp, x))
			np = np * 10 + x;
		else
			break;
	}
	return np;
}
int main()
{
	int x, t, chon, n;
	char tt;
	do{
		cout << "\nNhap chon: " << endl;
		cout << "1.khoi tao " << endl;
		cout << "2.kiem tra rong " << endl;
		cout << "3.kiem tra day " << endl;
		cout << "4.them 1 phan tu " << endl;
		cout << "5.xoa 1 phan tu " << endl;
		cout << "6.doi 1 so thap phan sang nhi phan " << endl;
		cout << "7.xuat danh sach " << endl;
		cout << "Chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			init(a, sp);
			cout << "Khoi tao danh sach thanh cong " << endl;
			break;
		case 2:
			if (isempty(a, sp) != 0)
				cout << "Danh sach rong " << endl;
			else
				cout << "Danh sach khong rong " << endl;
			break;
		case 3:
			if (isfull(a, sp) != 0)
				cout << "Danh sach day " << endl;
			else
				cout << "Danh sach chua day " << endl;
			break;
		case 4:
			cout << "Nhap gia tri muon them: ";
			cin >> x;
			t = push(a, sp, x);
			if (t != 0)
				cout << "Them thanh cong! " << endl;
			else
				cout << "Stack day khong the them! " << endl;
			break;
		case 5:
			t = pop(a, sp, x);
			if (t != 0)
				cout << "Phan tu lay ra co gia tri" << x <<  endl;
			else
				cout << "Stack rong! " << endl;
			break;
		case 6:
			cout << "Nhap gia tri can doi nhi phan: ";
			cin >> n;
			cout << "So sau khi chuyen sang nhi phan la: ";
			cout << nhiPhan(n) << endl;
			break;
		case 7:
			cout << "Danh sach cua stack: " << endl;
			xuat(a, sp);
			break;
		default:
			cout << "Gia tri chon khong hop le! " << endl;
			break;
		}
		cout << "Ban muon tiep tuc khong(Y/N):";
		cin >> tt;
	} while (tt == 'y' || tt == 'Y');
	return 0;
}