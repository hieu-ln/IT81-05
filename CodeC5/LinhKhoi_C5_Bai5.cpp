#include<iostream>
#include<stdio.h>
#include<fstream>
#include<sstream>
using namespace std;
#define MAX 20

struct node{
	int info;
	node *link;
};
node *first[MAX];
int n;
char vertex[MAX];

node *sp;
node *front, *rear;
///stack
void initstack()
{
	sp = NULL;
}
int isemptys()
{
	if(sp==NULL)
		return 1;
	return 0;
}
void pushs(int x)
{
	node *p;
	p = new node;
	p->info = x;
	p->link=sp;
	sp=p;
}
int pops(int &x)
{
	if (sp!= NULL)
	{
		node *p = sp;
		x= p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
///end stack

///queue
void initqueue()
{
	front = NULL;
	rear = NULL;
}
int isemptyq()
{
	if (front == NULL)
		return 1;
	return 0;
}
void pushq(int x)
{
	node *p = new node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}
int popq(int &x)
{
	if (front !=NULL)
	{
		node *p = front;
		front = p->link;
		x= p->info;
		if( front == NULL)
		{
			rear =NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}
///end queue



///danh sach ke
void initgraph()
{
	n=0;
}
void insertlast(node *&first, node *p)
{
	if(first == NULL)
		first = p;
	else
	{
		node *q= first;
		while(q->link!=NULL)
		{
			q=q->link;
		}
		q->link= p;
	}
}
void inputgraphfromtext()
{
	string line;
	ifstream myfile ("danhsachke1.txt");
	if(myfile.is_open())
	{
		myfile>>n;
		for(int i=0;i<n;i++)
			myfile>>vertex[i];
		string str;
		int i=0;
		while(getline(myfile, str))
		{
			istringstream ss(str);
			int u;
			while(ss >> u)
			{
				node *p = new node;
				p->info = u;
				p->link = NULL;
				insertlast(first[i-1],p);
			}
			i++;
		}
		cout<<i;
	}
}
///5.1
void inputgraph()
{
	cout<<"Nhap so dinh do thi n: ";
	cin>>n;
	cout<<"Nhap ten dinh: ";
	for(int i=0; i<n; i++)
		cin>>vertex[i];
	for(int i=0; i<n; i++)
	{
		if(i>0)
			cout<<"Nhap DSK cua dinh thu "<<i-1<<" ("<<vertex[i-1]<<") ";
		int u;
		string str;
		while(getline(cin,str))
		{
			istringstream ss(str);
			while(ss >> u)
			{
				node *p = new node;
				p->info = u;
				p->link = NULL;
				insertlast(first[i-1],p);
			}
			break;
		}
	}
}
///5.2
void outputgraph()
{
	for(int i=0;i<n;i++)
	{
		cout<<"Dinh "<<i<<" ("<<vertex[i]<<"): ";
		node *p= first[i];
		while (p!=NULL)
		{
			cout<<p->info<<" ";
			p=p->link;
		}
		cout<<endl;
	}
}
void output(int a[], int n)
{
	for(int i=0;i<n;i++)
		cout<<vertex[a[i]]<<" ";
}
int C[100], bfs[100];
int nbfs=0;
void initC()
{
	for(int i=0;i<n;i++)
		C[i]=1;
}
///5.3
void BFS(int v)
{
	int p;
	node *w;
	pushq(v);
	C[v]=0;
	while(front!=NULL)
	{
		popq(p);
		bfs[nbfs]=p;
		w = first[p];
		nbfs++;
		while(w!= NULL)
		{
			if(C[w->info])
			{
				pushq(w->info);
				C[w->info]=0;
			}
			w=w->link;
		}
	}
}
///5.4
int dfs[100];
int ndfs=0;
void DFS(int s)
{
	pushs(s);
	dfs[ndfs]=s;
	ndfs++;
	C[s]=0;
	int u=s;
	node *v= NULL;
	while(isemptys()==0)
	{
		if(v==NULL)
			pops(u);
		v= first[u];
		while(v!=NULL)
		{
			if(C[v->info]==1)
			{
				pushs(u);
				pushs(v->info);
				dfs[ndfs]=v->info;
				ndfs++;
				C[v->info]=0;
				u=v->info;
				break;
			}
			v=v->link;
		}
	}
}

///5.5
void search_by_bfs(int x, int v)
{
	int p;
	node *w;
	pushq(v);
	C[v]=0;
	while(front!=NULL)
	{
		popq(p);
		if(x==p)
		{
			cout<<"Tim thay x= "<<x<<endl;
			return;
		}
		w= first[p];
		while(w!=NULL)
		{
			if(C[w->info])
			{
				pushq(w->info);
				C[w->info]=0;
			}
			w=w->link;
		}
	}
}
int main()
{
	int choice,x;
	system("cls");
	cout<<"--------  BAI TAP 5 , CHUONG 5 . DO THI --------"<<endl;
	cout<<"1. Khoi tao DANH SACH KE rong"<<endl;
	cout<<"2. Nhap DANH SACH tu file text"<<endl;
	cout<<"3. Nhap DANH SACH KE "<<endl;
	cout<<"4. Xuat DANH SACH KE "<<endl;
	cout<<"5. Duyet do thi theo chieu rong BFS - DSLK"<<endl;
	cout<<"6. Duyet do thi theo chieu sau DFS - DSLK"<<endl;
	cout<<"7. Tim dinh co gia tri x theo BFS"<<endl;
	cout<<"8. Thoat"<<endl;
	do
	{
		cout<<"\nVui long chon so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			initgraph();
			cout<<"Ban vua khoi tao DANH SACH KE rong thanh cong!\n";
			break;
		case 2:
			inputgraphfromtext();
			cout<<"Ban vua nhap DANH SACH KE tu file: \n";
			outputgraph();
			break;
		case 3:
			inputgraph();
			break;
		case 4:
			outputgraph();
			break;
		case 5:
			initqueue();
			initC();
			cout<<"Vui long nhap dinh xuat phat: ";
			cin>>x;
			nbfs=0;
			BFS(x);
			cout<<"Thu tu dinh sau khi duyet BFS: "<<endl;
			output(bfs,n);
			break;
		case 6:
			initstack();
			initC();
			cout<<"Vui long nhap dinh xuat phat: ";
			cin>>x;
			ndfs=0;
			DFS(x);
			cout<<"Thu tu dinh sau khi duyet DFS: "<<endl;
			output(dfs,n);
			break;
		case 7:
			initqueue();
			initC();
			cout<<"Vui long nhap gia tri x can tim: ";
			cin>>x;
			search_by_bfs(x,0);
			break;
		case 8:
			cout<<"Goodbye......!"<<endl;
			break;
		default:
			break;
		}
	}while(choice!=8);
	system("pause");
	return 0;
}