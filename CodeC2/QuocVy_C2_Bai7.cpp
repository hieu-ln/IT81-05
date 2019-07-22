
#include <iostream>
#include <stdio.h>
using namespace std;

//C7.1 Khai bao cau truc Queue
#define MAX 100
//C7.2 Khoi tao Queue rong
void init(int a[], int &front, int &rear)
{
	front = -1;
	rear = -1;
}
//C7.3 Kiem tra Queue rong
int isEmpty(int a[], int &front, int &rear)
{
	if (front == rear)
		return 1;
	return 0;
}
//C7.4 Kiem tra Queue day
int isFull(int a[], int &front, int &rear)
{
	if ((front == 0 && rear == MAX - 1) || (front - rear == 1))
		return 1;
	else
		return 0;
}
//C7.5 Them 1 phan tu vao Queue
int Push(int a[], int &front, int &rear, int n)
{
	if (rear - front == MAX - 1)
		return 0;
	else
	if (front == -1)
		front = 0;
	if (rear == MAX - 1)
	{
		for (int i = front; i <= rear; i++)
		{
			a[i - front] = a[i];
		}
		rear = MAX - 1 - front;
		front = 0;
	}
	a[++rear] = n;
	return 1;
}

//C7.6 Xoa 1 phan tu trong Queue
int Pop(int a[], int &front, int &rear, int &n)
{
	if (front == -1)
		return 0;
	else
	{
		n = a[front++];
		if (front > rear)
		{
			front = -1;
			rear = -1;
		}
		return 1;
	}
}
//Xuat hang doi
void xuat(int a[], int front, int rear)
{
	cout << "front = " << front << "  " << "rear = " << rear << endl;
	if (front < rear && front != -1)
	{
		cout << "<----  ";
		for (int i = front; i < rear + 1; i++)
		{
			cout << a[i] << "  ";
		}
		cout << "<----  " << endl;
	}
}
int main()
{
	int a[MAX];
	int choose, front, rear, n, k;
	system("cls");
	cout << "1. Khoi tao Queue rong " << endl;
	cout << "2. Them phan tu vao Queue " << endl;
	cout << "3. Lay phan tu ra khoi Queue " << endl;
	cout << "4. Kiem tra Queue rong" << endl;
	cout << "5. Kiem tra Queue day" << endl;
	cout << "6. Xuat Queue " << endl;
	cout << "7. Thoat" << endl;
	do{
		cout << "\n Nhap so thu tu muon thuc hien: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			init(a, front, rear);
			cout << "Khoi tao Queue thanh cong! " << endl;
			break;
		case 2:
			cout << "Nhap gia tri phan tu can them: ";
			cin >> n;
			k = Push(a, front, rear, n);
			cout << "Queue thay doi la: ";
			xuat(a, front, rear);
			break;
		case 3:
			cout << "Nhap gia tri phan tu can lay ra: ";
			cin >> n;
			k = Pop(a, front, rear, n);
			cout << "Queue sau khi lay ra: ";
			xuat(a, front, rear);
			break;
		case 4:
			k = isEmpty(a, front, rear);
			if (k == 0)
				cout << "Queue khong rong " << endl;
			else
				cout << "Queue rong " << endl;
			break;
		case 5:
			k = isFull(a, front, rear);
			if (k == 0)
				cout << "Queue chua day " << endl;
			else
				cout << "Queue day " << endl;
			break;
		case 6:
			cout << "Queue hien tai la: ";
			xuat(a, front, rear);
			break;
		case 7:
			cout << "Ban chon thoat " << endl;
			break;
		default:
			break;
		}
	} while (choose != 7);
	system("pause");
	return 0;
}