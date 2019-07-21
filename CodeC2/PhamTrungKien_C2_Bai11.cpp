//Chuong 2: Cau truc du lieu co ban - bai 10- PHAM TRUNG KIEN - nhom 5- IT81
#include<stdio.h>
#include<iostream>
using namespace std;

struct Node
{
	int info;
	Node *link;
};
Node *front, *rear;

void init()
{
	front = NULL;
	rear = NULL;
}

int isEmpty()
{
	if (front == NULL)
		return 1;
	return 0;
}

void push(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}

int pop(int& x)
{
	if (front != NULL)
	{
		Node* p = front;
		front = p->link;
		x = p->info;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}

void process_queue()
{
	if(front!=NULL)
	{
		Node* p = front;
		cout << " <--";
		do {
			cout << p->info << "  ";
			p = p->link;
		} while (p != NULL);
		cout << "<-- " << endl;
	}
}

int main()
{
	int choice, x, i;
	system("cls");
	cout << "1.Khoi tao queue rong\n";
	cout << "2. Them 1 phan tu vao queue\n";
	cout << "3. Lay 1 phan tu ra khoi queue\n";
	cout << "4. Kiem tra queue rong hay khong\n";
	cout << "5. Xuat queue ra man hinh\n";
	cout << "6. Thoat\n";
	do {
		cout << "Vui long chon so: ";
		cin >> choice;	
		switch (choice)
		{
		case 1:
			init();
			cout << "Khoi tao queue thanh cong!\n";
			break;
		case 2:
			cout << "Nhap gia tri x: ";
			cin >> x;
			push(x);
			cout << "queue sau khi them: ";
			process_queue();
			break;
		case 3:
			pop(x);
			cout << "phan tu lay ra tu queue: " << x << endl;
			cout << "Stack sau khi lay ra: ";
			process_queue();
			break;
		case 4:
			i = isEmpty();
			if (i == 0)
				cout << "Queue khong rong\n";
			else
				cout << "Queue rong\n";
			break;
		case 5:
			cout << "Stack hien tai la: ";
			process_queue();
			break;
		case 6:
			cout << "Ban chon thoat!\n";
			break;
		default:
			break;
		}
	} while (choice != 6);
	system("pause");
	return 0;
}