#include <iostream>
using namespace std;
int sp;

typedef int item;
struct Node {
	item data;
	Node *next;
};
typedef Node *List;

void Init(List &L);
int len(List L);
Node *Make_Node(Node *P, item x);
void Del_k(List &L, item &x, int k);
void Insert_first(List &L, item x);
void Insert_k(List &L, item x, int k);
void Input(List &L);
void Output(List L);
int Search(List L, item x);
void Del_x(List &L, item x);

void Input(List &L)
{
	int i = 0;
	item x;
	do
	{
		i++;
		cout << "Nhap phan tu thu " << i << " (stop = 0) : ";
		cin >> x;
		if (x != 0)
			Insert_k(L, x, len(L) + 1);
	} while (x != 0);
}

void Output(List L)
{
	Node *P = L;
	while (P != NULL)
	{
		cout << P->data;
		P = P->next;
	}
	cout << endl;
}

int main()
{
	List L;
	Init(L);
	Input(L);
	Output(L);

	int lua_chon;
	cout << "Moi ban chon phep toan voi DS LKD:\n";
	cout << "\n1: Chen phan tu x vao vi tri k trong DS";
	cout << "\n2: Tim mot phan tu trong DS";
	cout << "\n3: Xoa phan tu tai vi tri k";
	cout << "\n4: Xoa phan tu x trong DS";
	cout << "\n5: Thoat";
	do
	{
		cout << "\nBan chon: ";
		cin >> lua_chon;
		cout << endl;
		switch (lua_chon)
		{
		case 1:
		{
			item x;
			int k;
			cout << "Nhap phan tu can chen vao DS: ";
			cin >> x;
			cout << "Nhap vi tri can chen: ";
			cin >> k;
			Insert_k(L, x, k);
			cout << "DS sau khi chen:\n";
			Output(L);
			break;
		}
		case 2:
		{
			item x;
			cout << "Moi ban nhap vao phan tu can tim: ";
			cin >> x;
			int k = Search(L, x);
			if (k) cout << "Tim thay " << x << " trong DS tai vi tri thu: " << k << endl;
			else cout << "Khong tim thay %d trong danh sach !";
			break;
		}
		case 3:
		{
			int k;
			item x;
			cout << "Nhap vi tri can xoa: ";
			cin >> k;
			Del_k(L, x, k);
			cout << "DS sau khi xoa:\n";
			Output(L);
			break;
		}
		case 4:
		{
			item x;
			cout << "Nhap phan tu can xoa: ";
			cin >> x;
			Del_x(L, x);
			cout << "DS sau khi xoa:\n";
			Output(L);
			break;
		}
		case 5: break;
		}
	} while (lua_chon != 5);

	return 0;
}



void Init(List &L)
{
	L = NULL;
}
Node *Make_Node(Node *P, item x)
{
		P = (Node *)malloc(sizeof(Node)); 
		P->next = NULL; 
		P->data = x;
		return P;
}
void Insert_first(List &L, item x)
{
	Node *P;
	P = Make_Node(P, x); 
	P->next = L; 
	L = P;
}
int len(List L)
{
	Node *P = L;
	int i = 0;
	while (P != NULL)
	{
		i++; 
		P = P->next;
	}
	return i;
}
void Insert_k(List &L, item x, int k)
{
	Node *P, *Q = L;
	int i = 1;
	if (k<1 || k> len(L) + 1)
		cout << "Vi tri chen khong hop le !" << endl;
	else
	{
		P = Make_Node(P, x); 
		if (k == 1) 
			Insert_first(L, x);
		else
		{
			while (Q != NULL && i != k - 1) 
			{
				i++;
				Q = Q->next;
			}
			P->next = Q->next;
			Q->next = P;
		}
	}
}

int Search(List L, item x)
{
	Node *P = L;
	int i = 1;
	while (P != NULL && P->data != x)
	{
		P = P->next;
		i++;
	}
	if (P != NULL) return i;
	else return 0;
}
void Del_frist(List &L, item &x)
{
	x = L->data;
	L = L->next;
}
void Del_k(List &L, item &x, int k) 
{
	Node *P = L;
	int i = 1;
	if (k<1 || k>len(L))
		cout << "Vi tri xoa khong hop le !" << endl;
	else
	{
		if (k == 1) Del_frist(L, x);
		else
		{
			while (P != NULL && i != k - 1) 
			{
				P = P->next;
				i++;
			}
			P->next = P->next->next;
		}
	}
}
void Del_x(List &L, item x)
{
	while (Search(L, x)) Del_k(L, x, Search(L, x));
}
