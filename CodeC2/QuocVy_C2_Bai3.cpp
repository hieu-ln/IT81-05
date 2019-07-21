#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node *link;
};
Node *first;
//C3.2
void init()
{
	first = NULL;
}
//C3.3
void processList()
{
	Node *p;
	p = first;
	while (p != NULL)
	{
		cout << p->info << "  ";
		p = p->link;
	}
}
//C3.4
Node *Search(int x)
{
	Node *p = first;
	while (p != NULL && p->info != x)
		p = p->link;
	return p;
}
void addFirst(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}
int deleteFirst()
{
	if (first = NULL)
	{
		Node *p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}
void addLast(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = NULL;
	if (first == NULL)
		first = p;
	else
	{
		Node *q = first;
		while (q->link != NULL)
			q = q->link;
		q->link = p;
	}
}
//C3.8
void deleteLast()
{
	Node *p, *q;
	p = first;
	if (p != NULL)
	while (p->link != NULL)
	{
		q = p;
		p = p->link;
	}
	q -> link = NULL;
	delete p;
}
//C3.9
int FindAndDelete(int x)
{
	if (first != NULL)
	{
		Node *p, *q;
		p = first;
		q = first;
		while (p != NULL && p->info != x)
		{
			q = p;
			p = p->link;
		}
		if (p != first && p->link != NULL)
		{
			
			if (p->link != NULL)
				q->link = p->link;
			else
				q->link = NULL;
			delete p;
			return 1;
		}
		else
		if (p == first)
		{
			first = p->link;
			delete p;
			return 1;
		}
		else
			return 0;

	}
	return 0;
}
int main()
{
	cout << "1.Khoi tao danh sach rong " << endl;
	cout << "2.Xuat danh sach" << endl;
	cout << "3.Tim 1 phan tu trong danh sach" << endl;
	cout << "4.Them 1 phan tu vao dau danh sach" << endl;
	cout << "5.Xoa phan tu o dau danh sach" << endl;
	cout << "6.Them 1 phan tu o cuoi danh sach" << endl;
	cout << "7.Xoa 1 phan tu cuoi danh sach" << endl;
	cout << "8.Xoa phan tu can tim" << endl;
	cout << "9.Thoat!" << endl;
	int choice;
	int x;
	Node *p;
	do{
		cout << "Moi ban chon: ";
		cin >> choice;
		if (choice < 1 || choice > 9)
			cout << "Nhap sai.Nhap lai " << endl;
		switch (choice)
		{
		case 1:
			init();
			cout << "Ban khoi tao danh sach thanh cong! " << endl;
			break;
		case 2:
			cout << "Danh sach: ";
			processList();
			cout << endl;
			break;
		case 3:

			cout << "Nhap gia tri can tim: ";
			cin >> x;
			p = Search(x);
			if (p != NULL)
				cout << " co trong danh sach x= " << p->info << endl;
			else
				cout << p->info << " khong co trong danh sach " << endl;
			break;
		case 4:
			cout << "Nhap gia tri phan tu them vao: ";
			cin >> x;
			addFirst(x);
			break;
		case 5:
			deleteFirst();
			cout << "Danh sach sau khi xoa: ";
			processList();
			cout << endl;
			break;
		case 6:
			cout << "Nhap gia tri phan tu can them: ";
			cin >> x;
			addLast(x);
			break;
		case 7:
			deleteLast();
			cout << "Danh sach sau khi xoa cuoi: ";
			processList();
			cout << endl;
			break;
		case 8:
			cout << "Nhap gia tri phan tu can tim: ";
			cin >> x;
			if (FindAndDelete(x) != 0)
			{
				cout << "Danh sach sau khi xoa phan tu can tim: ";
				processList();
			}
			else
				cout << "Khong tim thay phan tu can xoa " << endl;
			cout << endl;
			break;
		case 9:
			break;
		default:
			break;
		}
	} while (choice != 9);
	return 0;
}
