//Chuong 4- bai 1
#include <iostream>
using namespace std;

#define COUNT 10

struct node {
	int info;
	node* left;
	node* right;
};
node* root;

void init()
{
	root = NULL;
}

int insertNode(node*& p, int x)
{
	if (p == NULL)
	{
		p = new node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if (p->info == x)
			return 0;
		else
			if (p->info > x)
				return insertNode(p->left, x);
			else
				return insertNode(p->right, x);
	}
}

node* search(node* p, int x)
{
	if (p != NULL)
	{
		if (p->info == x)
			return p;
		else
			if (x > p->info)
				return search(p->right, x);
			else
				return search(p->left, x);

	}
	return NULL;
}

void tim(node*& p, node*& q)
{
	if (p->left == NULL)
	{
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		tim(p, q->left);
}
int xoa(node*& k, int x)
{
	if (k == NULL)
		return 0;
	if (k->info == x)
	{
		node* p = k;
		if (k->left == NULL)
			k = k->right;
		else
			if (k->right == NULL)
				k = k->left;
			else
				tim(p, k->right);
		delete p;
		return 1;
	}
	if (k->info < x)
		return xoa(k->right, x);
	if (k->info > x)
		return xoa(k->left, x);
}

void duyetLNR(node* p)
{
	if (p != NULL)
	{
		duyetLNR(p->left);
		cout << p->info << " ";
		duyetLNR(p->right);
	}
}

void duyetNLR(node* p)
{
	if (p != NULL)
	{
		cout << p->info << " ";
		duyetNLR(p->left);
		duyetNLR(p->right);
	}
}

void duyetLRN(node* p)
{
	if (p != NULL)
	{
		duyetLRN(p->left);
		duyetLRN(p->right);
		cout << p->info << " ";
	}

}
void print(node* p, int space)
{
	if (p == NULL)
		return;
	space += COUNT;
	print(p->right, space);
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << p->info << "\n";
	print(p->left, space);
}
void processTree()
{
	print(root, 0);
}
int main()
{
	int choose;
	int x, i;
	node* p;
	system("cls");
	cout << "1. khoi tao cay NPTK rong\n";
	cout << "2. them phan tu vao cay NPTK\n";
	cout << "3. tim phan tu co gia tri x\n";
	cout << "4. xoa phan tu co gia tri x\n";
	cout << "5. duyet cay theo LNR\n";
	cout << "6. duyet cay theo NLR\n";
	cout << "7. duyet cay theo LRN\n";
	cout << "8.Xuat cay\n";
	cout << "9.Thoat\n";
	do {
		cout << "Nhap so thu tu muon thuc hien: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			init();
			cout << "Khoi tao cay thanh cong\n";
			break;
		case 2:
			cout << "Nhap gia tri can them: ";
			cin >> x;
			insertNode(root, x);
			cout << "Cay sau khi them: ";
			processTree();
			break;
		case 3:
			cout << "Nhap gia tri can tim: ";
			cin >> x;
			p = search(root, x);
			if (p != NULL)
				cout << "Tim thay x= " << x << "trong cay\n";
			break;
		case 4:
			cout << "Nhap gia tri can xoa: ";
			cin >> x;
			i = xoa(root, x);
			if (i == 0)
				cout << "khong tim thay x\n";
			else
			{
				cout << "Xoa thanh cong\n";
				cout << "cay sau khi xoa: ";
				processTree();
			}
			break;
		case 5:
			cout << "Cay duyet theo LNR la: ";
			duyetLNR(root);
			break;
		case 6:
			cout << "Cay duyet theo NLR la: ";
			duyetNLR(root);
			break;
		case 7:
			cout << "Cay duyet theo LRN la: ";
			duyetLRN(root);
			break;
		case 8:
			cout << "Cay nhi phan tim kiem: ";
			processTree();
			break;
		case 9:
			cout << "Thoat!\n";
			break;
		default:
			break;
		}
	} while (choose != 9);
	system("pause");
	return 0;
}