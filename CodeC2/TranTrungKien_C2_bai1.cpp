//Bai 1 chuong 2 : Danh sach dac
#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX 100

//cau 1.1 khai bao phan tu
int n;
int a[MAX];

//cau 1.2 Nhap vao 
void input (int a[] , int &n)
{
	cout<<"Nhap vao so luong phan tu cua danh sach: ";
	cin>>n;
	cout<<"Nhap vao cac phan tu cua danh sach: ";
	for(int i=0; i<n; i++)
	{
		cout<<"a["<<i<<"]=";
		cin>>a[i];
	}
}

//cau 1.3
void output ( int a[] , int n )
{
	for(int i=0; i<n; i++)
	{
		cout<<a[i]<<" ";

	}
	cout<<endl;
}

//cau 1.4 tim 1 phan tu cua danh sach

int search (int n , int a[] , int x  )
{
	int i=0;
	while (i<n && a[i]!=x)
	{
		i++;
		if (i == n)
			return -1;
	}
	return i;
}

//cau 1.5 chen 1 phan tu vao cuoi danh sach

int insert_last(int a[], int &n, int x)
{
	if (n<MAX)
	{
		a[n] = x;
		n++;
		return 1;
	}
	return 0;
}

//cau 1.6 xoa pha tu cuoi danh sach

int delete_last(int a[], int &n)
{
	if(n>=0)
	{	
		n--;
		return 1;
	}
	return 0;
}

//cau 1.7 xoa phan tu thu i cua danh sach
int delete_i(int a[], int &n, int i)
{
	if(i>=0 && i<n)
	{
		for(int j=i; j<n; j++)
		{
			a[j]=a[j+i];
		}
		n--;
		return 1;
	}
	return 0;
}

//cau 1.8 tim 1 phan tu trong danh sach, neu tim thay xoa phan tu do
int search_delete(int a[], int x, int &n)
{
	for (int i=0; i<n; i++)
	{
		if (a[i] == x)
		{
			delete_i(a,n,i);
			return 1;
		}
	}
	return 0;
}

int main()
{
	int chon=0;
	int x,i;
	system("cls");
	cout<<" ------- BAI TAP 1, CHUONG 1, DANH SACH DAC -------"<<endl;
	cout<<" 1. Nhap danh sach "<<endl;
	cout<<" 2. Xuat danh sach "<<endl;
	cout<<" 3. Tim phan tu "<<endl;
	cout<<" 4. Them 1 phan tu vao cuoi danh sach "<<endl;
	cout<<" 5. Xoa phan tu cuoi danh sach "<<endl;
	cout<<" 6. Xoa phan tu tai vi tri "<<endl;
	cout<<" 7. Tim phan tu tai dia chi x sau do xoa phan tu do "<<endl;
	cout<<" 8. Thoat "<<endl;

	do
	{
		cout<<" Vui long chon so de thuc hien : ";
		cin>>chon;
		switch (chon)
		{
			case 1:
				input(a, n);
				cout<<" Ban vua nhap danh sach thanh cong \n";
				break;
			case 2:
				output(a, n);
				cout<<" Danh sach ban vua nhap \n" ;
				break;
			case 3:
				cout<<" Nhap x vua tim \n ";
				cin>>x;
				i=search (n,a,x);
				if(i==-1)
					cout<<" Tim khong thay ";
				else
					cout<<" Tim thay tai vi tri "<<i<<endl;
				break;
			case 4:
				cout<<" Nhap x can them vao cuoi danh sach :";
				cin>>x;
				i= insert_last(a,n,x);
				if(i==0)
				{
					cout<<" Danh sach da day, khong the chen ";
				}
				else
				{
					cout<<" Da them phan tu "<<i<< " vao cuoi danh sach "<<endl;
					cout<<" Danh sach sau khi them : ";
					output (a,n);
				}
				break;
			case 5:
				i=delete_last(a,n);
				if(i>0)
				{
					cout<<" Xoa thanh cong "<<endl;
					cout<<" Danh sach sau khi xoa la:\n ";
					output(a,n);
				}
				else
					cout<<"Danh sach rong khong co phan tu de xoa: ";
				break;
			case 6:
				cout<<" Vui long nhap vi tri can xoa ";
				cin>>i;
				i=delete_i(a,n,i);
				if(i==1)
				{
					cout<<" Xoa thanh cong "<<endl;
					cout<<" Danh sach sau khi xoa la : "<<endl;
					output(a,n);
				}
				else
					cout<<" Khong co phan tu nao de xoa : "<<endl;
				break;
			case 7:
				cout<<" Vui long nhap gia tri can xoa "<<endl;
				cin>>x;
				i=search_delete(a,x,n);
				if(i==1)
				{
					cout<<" Xoa thanh cong phan tu co gia tri x= "<<x<<endl;
					cout<<" Danh sach sau khi xoa la: \n ";
					output(a,n);
				}
				else
					cout<<"Khong co phan tu nao de xoa "<<endl;
				break;
			case 8:
				cout<<" Bái bai <3 ";
				break;
			default:
				break;
		}
	}while (chon!=8);
	system("pause");
	return 0;
}