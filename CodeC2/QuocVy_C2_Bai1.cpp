#include <iostream>
using namespace std;

//Cau1
#define MAX 100
int a[MAX];
int n;
//Cau1.2
void inputList(int a[], int &n)
{
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	cout << "Nhap danh sach: ";
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
//Cau1.3
void outputList(int a[], int &n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
//Cau 1.4
int search(int a[], int &n, int x)
{
	for (int i = 0; i < n; i++)
	if (a[i] == x)
		return i + 1;
	return 0;
}
//Cau 1.5
void addTail(int a[], int &n, int x)
{
	a[n] = x;
	n++;
}
//Cau 1.6
int deleteTail(int a[], int &n)
{
	if (n > 0)
	{
		n--;
		return 1;
	}
	return 0;
}
//Cau 1.7
int Delete(int a[], int &n, int x)
{
	if (x >= 0 && x < n)
	{
		for (int i = x - 1; i < n; i++)
			a[i] = a[i + 1];
		n--;

		return 1;
	}
	return 0;
}
//Cau 1.8
int FindandDelete(int a[], int &n, int x)
{
	if (search(a, n, x) != 0)
	{
		Delete(a, n, search(a, n, x));
		return 1;
	}
	return 0;
}
int main()
{
	cout << "1.Nhap danh sach" << endl;
	cout << "2. Xuat danh sach\n";
	cout << "3.Tim 1 phan tu trong danh sach" << endl;
	cout << "4. Them 1 phan tu vao cuoi danh sach" << endl;
	cout << "5. Xoa phan tu cuoi danh sach" << endl;
	cout << "6.Xoa phan tu tai vi tri bat ky " << endl;
	cout << "7.Tim va xoa mot phan tu trong danh sach " << endl;
	cout << "8.Thoat" << endl;
	int choose;
	do{
		cout << "--Moi ban chon: ";
		cin >> choose;
		if (choose < 1 && choose > 8)
			cout << "Nhap sai. Hay nhap lai" << endl;
		switch (choose)
		{
		case 1:
			inputList(a, n);
			cout << "Nhap danh sach thanh cong" << endl;
			break;
		case 2:
			outputList(a, n);
			cout << "Xuat danh sach thanh cong" << endl;
			break;
		case 3:
			int b;
			cout << "Nhap phan tu muon tim: ";
			cin >> b;
			if (search(a, n, b) != 0)
				cout << b << " co trong danh sach o vi tri " << search(a, n, b) << endl;
			else
				cout << b << " khong co trong danh sach" << endl;
			break;
		case 4:
			int y;
			cout << "Nhap phan tu muon them: ";
			cin >> y;
			addTail(a, n, y);
			cout << "Danh sach sau khi them cuoi: ";
			outputList(a, n);
			cout << endl;
			break;
		case 5:
			if (deleteTail(a, n) == 1)
			{
				cout << "Danh sach sau khi xoa: ";
				outputList(a, n);
				cout << endl;
			}
			else
				cout << "Khong thuc hien duoc" << endl;
			break;
		case 6:
			int k;
			cout << "Nhap vi tri phan tu muon xoa: ";
			cin >> k;
			if (Delete(a, n, k) == 1)
			{
				cout << "Danh sach sau khi xoa: ";
				outputList(a, n);
				cout << endl;
			}
			break;
		case 7:
			int h;
			cout << "Nhap phan tu muon xoa: ";
			cin >> h;
			if (FindandDelete(a, n, h) == 1)
			{
				cout << "Danh sach sau khi xoa: ";
				outputList(a, n);
				cout << endl;
			}
		}
	} while (choose != 8);
	return 0;
}