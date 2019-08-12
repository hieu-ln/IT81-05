//#include<iostream>
//#include<stdio.h>
//#include<fstream>
//using namespace std;
//#define MAX 20
//int A[MAX][MAX];
//int n;
//char vertex[MAX];
//struct node{
//	int info;
//	node *link;
//};
//node *sp;
//node *front, *rear;
//
/////stack
//void initstack()
//{
//	sp = NULL;
//}
//int isemptys()
//{
//	if(sp==NULL)
//		return 1;
//	return 0;
//}
//void pushs(int x)
//{
//	node *p;
//	p = new node;
//	p->info = x;
//	p->link=sp;
//	sp=p;
//}
//int pops(int &x)
//{
//	if (sp!= NULL)
//	{
//		node *p = sp;
//		x= p->info;
//		sp = p->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
/////end stack
//
/////queue
//void initqueue()
//{
//	front = NULL;
//	rear = NULL;
//}
//int isemptyq()
//{
//	if (front == NULL)
//		return 1;
//	return 0;
//}
//void pushq(int x)
//{
//	node *p = new node;
//	p->info = x;
//	p->link = NULL;
//	if (rear == NULL)
//		front = p;
//	else
//		rear->link = p;
//	rear = p;
//}
//int popq(int &x)
//{
//	if (front !=NULL)
//	{
//		node *p = front;
//		front = p->link;
//		x= p->info;
//		if( front == NULL)
//		{
//			rear =NULL;
//		}
//		delete p;
//		return 1;
//	}
//	return 0;
//}
/////end queue
//void initgraph()
//{
//	n=0;
//}
//void inputgraphfromtext()
//{
//	string line;
//	ifstream myfile ("matranke1.txt");
//	if(myfile.is_open())
//	{
//		myfile>>n;
//		for(int i=0;i<n;i++)
//			myfile>>vertex[i];
//		for(int i=0;i<n;i++)
//		{
//			for(int j=0; j<n;j++)
//				myfile>>A[i][j];
//		}
//	}
//}
/////4.1
//void inputgraph()
//{
//	cout<<"Nhap so dinh do thi n: ";
//	cin>>n;
//	cout<<"Nhap ten dinh: ";
//	for(int i=0; i<n; i++)
//		cin>>vertex[i];
//	for(int i=0; i<n; i++)
//	{
//		cout<<"Nhap vao dong thu "<<i+1<<": ";
//		for(int j=0;j<n;j++)
//			cin>>A[i][j];
//	}
//}
/////4.2
//void outputgraph()
//{
//	for(int i=0;i<n;i++)
//	{
//		for(int j= 0;j<n;j++)
//			cout<<A[i][j]<<" ";
//		cout<<endl;
//	}
//}
//void output(int a[], int n)
//{
//	for(int i=0;i<n;i++)
//		cout<<vertex[a[i]]<<" ";
//}
//int C[100], bfs[100];
//int nbfs=0;
//void initC()
//{
//	for(int i=0;i<n;i++)
//		C[i]=1;
//}
//void BFS(int v)
//{
//	int w, p;
//	pushq(v);
//	C[v]=0;
//	while(front!=NULL)
//	{
//		popq(p);
//		bfs[nbfs]=p;
//		nbfs++;
//		for(w=0; w<n;w++)
//			if(C[w] && A[p][w]==1)
//			{
//				pushq(w);
//				C[w]=0;
//			}
//	}
//}
/////4.4
//int dfs[100];
//int ndfs=0;
//void DFS(int s)
//{
//	pushs(s);
//	dfs[ndfs]=s;
//	ndfs++;
//	C[s]=0;
//	int v=-1, u=s;
//	while(isemptys()==0)
//	{
//		if(v==n)
//			pops(u);
//		for(v=0;v<n;v++)
//			if(A[u][v]!=0 && C[v]==1)
//			{
//				pushs(u);
//				pushs(v);
//				dfs[ndfs]=v;
//				ndfs++;
//				C[v]=0;
//				u=v;
//				break;
//			}
//	}
//}
//
/////4.5
//void search_by_bfs(int x, int v)
//{
//	int w,p;
//	pushq(v);
//	C[v]=0;
//	while(front!=NULL)
//	{
//		popq(p);
//		if(x==p)
//		{
//			cout<<"Tim thay x= "<<x<<endl;
//			return;
//		}
//		for(w=0;w<n;w++)
//			if(C[w]&&A[p][w]==1)
//			{
//				pushq(w);
//				C[w]=0;
//			}
//	}
//}
//int main()
//{
//	int choice,x;
//	system("cls");
//	cout<<"--------  BAI TAP 4 , CHUONG 5 . DO THI --------"<<endl;
//	cout<<"1. Khoi tao MA TRAN KE rong"<<endl;
//	cout<<"2. Nhap MA TRAN KE tu file text"<<endl;
//	cout<<"3. Nhap MA TRAN KE "<<endl;
//	cout<<"4. Xuat MA TRAN KE "<<endl;
//	cout<<"5. Duyet do thi theo chieu rong BFS - DSLK"<<endl;
//	cout<<"6. Duyet do thi theo chieu sau DFS - DSLK"<<endl;
//	cout<<"7. Tim dinh co gia tri x theo BFS"<<endl;
//	cout<<"8. Thoat"<<endl;
//	do
//	{
//		cout<<"\nVui long chon so de thuc hien: ";
//		cin>>choice;
//		switch(choice)
//		{
//		case 1:
//			initgraph();
//			cout<<"Ban vua khoi tao MA TRAN KE rong thanh cong!\n";
//			break;
//		case 2:
//			inputgraphfromtext();
//			cout<<"Ban vua nhap MA TRAN KE tu file: \n";
//			outputgraph();
//			break;
//		case 3:
//			inputgraph();
//			break;
//		case 4:
//			outputgraph();
//			break;
//		case 5:
//			initqueue();
//			initC();
//			cout<<"Vui long nhap dinh xuat phat: ";
//			cin>>x;
//			nbfs=0;
//			BFS(x);
//			cout<<"Thu tu dinh sau khi duyet BFS: "<<endl;
//			output(bfs,n);
//			break;
//		case 6:
//			initstack();
//			initC();
//			cout<<"Vui long nhap dinh xuat phat: ";
//			cin>>x;
//			ndfs=0;
//			DFS(x);
//			cout<<"Thu tu dinh sau khi duyet DFS: "<<endl;
//			output(dfs,n);
//			break;
//		case 7:
//			initqueue();
//			initC();
//			cout<<"Vui long nhap gia tri x can tim: ";
//			cin>>x;
//			search_by_bfs(x,0);
//			break;
//		case 8:
//			cout<<"Goodbye......!"<<endl;
//			break;
//		default:
//			break;
//		}
//	}while(choice!=8);
//	system("pause");
//	return 0;
//}
