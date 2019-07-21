//Bai 3 chuong 1 : Danh sach lien ket don
#include<iostream>
#include <stdio.h>

using namespace std;

//cau 3.1: khai bao cau truc danh sach
struct Node {
	int info;
	Node *link;
};
Node *first;

//3.2 khoi tao danh sach rong
void Init()
{
	first=NULL;
}
//cau 3.3: xuat cac phan tu trong danh sach
void Process_list()
{
	Node *p;
	p=first;
	while (p!=NULL){
		cout<<p->info<< " ";
		p=p->link;
	}
	cout<<endl;
}

//cau 3.4 Tim mot phan tu trong danh sach
Node *search(int x)
{
	Node *p = first;
	while (p!=NULL && p->info !=x){
		p=p->link;
	}
	return p;
}

//cau 3.5 Them phan tu vao dau danh sach
void insert_first(int x)
{
	Node *p;
	p= new Node;
	p->info =x;
	p->link =first;
	first=p;
}

//cau 3.6 Xoa phan tu dau danh sach
int Delete_first()
{
	if(first!=NULL)
	{
		Node *p = first;
		first= first ->link;
		delete p;
		return 1;
	}
	return 0;
}

//cau 3.7 Them phan tu cuoi danh sach
void insert_last(int x)
{
	Node *p;
	p=new Node;
	p->link =NULL;
	p->info =x;
	if(first==NULL)
	{
		first=p;
	}
	else
	{
		Node *q = first ;
		while(q->link !=NULL)
		{
			q=q->link;
		}
		q->link =p;
	}
}

//cau 3.8 xoa phan tu cuoi danh sach
int Delete_last()
{
	if(first!=NULL)
	{
		Node *p, *q;
		p=first;
		q=first;
		while(p->link !=NULL)
		{
			q=p;
			p-p->link;
		}
		if (p!=first)
		{
			q->link =NULL;
		}
		else
			first=NULL;
		delete p;
		return 1;
	}
	return 0;
}

//cau 3.9 tim mot phan tu trong danh sach roi xoa 

int Search_Delete (int x)
{
	if (first !=NULL)
	{
		Node *p ,*q;
		q=first;
		p=first;
		while (p->info !=x && p->info !=NULL)
		{
			q=p;
			p=p->link;
		}
		if (p!=first && p->link!=NULL)
		{
			//phan tu giua danh sach
			if (p->link !=NULL)
				q->link = p->link;
			else
				q->link = NULL;
			delete p;
			return 1;
		}
		else if(p==first)
		{
			//phan tu dau danh sach
			first=q->link;
			delete p;
			return 1;
		}
		else if(p->link==NULL && p->info==x)
		{
			//phan tu cuoi danh sach
			q->link = NULL;
			delete p;
			return 1;
		}
		else 
			return 0;
	}
}

//ham doi gia tri 2 phan tu
void swap(Node *a, Node*b)
{
	int t=a->info;
	a->info=b->info;
	b->info=t;
}

//3.10 sap xep danh sach co thu tu tang dan 

void Sort()
{
	Node *p,*q,*min;
	//di chuyen ranh gioi cua mang sap xep va chua sap xep
	p=first;
	while (p!=NULL)
	{
		//tim phan tu nho nhat trong mang chua sap xep
		min = p;
		q=p->link;
		while (q!=NULL)
		{
			if (q->info < min->info)
				min=q;
			q=q->link;
		}
		/*doi cho phan tu nhat nhat voi phan tu dau tien*/
		swap(min,p);
		p=p->link;
	}

}

void Sort_Desc()
{
	Node *p,*q,*min;
	//di chuyen ranh gioi cua mang sap xep va chua sap xep
	p=first;
	while (p!=NULL)
	{
		//tim phan tu nho nhat trong mang chua sap xep
		min = p;
		q=p->link;
		while (q!=NULL)
		{
			if (q->info > min->info)
				min=q;
			q=q->link;
		}
		/*doi cho phan tu nhat nhat voi phan tu dau tien*/
		swap(min,p);
		p=p->link;
	}

}

int main()
{
	int choice =0;
	int x,i;
	Node *p;
	system("cls");
	cout<<"-------- Bai tap 3 Chuong 2: Danh sach lien ket dac -------- "<<endl;
	cout<<"1. Khoi tao DSLK DON rong "<<endl;
	cout<<"2. Them phan tu vao dau DSLK DON "<<endl;
	cout<<"3. Them phan tu vao cuoi DSLK DON "<<endl;
	cout<<"4. Xoa phan tu vao dau DSLK DON "<<endl;
	cout<<"5. Xoa phan tu vao cuoi DSLK DON "<<endl;
	cout<<"6. Xuat DSLK DON "<<endl;
	cout<<"7. Tim mot phan tu gia tri x trong DSLK DON "<<endl;
	cout<<"8. Tim mot phan tu gia tri x trong DSLK DON va xoa neu co"<<endl;
	cout<<"9. Sap xep DSLK DON tang dan "<<endl;
	cout<<"9. Sap xep DSLK DON giam dan "<<endl;
	cout<<"Thoat"<<endl;
	do {
		cout<<"Chon so de thuc hien :";
		cin>>choice;
		switch (choice)
		{
		case 1:
			Init ();
			cout<<"Ban vua khoi tao thanh cong \n :";
			break;
		case 2:
			cout<<"Vui long nhap gia tri x= ";
			cin>>x;
			insert_first(x);
			cout<<"Danh sach sau khi them la: ";
			Process_list();
			break;
		case 3:
			cout<<"Vui long nhap gia tri x= ";
			cin>>x;
			insert_last(x);
			cout<<"Danh sach sau khi them la: ";
			Process_list();
			break;
		case 4:
			i=Delete_first();
			if(i==0)
				cout<<"Danh sach rong khong the xoa "<<x<<endl;
			else
			{
				cout<<"Da xoa thanh cong phan tu dau cua DSLK DON !"<<endl;
				Process_list();
			}
			break;
		case 5:
			i=Delete_last();
			if(i==0)
				cout<<"Danh sach rong khong the xoa "<<x<<endl;
			else
			{
				cout<<"Da xoa thanh cong phan tu dau cua DSLK DON !"<<endl;
				Process_list();
			}
			break;
		case 6:
			cout<<" Danh sach hien tai la :";
			Process_list();
			break;
		case 7:
			cout<<"Vui long nhap gia tri can tim";
			cin>>x;
			p=search(x);
			if(p!=NULL)
			{
				cout<<"Tim thay phan tu co gia tri "<<x<<endl;
			}
			else 
				cout<<"Khong tim thay phan tu co gia tri "<<x<<endl;
			break;
		case 8: 
			cout<<"Vui long nhap gia tri can tim ";
			cin>>x;
			i=Search_Delete (x);
			if(i==1)
			{
				cout<<"Tim thay x "<<x<<" va xoa thanh cong "<<endl;
				cout<<"Danh sach sau khi xoa ";
				Process_list();
			}
			else
				cout<<"Khong tim thay phan tu co gia tri "<<x<<endl;
			break;
		case 9:
			Sort();
			cout<<"Danh sach sau khi sap xep tang dan la: ";
			Process_list();
			break;
		case 10:
			Sort_Desc();
			cout<<"Danh sach sau khi sap xep tang dan la: ";
			Process_list();
			break;
		case 11:
			cout<<"Bái bai <3 "<<endl;	
		default:
			break;
		}
	}while(choice!=11);
	system("pause");
	return 0;
}