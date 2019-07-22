#include <iostream>
using namespace std;


//C5.1
#define MAX 100
int a[MAX];
int sp;

//C5.2
void init(int a[], int& sp)
{
	sp = -1;
}
//C5.3
int isEmpty(int a[], int& sp)
{
	if (sp == -1)
		return 1;
	else
		return 0;
}
//C5.4
int isFull(int a[], int& sp)
{
	if (sp == MAX - 1)
		return 1;
	else
		return 0;
}
//C5.5
int push(int a[], int& sp, int n)
{
	if (sp < MAX - 1)
	{
		a[++sp] = n;
		return 1;
	}
	return 0;
}
//C5.6
int pop(int a[], int& sp, int n)
{
	if (sp != -1)
	{
		n = a[sp--];
		return 1;
	}
	return 0;
}
void xuat(int a[], int& sp)
{
	for (int i = 0; i < sp + 1; i++)
		cout << a[i] << "  ";
	cout << endl;
}

int main()
{
	int a[MAX];
	int choose, sp, kq, n;
	cout << "1.Khoi tao danh sach rong " << endl;
	cout << "2. Kiem tra stack rong " << endl;
	cout << "3. Kiem tra stack day " << endl;
	cout << "4. Them 1 phan tu vao stack " << endl;
	cout << "5. Xoa 1 phan tu trong stack " << endl;
	cout << "6. Xuat stack ra man hinh " << endl;
	cout << "7. Thoat" << endl;
	do {
		cout << "Nhap so thu tu thao tac muon thuc hien: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			init(a, sp);
			cout << "Khoi tao danh sach thanh cong! " << endl;
			break;
		case 2:
			if (isEmpty(a, sp) == 1)
				cout << "Stack rong " << endl;
			else
				cout << "Stack khong rong " << endl;
			break;
		case 3:
			if (isFull(a, sp) == 1)
				cout << "Stack da day " << endl;
			else
			cout << "Stack hien tai chua day " << endl;
			break;
		case 4:
			cout << "Nhap gia tri can them: ";
			cin >> n;
			kq = push(a, sp, n);
			cout << "Stack sau khi them la: ";
			xuat(a, sp);
			break;
		case 5:
			cout << "Nhap gia tri can xoa: ";
			cin >> n;
			kq = pop(a, sp, n);
			cout << "Stack sau khi lay " << n << " ra: ";
			xuat(a, sp);
			break;
		case 6:
			if (isEmpty(a, sp) == 1)
				cout << "Stack khong co " << endl;
			else
				xuat(a, sp);
			break;
		case 7:
			cout << "Ban chon thoat! " << endl;
			break;
		default:
			break;
		}
	} while (choose != 7);
	return 0;
}