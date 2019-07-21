//Chuong 2 - Cau truc du lieu co ban - bai 10 - Luc Tuan Kien - nhom 5 - IT81
#include <iostream>
using namespace std;

//cau 10.1 Khai bao cau truc stack
struct Node
{
	int info;
	Node *link;
};
Node *sp;
//Cau 10.2 Khoi tao stack rong
void init()
{
	sp = NULL;
}
//Cau 10.3 Kiem tra stack rong
int isEmpty()
{
	if(sp == NULL)
		return 1;
	return 0;
}
//Cau 10.4 Push (them phan tu)
void Push(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}
//Cau 10.5 Pop(Lay phan tu ra)
int Pop(int &x)
{
	if(sp != NULL)
	{
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
//Cau 10.6 Xuat stack
void xuat()
{
	Node *p = sp;
	do{
		cout << p->info << "  ";
		p = p->link;
	} while(p!= NULL);
	cout << endl;
}
//Cau 10.7 Chuyen doi nhi phan
int nhiphan(int x)
{
	int a;
	if(x == 0)
		return 0;
	else
	{
		a = x % 2;
		return nhiphan(x/2)*10 + a;
	}
}
int main()
{
	int choose,x;
	system("cls");
	cout << "1.Khoi tao stack rong\n";
	cout << "2. Kiem tra stack rong\n";
	cout << "3. Them 1 phan tu vao stack\n";
	cout << "4. Xoa 1 phan tu trong stack\n";
	cout << "5. Xuat stack ra man hinh\n";
	cout << "6. Doi 1 gia tri trong stack sang he nhi phan\n";
	cout << "7. Thoat\n";
	do{
		cout << "Nhap so thu tu thao tac muon thuc hien: ";
		cin >> choose;
		switch(choose)
		{
		case 1:
			init();
			cout << "Khoi tao stack thanh cong!\n";
			break;
		case 2:
			if(isEmpty() == 1)
				cout << "Stack hien tai dang rong\n";
			else
				cout << "Stack khong rong\n";
			break;
		case 3:
			cout << "Nhap gia tri phan tu them vao: ";
			cin >> x;
			Push(x);
			cout << "Stack sau khi them: ";
			xuat();
			break;
		case 4:
			cout << "Nhap phan tu muon lay ra: ";
			cin >> x;
			Pop(x);
			cout << "Stack sau khi lay ra: ";
			xuat();
			break;
		case 5:
			cout << "Stack hien tai la: ";
			xuat();
			break;
		case 6:
			cout << "Nhap gia tri trong stack muon chuyen nhi phan: ";
			cin >> x;
			cout << x << " o he nhi phan la: " << nhiphan(x) << endl;
			break;
		case 7:
			cout << "Ban chon thoat!\n";
			break;
		default:
			break;
		}
	}while(choose!= 7);
	return 0;
}