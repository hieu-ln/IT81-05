#include <iostream>
#include <fstream>
using namespace std;
#define MAX 20
int a[MAX][MAX];
int n;
char vertex[MAX];

struct Node
{
	int info;
	Node *link;
};

Node *sp;
Node *front, *rear;

//Stack;
void InitStack()
{
	sp = NULL;
}
int isEmptyS()
{
	if (sp == NULL)
	{
		return 1;
	}
	return 0;
}
void PushS(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}
int PopS(int &x)
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
//end stack

//Queue
void InitQueue()
{
	front = NULL;
	rear = NULL;
}
int isEmptyQ()
{
	if (front == NULL)
	{
		return 1;
	}
	return 0;
}
void PushQ(int x)
{
	Node*p = new Node;
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
int PopQ(int &x)
{
	if (front != NULL)
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
//end Queue

void initGraph()
{
	n = 0;
}
void inputGraphFromText()
{
	string line;
	ifstream myfile("matranke1.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n; i++)
		{
			myfile >> vertex[i];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				myfile >> a[i][j];
			}
		}
	}
}

//cau 4.1
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
		{
			cin >> a[i][j];
		}
	}
}
//cau 4.2
void outputGraph()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << "  ";
		cout << endl;
	}
}
void output(int A[], int n)
{
	for (int  i = 0; i < n; i++)
	{
		cout << vertex[A[i]] << "  ";
	}
}
//cau 4.3
int C[100], bfs[100];
int nbfs = 0;
void InitC()
{
	for (int i = 0; i < n; i++)
	{
		C[i] = 1;
	}
}
void BFS(int v)
{
	int w, p;
	PushQ(v);
	C[v] = 0;
	while (front != NULL)
	{
		PopQ(p);
		bfs[nbfs] = p;
		nbfs++;
		for (int w = 0; w < n; w++)
		{
			if (C[w] && a[p][w] == 1)
			{
				PushQ(w);
				C[w] = 0;
			}
		}
	}
}
//cau 4.4
int dfs[100];
int ndfs = 0;
void DFS(int s)
{
	PushS(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v = -1, u = s;
	while (isEmptyS() == 0)
	{
		if (v == n)
		{
			PopS(u);
		}
		for (int v = 0; v < n; v++)
		{
			if (a[u][v] != 0 && C[v] == 1)
			{
				PushS(u);
				PushS(v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u = v;
				break;
			}
		}
	}
}
//cau 4.5
void Search_by_BFS(int x, int v)
{
	int w, p;
	PushQ(v);
	C[v] = 0;
	while (front != NULL)
	{
		PopQ(p);
		if (x == p)
		{
			cout << "Tim thay x = " << x << endl;
			return;
		}
		for (int w = 0; w < n; w++)
		{
			if (C[w] && a[p][w] == 1)
			{
				PushQ(w);
				C[w] = 0;
			}
		}
	}
}

int main()
{
	int a[MAX];
	int b[MAX];
	int choice, sp, sp_b, x, i;
	cout << "----------------  BAT TAP 4, CHUONG 5, DO THI  ---------------------" << endl;
	cout << "1. Khoi tao MA TRAN KE rong" << endl;
	cout << "2. Nhap MA TRAN KE tu file text " << endl;
	cout << "3. Nhap MA TRAN KE" << endl;
	cout << "4. Xuat MA TRAN KE" << endl;
	cout << "5. Duyet do thi theo chieu rong BFS - DSLK" << endl;
	cout << "6. Duyet do thi theo chieu sau DFS - DSLK	" << endl;
	cout << "7. Tim dinh co gia tri x theo BFS" << endl;
	cout << "8. Thoat" << endl;
	do
	{
		cout << "\n Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			initGraph();
			cout << "Ban vua khoi tao MA TRAN KE rong thanh cong !\n";
			break;
		case 2:
			inputGraphFromText();
			cout << "Ban vua nhap MA TRAN KE tu file: \n";
			outputGraph();
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 5:
			InitQueue();
			InitC();
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			nbfs = 0;
			BFS(x);
			cout << "Thu tu dinh sau khi duyet BFS: " << endl;
			output(bfs, n);
			break;
		case 6:
			InitStack();
			InitC();
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			ndfs = 0;
			DFS(x);
			cout << "Thu tu dinh sau khi duyet DFS: " << endl;
			output(dfs, n);
			break;
		case 7:
			cout << "Vui long nhap gia tri x can tim: " << endl;
			cin >> x;
			Search_by_BFS(x, 0);
			break;
		case 8:
			cout << "GOODBYE ................!" << endl;
			break;
		default:
			break;
		}
	} while (choice != 8);
	return 0;
}
