#include<iostream>
using namespace std;
struct Node
{
	int info;
	Node *link;
};
Node *first;
void init()
{
	first = NULL;
}
void Process_list()
{
	Node *p;
	p = first;
	while(p!=NULL)
	{
		cout<<p->info<<endl;
		p=p->link;
	}
}
Node *search (int x)
{
	Node *p= first;
	while ((p!=NULL) && (p->info!=x))
		p=p->link;
	return p;
}
void Insert_first(int x)
{
	Node *p;
	p= new Node;
	p->info = x;
	p->link = first;
	first = p;
}
int Delete_first()
{
	if(first!=NULL)
	{
		Node *p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}
void Insert_last(int x)
{
	Node *p;
	p= new Node;
	p->info = x;
	p->link = NULL;
	if(first == NULL)
		first = p;
	else
	{
		Node *q = first;
		while(q->link!=NULL)
			q=q->link;
		q->link= p;
	}
}
int Delete_last()
{
	if(first!=NULL)
	{
		Node *p, *q;
		p = first; q= NULL;
		if(p!=NULL)
			while(p->link!=NULL)
			{
				q=p;p=p->link;
			}
			if(p!=first)
				q->link=NULL;
			else first = NULL;
			delete p;
			return 1;
	}
	return 0;
}
void sapxeptang()
{
	Node *p = first, kq, *q;
	while( p->link!= NULL)
	{
		q=p->link;
		while(q!=NULL)
			if(p->info > q->info)
			{
				int tam = p->info;
				p->info=q->info;
				q->info=tam;
			}
			q=q->link;
	}
	p=p->link;
}
int main()
{
	int x, t, chon;
	Node *tmp;
	init();
	while(true)
	{
		cout<<"\nNhap chon:\n"
			<<"0.Thoat\n"
			<<"1.Them phan tu vao dau danh sach\n"
			<<"2.Them phan tu vao cuoi danh sach \n"
			<<"3.Tim phan tu trong danh sach\n"
			<<"4.Xuat danh sach\n"
			<<"5.Xoa phan tu dau danh sach\n"
			<<"6.Xoa phan tu cuoi danh sach\n"
			<<"7.Sap xep tang\n"
			<<"Chon: ";
		cin>>chon;
		switch(chon)
		{
		case 0:
			return 1;
			break;
		case 1:
			cout<<"Nhap gia tri muon them dau danh sach: ";
			cin>>x;
			Insert_first(x);
			cout<<"Them thanh cong!\n";
			break;
		case 2:
			cout<<"Nhap gia tri muon them cuoi danh sach: ";
			cin>>x;
			Insert_last(x);
			cout<<"Them thanh cong!\n";
			break;
		case 3:
			cout<<"Nhap gia tri can tim : ";
			cin>>x;
			tmp = search(x);
			if(tmp!=NULL)
			{
				cout<<"tim thanh cong\n";
			}
			else
			{
				cout<<"tim khong thanh cong\n";
				}
			break;
		case 4:
			cout<<"Danh sach:\n";
			Process_list();
			break;
		case 5:
			t=Delete_first();
			if(t!=0)
				cout<<"Xoa thanh cong phan tu dau danh sach!\n";
			else
				cout<<"Danh sach trong!\n";
			break;
		case 6:
			t=Delete_last();
			if(t!=0)
				cout<<"Xoa thanh cong phan tu cuoi danh sach!\n";
			else
				cout<<"Danh sach trong!\n";
			break;
		case 7:
			sapxeptang();
			break;
		default:
			cout<<"Gia tri chon khong hop le\n";
			break;
		}
	}
	system("pause");
	return 0;
}