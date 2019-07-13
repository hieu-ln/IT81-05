#include <iostream>
using namespace std;
#define MAX 100
int sp;

void rong(int a[], int &sp)
{
	sp = -1;
}
int kiemtra(int a[], int sp)
{
	if (sp ==-1)
	{
		return 1;
	}
	return 0;
}
int day(int a[], int sp)
{
	if (sp ==MAX - 1)
	{
		return -1;
	}
	return 1;
}
int them(int a[], int &sp, int x)
{
	if (sp < MAX -1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}
int xoa(int a[], int &sp, int &x)
{
	if (sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}
void xuat(int a[], int n)
{
	cout << "Danh sach xuat ra:" << endl;
	for (int i=0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
}
void nhap(int a[], int n)
{
	cout << "Nhap danh sach vao:";
	for (int i=0; i < n; i++)
	{
		cin >> a[i];
	}
}

int main()
{
	int a[MAX];
	int chon = 0;
	int n;
	int x, i;
	do
	{
	cout << "So luong phan tu trong danh sach: ";
	cin >> n;
	system("cls");
	
		cout << endl;
	cout << "1.Nhap cac phan tu trong danh sach: \n";
	cout << "2.Xuat danh sach: \n";
	cout << "3.Khoi tao danh sach rong: \n";
	cout << "4.Kiem tra danh sach rong: \n";
	cout << "5.Kiem tra danh sach day: \n";
	cout << "6.Them phan tu vao trong danh sach: \n";
	cout << "7.Xoa phan tu trong danh sach: \n";
	cout << "8.Thoat\n";
	
	cout << "Ban chon muc nao: " << endl;
	cin >> chon;

	system("pause");
	system("cls");
	switch (chon)
	{
	case 6:
		cout << "Nhap them phan tu: ";
		cin >> x;
		cout << "Danh sach them: " << endl;
		i = them(a, sp, x);
		xuat(a, sp);
		break;
	case 1:
		nhap(a, n);
		break;
	case 2:
		xuat(a, n);
		break;
	case 3:
		cout << "Thanh cong.\n";
		break;
	case 4:
		i = kiemtra(a, n);
		if (i == 1)
		{
			cout << "Danh sach rong\n";
		}
		else
		{
			cout << "Danh sach co phan tu\n";
		}
		break;
	case 5:
		i = day(a, n);
		if (i == -1)
		{
			cout << "Danh sach day\n";
		}
		else
		{
			cout << "Danh sach chua day\n";
		}
		break;

	default:
		cout << "Nhap pha tu xoa:";
		cin >> x;
		i = xoa(a, n, x);
		xuat(a, n);
		break;
	}
	cout << endl;
	} while (chon > 0 && chon < 8);

	system("pause");
	return 0;
}