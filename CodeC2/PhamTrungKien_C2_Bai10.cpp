//Chuong 2: Cau truc du lieu co ban - bai 10- PHAM TRUNG KIEN - nhom 5- IT81
#include<iostream>
#include<stdio.h>
using namespace std;

struct Node
{
	int info;
	Node* link;
};
Node *sp;

void init()
{
	sp = NULL;
}

int isEmpty()
{
	if (sp == NULL)
		return 1;
	return 0;
}

void push( int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}

int pop(int& x)
{
	if (sp != NULL)
	{
		Node* p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}

void process_stack()
{
	Node* p = sp;
	do {
		cout << p->info << " ";
		p = p->link;
	} while (p != NULL);
	cout << endl;
}

int main()
{
	int a[MAX];
	int choose, sp, kq, n;
	system("cls");
	cout << "1.Khoi tao danh sach rong\n";
	cout << "2 Them 1 phan tu vao stack\n";
	cout << "3. Lay phan tu ra khoi stack\n";
	cout << "4. Xuat stack ra man hinh\n";
	cout << "5. Thoat\n";
	do {
		cout << "Nhap so thu tu thao tac muon thuc hien: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			init();
			cout << "Khoi tao danh sach thanh cong!\n";
			break;
		case 2:
			cout << "Nhap gia tri x: ";
			cin >> x;
			push(x);
			cout << "Stack sau khi them: ";
			process_stack();
			break;
		case 3:
			pop(x);
			cout << "phan tu lay ra tu stack: " << x << endl;
			cout << "Stack sau khi lay ra: ";
			process_stack();
			break;
		case 4:
			cout << "Stack hien tai la: ";
			process_stack();	
			break;
		case 5:
			cout << "Ban chon thoat!\n";
			break;
		default:
			break;
		}
	} while (choose != 5);
	system("pause");

	return 0;
}