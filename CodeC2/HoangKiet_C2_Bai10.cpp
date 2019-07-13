#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node *link;
};
Node *sp;
void init()
{
	sp = NULL;
}
int isEmpty()
{
	if (sp==NULL)
	{
		return 1;
	}
	return 0;
}
void Push(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}
int Pop(int &x)
{
	if (sp != NULL)
	{
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
void Process_stack()
{
	Node *p = sp;
	do
	{
		cout << p->info << "   ";
		p = p->link;
	} while (p != NULL);
	cout << endl;
} 
int main()
{
	int choice, x, i;
	cout << " 1. Khoi tao STACK rong" << endl;
	cout << " 2. Them phan tu vao STACK" << endl;
	cout << " 3. Lay phan tu ra STACK "<< endl;
	cout << " 4. Xuat STACK" << endl;
	cout << " 5.Thoat" << endl;
	
	do
	{
		cout << "\nVui long chon: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "Khoi tao thanh cong" << endl;
			break;
		case 2:
			cout << "Vui nhap gia tri : ";
			cin >> x;
			Push(x);
			cout << "STACK sau: ";
			Process_stack();
			break;
		case 3:
			Pop(x);
			cout << "Phan tu lay " << x << endl;
			cout << "STACK sau: ";
			Process_stack();
			break;
		case 4:
			cout << "STACK hien tai: " << endl;
			Process_stack();
			break;
		case 5:
			cout << "GOODBYE---------------" << endl;


		default:
			break;
		}
	} while (choice != 5);
	return 0;
}
