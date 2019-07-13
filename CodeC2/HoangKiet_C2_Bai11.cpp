#include <iostream>
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
	{
		return 1;
	}
	return 0;
}
void Push(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
	{
		front = p;
	}
	else
	{
		rear->link = p;
	}
	rear = p;
}
int Pop(int &x)
{
	if (front !=NULL)
	{
		Node *p = front;
		front = p->link;
		x = p->info;
		if (front == NULL)
		{
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}
void Process_queue()
{
	if (front != NULL)
	{
		Node *p = front;
		cout << "<----- ";
		do
		{
			cout << p->info << "    ";
			p = p->link;
		} while (p!=NULL);
		cout << "<---" << endl;
	}
}
int main()
{
	int choice, x, i;
	cout << " 1. Khoi tao QUEUE rong  " << endl;
	cout << " 2. Them phan tu vao QUEUE  " << endl;
	cout << " 3. Lay phan tu ra khoi QUEUE  " << endl;
	cout << " 4.Kiem tra QUEUE co rong hay khong  " << endl;
	cout << " 5. Xuat QUEUE  " << endl;
	cout << " 6.Thoat  " << endl;
	cout << endl;
	do
	{
		cout << "\nVui long chon: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "Ban vua khoi tao thanh cong\n";
			break;
		case 2:
			cout << "Vui lhong nhap gia tri ; ";
			cin >> x;
			Push(x);
			cout << "Xuat ra: ";
			Process_queue();
			break;
		case 3:
			Pop(x);
			cout << "Phan tu lay ra x = " << x << endl;
			cout << "Xuat sau khi lay: ";
			Process_queue();
			break;
		case 4:
			isEmpty();
			if (i == 0)
			{
				cout << "Khong thanh cong" << endl;
			}
			else
			{
				cout << "Thanh cong " << endl;
 			}
		case 5:
			Process_queue();
			break;
		case 6: 
			cout << "BYE__________ " << endl;
		default:
			break;
		}

	} while (choice != 6);
	return 0;
}