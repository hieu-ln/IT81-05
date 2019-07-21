//Chuong 2 : Cau truc du lieu co ban - bai 11 - Luc Tuan Kien - nhom 5 - IT81
#include <iostream>
using namespace std;

//11.1 Khai bao cau truc Queue
struct Node
{
	int info;
	Node *link;
};
Node *front,*rear;
//11.2 Khoi tao Queue rong
void init()
{
	front = NULL;
	rear = NULL;
}
//11.3 Kiem tra Queue rong
int isEmpty()
{
	if(front == NULL)
		return 1;
	return 0;
}
//11.4 Them phan tu vao Queue
void Push(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if(rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}
//11.5 Xoa phan tu trong Queue
//Xuat Queue
void xuat()
{
	if(front != NULL)
	{
		Node *p = front;
		cout << "<---   ";
		do{
			cout << p->info << "  ";
			p= p ->link;
		}while(p!= NULL);
		cout << "<---  " << endl;
	}
}
int Pop(int &x)
{
	if(front != NULL)
	{
		Node *p = front;
		front = p->link;
		x = p ->info;
		if(front == NULL)
		{
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}
int main()
{
	int choose, x;
	system("cls");
	cout << "1.Khoi tao Queue rong\n";
	cout << "2.Kiem tra Queue rong\n";
	cout << "3.Them phan tu vao Queue\n";
	cout << "4. Xoa phan tu trong Queue\n";
	cout << "5. Xuat Queue\n";
	cout << "6. Thoat\n";
	do{
		cout << "Nhap so thu tu muon thuc hien: ";
		cin >> choose;
		switch(choose)
		{
		case 1:
			init();
			cout << "Khoi tao Queue thanh cong!\n";
			break;
		case 2:
			if(isEmpty() == 1)
				cout << "Queue hien tai rong\n";
			else
				cout << "Queue khong rong\n";
			break;
		case 3:
			cout << "Nhap gia tri phan tu can them: ";
			cin >> x;
			Push(x);
			cout << "Queue sau khi them: ";
			xuat();
			break;			
		case 4:
			cout << "Nhap phan tu can xoa: ";
			cin >> x;
			Pop(x);
			cout << "Queue sau khi xoa: ";
			xuat();
			break;
		case 5:
			cout << "Queue hien tai la: ";
			xuat();
			break;
		case 6:
			cout << "Ban chon thoat!\n";
			break;
		default:
			break;
		}
	}while(choose != 6);
	return 0;
}