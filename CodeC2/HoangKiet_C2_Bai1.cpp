#include <iostream>
using namespace std;
#define MAX 100
int a[MAX];

void nhap(int a[], int n)
{
	cout << "Nhap cac phan tu danh sach: ";
	for (int i = 0; i < n; i++)
	{
		cout << "\t";
		cin >> a[i];
	}
	cout << endl;
}
void xuat(int a[], int &n)
{
	cout << "Danh sach ban da nhap:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}
int tim(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i]!= x)
	{
		i++;
	}
	if (i == n)
	{
		return -1;
	}
	return i;
}
void themcuoi(int a[], int &n, int x)
{
	if (n != -1)
	{
		a[n++] = x;
	}

}
void xoa(int a[], int &n)
{
		n--;
}
void xoa_i(int a[], int &n, int i)
{
	if (i >= 0 && i < n)
	{
		for (int j = i; j < n - 1; j++)
		{
			a[j] = a[j + 1];
		}
		n--;
	}
}
int timvsxoa(int a[], int &n, int x)
{
	for (int i=0; i < n; i++)
	{
		if (a[i] == x)
			xoa_i(a, n, i);
			return 1;
	}
	return 0;
}


int main()
{
	int choice = 0;
	int tam;
	int ps;
	cout << "Nhap so luong phan tu: ";
	cin >> ps;
	do
	{
		int x = 0;
	cout << "1.Nhap danh sach cac phan tu: " << endl;
	cout << "2.Tim phan tu trong danh sach: " << endl;
	cout << "3.Them phan tu cuoi danh sach: " << endl;
	cout << "4.Xoa phan tu cuoi danh sach: " << endl;
	cout << "5.Xoa phan tu tai vi tri ban chon: " << endl;
	cout << "6.Tim phan tu va xoa trrong danh sach: " << endl;
	cout << "7.Thoat. " << endl;
	cout << endl;

	cout << "Ban muc nao: ";
	cin >> choice;
	system("pause");
	system("cls");
	switch (choice)
	{
	case 1:
		nhap(a, ps);
		xuat(a, ps);
		break;
	case 2:
		cout << "Tim phan tu ban muon: ";
		cin >> x;
		tam = tim(a, ps, x);
		if (tam == -1)
		{
			cout << "Khong tim thay phan tu ban muon.\n";
		}
		else
			cout << "Phan tu o vi tri i = " << tam + 1<< ",gia tri la " << a[tam] << endl;
		break;
	case 3:
		cout << "Nhap phan tu ban muon them: ";
		cin >> x;
		themcuoi(a, ps, x);
		xuat(a, ps);
		break;
	case 4:
		cout << "Xoa phan tu cuoi. \n";
		xoa(a, ps);
		xuat(a, ps);
		break;
	case 5:
		cout << "Nhap vi tri ban muon xoa:";
		cin >> x;
		x--;
		xoa_i(a, ps, x);
		xuat(a, ps);
		break;
	default:
		cout << "Tim phan tu va xoa trong danh sach:";
		cin >> x;
		x--;
		timvsxoa(a, ps, x);
		xuat(a, ps);
		break;
	}
	} while (choice > 0 && choice < 7);

	system("pause");
	return 0;
}