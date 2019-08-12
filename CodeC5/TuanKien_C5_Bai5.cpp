#include <iostream>
#include <string>
#include <stdio.h>
#define Max 20
char vertex[Max];
using namespace std;
struct Node{
	int info;
	Node *link;
};
Node *first[Max];
Node *sp;
Node *front, *rear;
int n;
void init()
{
	for(int i=0;i<n;i++)
		first[i]=NULL;
}

void insert_last(Node *&first, Node *p)
{
	if(first==NULL)
		first=p;
	else
	{
		Node *q=first;
		while(q->link!=NULL)
		{
			q=q->link;
		}
		q->link=p;
	}
}
void insert_first(Node *&f, int x)
{
	Node *p=new Node;
	p->info=x;
	p->link=f;
	f=p;
}

void input()
{
	int d,x,m;
	cout<<"Nhap so dinh cua do thi: ";
	cin>>n;
	cout<<"Nhap ten dinh: ";
	for(int i=0;i<n;i++)
	{
		cin>>vertex[i];
	}
	for(int i=0;i<n;i++)
	{
			cout<<"Nhap DSK cua dinh thu "<<i<<" ("<<vertex[i]<<"): ";
			cin>>d;
			insert_first(first[i],d);
			cout<<"Nhap vao so dinh ke cua "<<d<<": "<<endl;
			cin>>m;
			for(int j=0;j<n;j++)
			{
				cin>>x;
				insert_first(first[i],x);
			}
	}
}

void output_list(Node *f)
{
	if(f!=NULL)
	{
		Node *p=f;
		while(p!=NULL)
		{
			cout<<p->info<<" ";
			p=p->link;
		}
	}
}

void output()
{
	if(n>0)
		for(int i=0;i<n;i++)
		{
			cout<<endl<<"Danh sach thu"<<i<<": ";
			output_list(first[i]);
		}
	else
		cout<<"DANH SACH RONG !"<<endl;
}
void output(int a[],int n)
{
	for(int i=0;i<n;i++)
		cout<<vertex[a[i]]<<" ";
}

void initQ()
{
	front=NULL;
	rear=NULL;
}
int isEmptyQ()
{
	if(front==NULL)
		return 1;
	return 0;
}
void PushQ(int x)
{
	Node *p=new Node;
	p->info=x;
	p->link=NULL;
	if(rear==NULL)
		front=p;
	else
		rear->link=p;
	rear=p;
}
int PopQ(int &x)
{
	if(front!=NULL)
	{
		Node *p=front;
		front=p->link;
		x=p->info;
		if(front==NULL)
		{
			rear=NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}

void initS()
{
	sp=NULL;
}
int isEmptyS()
{
	if(sp==NULL)
		return 1;
	return 0;
}
void PushS(int x)
{
	Node *p=new Node;
	p->info=x;
	p->link=sp;
	sp=p;
}
int PopS(int &x)
{
	if(sp!=NULL)
	{
		Node *p=sp;
		x=p->info;
		sp=p->link;
		delete p;
		return 1;
	}
	return 0;
}

int C[100],bfs[100];
int nbfs=0;
void initC()
{
	for(int i=0;i<n;i++)//n la so dinh cua do thi
		C[i]=1;
}
void BFS(int v)
{
	int p;
	Node *w;
	PushQ(v);
	C[v]=0;
	while(front!=NULL)
	{
		PopQ(p);
		bfs[nbfs]=p;
		w=first[p];
		nbfs++;
		while(w!=NULL)
			if(C[w->info])
			{
				PushQ(w->info);
				C[w->info]=0;
			}
			w=w->link;
	}
}

int dfs[100];
int ndfs;
void DFS(int s)
{
	PushS(s);
	dfs[ndfs]=s;
	ndfs++;
	C[s]=0;
	Node *v=NULL;
	int u=s;
	while(isEmptyS()==0)
	{
		if(v==NULL)
			PopS(u);
		while(v!=NULL)
		{
			if(C[v->info]==1)
			{
				PushS(u);
				PushS(v->info);
				dfs[ndfs]=v->info;;
				ndfs++;
				C[v->info]=0;
				u=v->info;
				break;
			}
			v=v->link;
		}
	}
}

void searchbybfs(int x, int v)
{
	int p;
	Node *w;
	PushQ(v);
	C[v]=0;
	while(front!=NULL)
	{
		PopQ(p);
		if(x==p)
		{
			cout<<x<<" Ton tai"<<endl;
			return;
		}
		w=first[p];
		while(w!=NULL)
			if(C[w->info])
			{
				PushQ(w->info);
				C[w->info]=0;
			}
	}
}
int main()
{
	int a[Max];
	int b[Max];
	int choose,sp,x,i;
	system("cls");
	cout<<"1.Khoi tao danh sach ke"<<endl;
	cout<<"2.Nhap Danh sach ke cua do thi"<<endl;
	cout<<"3.Xuat danh sach ke cua do thi"<<endl;
	cout<<"4.Duyet do thi theo chieu rong - Queue"<<endl;
	cout<<"5.Duyet do thi theo chieu sau - Stack"<<endl;
	cout<<"6.Tim kiem mot dinh x theo BFS"<<endl;
	cout<<"7.EXIT"<<endl;
	do{
		cout<<"Nhap lua chon de thuc hien: ";
		cin>>choose;
		switch(choose)
		{
			case 1:
				init();
				cout<<"Khoi tao thanh cong"<<endl;
				break;
			case 2:
				input();
				break;
			case 3:
				output();
				break;
			case 4:
				initQ();
				initC();
				cout<<"Nhap dinh bat dau: ";
				cin>>x;
				nbfs=0;
				BFS(x);
				cout<<"Thu tu cac dinh cua do thi sau khi duyet BFS: ";
				output(bfs,n);
				cout<<endl;
				break;
			case 5:
				initS();
				initC();
				cout<<"Nhap dinh bat dau: ";
				cin>>x;
				ndfs=0;
				DFS(x);
				cout<<"Thu tu cac dinh cua do thi sau khi duyet DFS: ";
				output(dfs,n);
				cout<<endl;
				break;
			case 6:
				cout<<"Nhap gia tri x can tim theo BFS: ";
				cin>>x;
				searchbybfs(x,0);
				break;
			case 7:
				cout<<"Ban chon thoat!\n"<<endl;
				break;
			default:
				break;
		}
	}while(choose!=7);
	system("pause");
	return 0;
}