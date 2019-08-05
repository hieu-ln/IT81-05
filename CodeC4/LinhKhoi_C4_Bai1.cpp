#include<iostream>
using namespace std;
#define COUNT 10
struct node
{
	int info;
	node *left;
	node *right;
};
node *root;
int insert_node1(node *p,int x)
{
	if(p->info==x)
		return 0;
	else if(p->info>x)
	{
		if(p->left==NULL)
		{
			node *y=new node;
			y->info=x;
			y->left=NULL;
			y->right=NULL;
			p->left=y;
			return 1;
		}
		else
			return insert_node1(p->left,x);
	}
	else
	{
		if(p->right==NULL)
		{
			node *y=new node;
			y->info=x;
			y->left=NULL;
			y->right=NULL;
			p->right=y;
			return 1;
		}
		else
			return insert_node1(p->right,x);
	}
}
void tree_empty()
{
	root=NULL;
}
void insertnode(node *&p , int x)
{
	if(p==NULL)
	{
		p=new node;
		p->info=x;
		p->left=NULL;
		p->right=NULL;
	}
	else
	{
		if(p->info==x)
			return;
		else if(p->info>x)
			return insertnode(p->left,x);
		else
			return insertnode(p->right,x);
	}
}
void xuat(node *p, int space)
{
	if(p==NULL)
		return;
	space += COUNT;
	xuat(p->right, space);
	cout<<endl;
	for(int i=COUNT ; i<space; i++)
		cout<<" ";
	cout<<p->info<<endl;
	xuat(p->left,space);
}
void process_print()
{
	xuat(root, 0);
}

node *search(node *p, int x)
{
	while(p!=NULL)
	{
		if(p->info==x)
			return p;
		else
			if(p->info >x)
				p=p->left;
			else
				p=p->right;
	}
	return NULL;
}
node *search1(node *p, int x)
{
	if(p!=NULL)
	{
		if(p->info==x)
			return p;
		else
			if(x>p->info)
				return search(p->right,x);
			else
				return search(p->left,x);
	}
	return NULL;
}
void duyetLNR(node *p)
{
	if(p!=NULL)
	{
		duyetLNR(p->left);
		cout<<p->info<<" ";
		duyetLNR(p->right);
	}
}
void duyetNLR(node *p)
{
	if(p!=NULL)
	{
		cout<<p->info<<" ";
		duyetNLR(p->left);
		duyetNLR(p->right);
	}
}
void duyetLRN(node *p)
{
	if(p!=NULL)
	{
		duyetLRN(p->left);
		duyetLRN(p->right);
		cout<<p->info<<" ";
	}
}
void searchstandfor(node *&p, node *&q)
{
	if(q->left==NULL)
	{
		p->info=q->info;
		p=q;
		q=q->right;
	}
	else
		searchstandfor(p,q->left);
}
int delete1(node *&T, int x)
{
	if(T == NULL)
		return 0;
	if(T->info==x)
	{
		node *p=T;
		if(T->left==NULL)
			T=T->right;
		else if( T->right ==NULL)
			T=T->left;
		else
			searchstandfor(p,T->right);
		delete p;
		return 1;
	}
	if(T->info<x)
		return delete1(T->right,x);
	if (T->info>x)
		return delete1(T->left,x);
}
int demnode( node *p)
{
	if(p==NULL)
		return 0;
	else
		return 1+ demnode(p->left)+demnode(p->right);
}
int timMAX( node *p)
{
	if(p==NULL)
		return INT_MIN;
	else
	{
		while(p->right!=NULL)
			p=p->right;
		return p->info;
	}
}
int countnodelefttree(node *p)
{
	if(p==NULL || p->left==NULL)
		return 0;
	else
		return demnode(p->left);
}
int menu()
{
	int choose = 0;
	cout << "\n====================\n";
	cout<<"Moi nhap gia tri:\n";
	cout<<"0. Thoat\n";
	cout<<"1. Khoi tao cay rong\n";
	cout<<"2. Them 1 phan tu vao cay\n";
	cout<<"3. Xuat cay\n";
	cout<<"4. Tim 1 phan tu trong cay\n";
	cout<<"5. Xoa 1 nut trong cay\n";
	cout<<"6. Duyet cay theo thu tu NLR\n";
	cout<<"7. Duyet cay theo thu tu LNR\n";
	cout<<"8. Duyet cay theo thu tu LRN\n";
	cout<<"9. Dem cay co bao nhieu node\n";
	cout<<"10. Tim gia tri lon nhat trong cay\n";
	cout<<"11. Dem so node trai cua cay\n";
	cout<<"============================\n";
	cout<<"Chon chuc nang: ";
	cin>>choose;
	return choose;
}
int main()
{
	int choose, x, t;
	do{
		choose = menu();
		switch(choose)
		{
		case 0:
			cout<<"Nhan nut bat ki de thoat\n";
			break;
		case 1:
			tree_empty();
			cout<<"Khoi tao thanh cong!\n";
			break;
		case 2:
			cout<<"Nhap phan tu muon them vao cay: ";
			cin>>x;
			insertnode(root,x);
			break;
		case 3:
			process_print();
			break;
		case 4:
			cout<<"Nhap 1 phan tu muon tim trong cay: ";
			cin>>x;
			if(search(root,x)!=NULL)
				cout<<"Tim thay tai dia chi "<<search(root,x)<<endl;
			else
				cout<<"Tim khong thay\n";
			break;
		case 5:
			cout<<"Nhap 1 phan tu muon xoa trong cay: ";
			cin>>x;
			t= delete1(root,x);
			if(t == 1)
				cout<<"Xoa thanh cong\n";
			else
				cout<<"Xoa that bai\n";
			break;
		case 6:
			cout<<"Duyet theo NLR:\n";
			duyetNLR(root);
			cout<<endl;
			break;
		case 7:
			cout<<"Duyet theo LNR:\n";
			duyetLNR(root);
			cout<<endl;
			break;
		case 8:
			cout<<"Duyet theo LRN:\n";
			duyetLRN(root);
			cout<<endl;
			break;
		case 9:
			cout<<"So node trong cay: "<<demnode(root)<<endl;
			break;
		case 10:
			if(timMAX(root) != INT_MIN)
			cout<<"Gia tri lon nhat cua cay la: "<<timMAX(root)<<endl;
			else
				cout<<"Cay rong"<<endl;
			break;
		case 11:
			cout<<"So node cay trai la: "<<countnodelefttree(root)<<endl;
			break;
		default:
			cout << "Chuc nang khong ton tai\n";
			break;
		}
	}while(choose!=0);
	system("pause");
	return 0;
}
