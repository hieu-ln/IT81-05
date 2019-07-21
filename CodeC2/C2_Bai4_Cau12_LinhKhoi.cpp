#include<iostream>
using namespace std;
struct node
{
	int info;
	node *next, *previous;
};
node *first, *last;
void init()
{
	first = NULL;
	last = NULL;
}
void process_list()
{
	node *p;
	p = first;
	while (p!=NULL)
	{
		cout<<p->info<<endl;
		p=p->next;
	}
}
void process_list_begin_last()
{
	node *p;
	p = last;
	while (p!=NULL)
	{
		cout<<p->info<<endl;
		p=p->previous;
	}
}
node *search(int x)
{
	node *p;
	p=first;
	while ((p!=NULL) && (p->info!=x))
		p=p->next;
	return p;
}
node *search_list_begin_last(int x)
{
	node *p;
	p= last;
	while((p!=NULL) && (p->info!=x))
		p=p->previous;
	return p;
}
void insert_first(int x)
{
	node *p;
	p= new node;
	p->info = x;
	p->next = first;
	p->previous = NULL;
	if(first != NULL)
		first->previous=p;
	else
		last=p;
	first=p;
}
void insert_last(int x)
{
	node *p;
	p= new node;
	p->info = x;
	p->next = NULL;
	p->previous = last;
	if(last!=NULL)
		last->next=p;
	else
		first= p;
	last=p;
}
int delete_first()
{
	if(first!=NULL)
	{
		node *p = first;
		first=first->next;
		delete p;
		if(first!=NULL)
			first->previous=NULL;
		else
			last =NULL;
		return 1;
	}
	return 0;
}
int delete_last()
{
	if(last!=NULL)
	{
		node *p = last;
		last=last->previous;
		if(last!=NULL)
			last->next=NULL;
		else
			first =NULL;
		delete p;
		return 1;
	}
	return 0;
}
int find_and_delete(int x)
{
	node *p =search(x);
	if(p!=NULL)
	{
		if(p==first)
		{
			if(delete_first())
				return 1;
			else
				return 0;
		}
	
		else
			if(p==last)
			{
				if(delete_last())
					return 1;
				else
					return 0;
			}
	
		else
		{
			node *q;
			q=p->previous;
			q->next=p->next;
			(p->next)->previous=q;
			delete p;
			return 1;
		}
	}
	return 0;
}
int insert(int y, int x)
{
	node *p= new node;
	p->info=y;
	if(p==first)
	{
		insert_first(x);
		return 1;
	}
	else
	{
		node *n= new node ;
		
		n->info=x;
		n->next=p;
		p->previous=n;
		return 1;
	}
	return 0;
}
int menu()
{
	int choose = 0;

	cout << "====================\n";
	cout << " 0. Thoat\n";
	cout << " 1. Khoi tao\n";
	cout << " 2. Xuat\n";
	cout << " 3. Them vao dau\n";
	cout << " 4. Them vao cuoi\n";
	cout << " 5. Tim kiem\n";
	cout << " 6. Xoa o dau\n";
	cout << " 7. Xoa o cuoi\n";
	cout << " 8. Tim va xoa\n";
	cout << " 9. Tim va them\n";
	cout << "====================\n";
	cout << "Chon chuc nang: ";
	cin >> choose;

	return choose;
}
int main()
{
	int choose, x, m, n, y,a;

	do{
		choose = menu();

		switch(choose)
		{
		case 0:
			cout << "Nhan nut bat ki de thoat => ";
			break;
		//---------------------------------------------
		case 1:
			init();
			cout << "Khoi tao thanh cong\n";
			break;
		//---------------------------------------------	
		case 2:
			cout << "Danh sach lien ket vua khoi tao la:\n";
			process_list_begin_last();
			cout << endl;
			break;
		//---------------------------------------------
		case 3:
			cout << "Nhap gia tri can them vao dau: ";
			cin >> x;
			insert_first(x);
			break;
		//---------------------------------------------
		case 4:
			cout << "Nhap gia tri can them vao cuoi: ";
			cin >> n;
			insert_last(n);
			break;
		//---------------------------------------------
		case 5:
			cout << "Nhap gia tri can tim: ";
			cin >> m;
			if(search(m) == NULL)
				cout << "Gia tri can tim khong co trong danh sach lien ket\n";
			else
				cout << "Dia chi cua gia tri can tim la: " << int(search(m)) << endl;
			break;
		//---------------------------------------------
		case 6:
			if(delete_first() == 1)
				cout << "Xoa thanh cong\n";
			else
				cout << "Xoa khong thanh cong\n";
			break;
		//---------------------------------------------
		case 7:
			if(delete_last() == 1)
				cout << "Xoa thanh cong\n";
			else
				cout << "Xoa khong thanh cong\n";
			break;
		//---------------------------------------------
		case 8:
			cout << "Nhap gia tri can tim va xoa: ";
			cin >> y;
			if(find_and_delete(y) == 1)
				cout << "Xoa thanh cong\n";
			else
				cout << "Xoa khong thanh cong\n";
			break;
		case 9:
			
			cout << "Nhap gia tri can tim: ";
			cin >> a;
			cout << "Nhap gia tri can them: ";
			cin >> y;
			if(insert(a,y) == 1)
				cout << "Them thanh cong\n";
			else
				cout << "Them khong thanh cong\n";
			break;
		//---------------------------------------------
		default:
			cout << "Chuc nang khong ton tai\n";
			break;
		}
	}while(choose != 0);
	
	return 0;
}