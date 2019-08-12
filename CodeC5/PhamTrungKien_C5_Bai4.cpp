#include <iostream>
using namespace std;

#define MAX 20
int a[MAX][MAX];
int n;
char vertex[MAX];

struct node {
	int info;
	node* link;
};
node* sp;
node* front, * rear;
void initstack()
{
	sp = NULL;
}
int isemptyS()
{
	if (sp == NULL)
		return 1;
	return 0;
}
void pushS(int x)
{
	node* p = new node;
	p->info = x;
	p->link = sp;
	sp = p;
}
int popS(int& x)
{
	if (sp != NULL)
	{
		node* p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
void initQueue()
{
	front = NULL;
	rear = NULL;
}
int isemptyQ()
{
	if (front == NULL)
		return 1;
	return 0;
}
void pushQ(int x)
{
	node* p = new node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}
int popQ(int& x)
{
	if (front != NULL)
	{
		node* p = front;
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
void initGraph()
{
	n = 0;
}
void inputGraph()
{
	cout << "Nhap so dinh do thi n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap ten dinh: ";
		cin >> vertex[i];
		cout << "Nhap vao dong thu " << i + 1 << " : ";
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
}
void outputGraph()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << vertex[a[i]] << " ";
}
int c[100], bfs[100];
int nbfs = 0;
void initC()
{
	for (int i = 0; i < n; i++)
		c[i] = 1;
}
void BFS(int v)
{
	int w, p;
	pushQ(v);
	c[v] = 0;
	while (front != NULL)
	{
		popQ(p);
		bfs[nbfs] = p;
		nbfs++;
		for (w = 0; w < n; w++)
			if (c[w] && a[p][w] == 1)
			{
				pushQ(w);
				c[w] = 0;
			}
	}
}
int dfs[100];
int ndfs = 0;
void DFS(int s)
{
	pushS(s);
	dfs[ndfs] = s;
	ndfs++;
	c[s] = 0;
	int v = -1, u = s;
	while (isemptyS() == 0)
	{
		if (v == n)
			popS(u);
		for (v = 0; v < n; v++)
			if (a[u][v] != 0 && c[v] == 1)
			{
				pushS(u);
				pushS(v);
				dfs[ndfs] = v;
				ndfs++;
				c[v] = 0;
				u = v;
				break;
			}
	}
}
void searchBFS(int x, int v)
{
	int w, p;
	pushQ(v);
	c[v] = 0;
	while (front != NULL)
	{
		popQ(p);
		if (x == p)
		{
			cout << "Tim thay x= " << x << endl;
			return;

		}
		for (w = 0; w < n; w++)
			if (c[w] && a[p][w] == 1)
			{
				pushQ(w);
				c[w] = 0;
			}
	}
}
int main()
{
	int a[MAX];
	int b[MAX];
	int choose, sp, sp_b, x, i;
	system("cls");
	cout << "1.Khoi tao ma tran ke rong\n";
	cout << "2.Nhap ma tran ke\n";
	cout << "3.Xuat ma tran ke\n";
	cout << "4.Duyet do thi theo BFS - DSLK\n";
	cout << "5.Duyet do thi theo DFS - DSLK\n";
	cout << "6.Tim dinh co gia tri x theo BFS\n";
	cout << "7.Thoat!\n";
	do {
		cout << "Nhap so thuc hien: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			initGraph();
			cout << "Khoi tao thanh cong!\n";
			break;
		case 2:
			inputGraph();
			break;
		case 3:
			outputGraph();
			break;
		case 4:
			initQueue();
			initC();
			cout << "Nhap dinh xuat phat: ";
			cin >> x;
			nbfs = 0;
			BFS(x);
			cout << "Thu tu dinh sau khi duyet BFS: \n";
			output(bfs, n);
			break;
		case 5:
			initstack();
			initC();
			cout << "Nhap dinh xuat phat: ";
			cin >> x;
			ndfs = 0;
			DFS(x);
			cout << "Thu tu dinh sau khi duyet DFS: \n";
			output(dfs, n);
			break;
		case 6:
			cout << "Nhap gia tri x can tim: ";
			cin >> x;
			searchBFS(x, 0);
			break;
		case 7:
			cout << "Ban chon thoat!\n";
			break;
		default:
			break;
		}
	} while (choose != 7);
	system("pause");
}