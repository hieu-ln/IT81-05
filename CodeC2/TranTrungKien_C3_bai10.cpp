//Chuong 2: Cau truc du lieu co ban: cau 5 - Tran Trung Kien - nhom 5 - it81
#include <iostream>
using namespace	std;

#define MAX 100
int a[MAX];
int sp;

 void init(int a[],int &sp)
{
	sp = -1;
}
 
 int isEmpty (int a[], int &sp)
 {
 	if (sp==-1)
 		return 1;
	else 
		return 0;
 }
 
 int isFull(int a[], int sp)
 {
 	if (sp== MAX-1)
 		return 1;
	else
		return 0;
 }
 
int push(int a[], int &sp, int n)
{
	if(sp < MAX - 1)
	{
		a[++sp] = n;
		return 1;
	}
	return 0;
}
 
 int pop(int a[], int &sp, int n)
 {
 	if(sp!=-1)
 	{
 		n=a[sp--];
 		return 1;
 	}
 	else	
 		return 0;
 }
 //ham nhi phan
 int binary(int x)
 {
 	int a;
 	if(x==0)
 		return 0;
	else
	{
		a=x%2;
		return binary(x/2)*10+a;
	}
 }
 //xuat stack
 void xuat(int a[], int &sp)
 {
 	for(int i=0; i<sp+1; i++)
 		cout<<a[i]<<" ";
	cout <<endl;
 }
 //thap ha noi
 void Tower(int n , char a, char b, char c ){
    if(n==1){
        cout<<"\t"<<a<<"-------"<<c<<endl;
        return;
    }
    Tower(n-1,a,c,b);
    Tower(1,a,b,c);
    Tower(n-1,b,a,c);
    }
 
 int main()
 {
 	cout<<"1. Khoi tao stack rong"<<endl;
 	cout<<"2. Kiem ta stack rong"<<endl;
 	cout<<"3. Kiem tra stack day"<<endl;
 	cout<<"4. Them phan tu vao stack"<<endl;
 	cout<<"5. Xoa phan tu trong stack"<<endl;
 	cout<<"6. Xuat stack"<<endl;
 	cout<<"7. Doi 1 gia tri trong stack sang he nhi phan "<<endl;
 	cout<<"8. Thap ha noi"<<endl;
 	cout<<"9. Thoat"<<endl;
	int a[MAX];
	int choose, sp, kq, n;
 	char a='A', b='B', c='C';
	do{
		cout<<"Nhap so phan tu can thuc hien ";
		cin>>choose;
		switch(choose)
		{
		case 1:
			init(a,sp);
			cout<<"Khoi tao stack thanh cong: ";
			break;
		case 2:
			if(isEmpty(a,sp)==1)
				cout<<"Stack rong";
			cout<<"Stack khong rong";
			break;
		case 3:
			if(isFull(a,sp)==1)
				cout<<"Stack day";
			cout<<"Stack chua day";
			break;
		case 4:
			cout << "Nhap gia tri can them: ";
			cin >> n;
			kq = push(a,sp,n);
			cout << "Stack sau khi them la: ";
			xuat(a,sp);
			break;
		case 5:
			cout << "Nhap gia tri can xoa: ";
			cin>>n;
			kq = pop(a,sp,n);
			cout << "Stack sau khi lay " << n << " ra: ";
			xuat(a,sp);
			break;
		case 6:
			if(isEmpty(a,sp)==1)
				cout<<"Stack khong co";
			xuat(a,sp);
			break;
		case 7:
			cout<<"Nhap gia tri can doi: ";
			cin>>n;
			cout<<"Gia tri "<<n<<"trong stack sang he nhi phan la: "<<binary(n)<<endl;
			break;
		case 8:
			cout<<"Nhap do cai cua thap Ha Noi ";
    		cin>>n;
    		Tower(n,a,b,c);
		case 9:
			cout<<"Chon thoat: ";
			break;
		default:
			break;
		}
	}while(choose!=7);
	return 0;
 }
