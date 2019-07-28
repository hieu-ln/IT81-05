#include <iostream>
#include <ctime>
#include <stdio.h>
using namespace std;

#define MAX 5000

//cau 1.1
int a[MAX];
int n;

//cau 1.2 Nhap danh sach ngau nhien
void init(int a[], int &n)
{
	cout<<"Nhap vao so luong phan tu cua danh sach ";
	cin>>n;
	for (int i=0; i<n; i++)
	{
		a[i]=rand() % 10000+1;
	}
	cout<<"Danh sach da duoc nhap ngau nhien " <<endl;
	for(int i=0; i<n; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

//Nhap danh sach bang tay
void input(int a[], int &n)
{
	cout<<"Nhap vao so luong phan tu cua danh sach ";
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cout<<"a["<<i<<"]";
		cin>>a[i];
	}
}

//Xuat danh sach
void output(int a[],int n)
{
	for (int i=0; i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void CopyArray (int a[], int b[], int n)
{
	for(int i=0; i<n; i++)
	{
		b[i]=a[i];
	}
}

//1.4 Insertion Sort
void InsertionSort(int a[], int n)
{
	int i, key, j;
	for(int i=1; i<n; i ++)
	{
		key=a[i];
		j=i-1;
		while (j>=0 && key<a[i])
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
	}
}

//Ham doi gia tri 
void Swap (int &a, int &b)
{
	int t=a;
	a=b;
	t=b;
}

//1.5 Selection Sort
void SelectionSort(int a[], int n)
{
	int i,j,min_idx;
	for(int i=0; i<n-1;i++)
	{
		min_idx=i;
		for(int j=1+i; j<n; j++)
			if (a[j] < a[min_idx])
				min_idx=j;
		Swap(a[min_idx], a[i]);
	}
}

//1.6 Interchange Sort
void InterchangeSort(int a[], int n)
{
	for (int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(a[i] > a[j])
				Swap(a[i],a[j]);
}

//1.7 Bubble Sort
void BubbleSort(int arr[], int n)
{
	int i, j;
	bool haveSwap= false;
	for(int i=0; i<n-1; i++){
		haveSwap= false;
		for(int j=0; j<n-i-1; j++){
			if(arr[j] > arr[j+1]){
				Swap(arr[j],arr[j+1]);
				haveSwap=true;
			}
		}
		if(haveSwap==false){
			break;
		}
	}
}

//1.8 Quick Sort
void QuickSort(int a[], int left, int right)
{
	int x=a[(left+right)/2];
	int i=left;
	int j=right;
	while (i<j)
	{
		while(a[i]<x)
			i++;
		while (a[j]>x)
			j--;
		if(i<=j)
		{
			Swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	if(left<j)
		QuickSort(a,left,j);
	if(i<right)
		QuickSort(a,i,right);
}

//1.9 Heap Sort
void Shift(int a[], int i, int n)
{
	int j=2*i+1;
	if(j>=n)
		return;
	if(j+1<n)
		if(a[j]<a[j+1])
			j++;
	if(a[i]>=a[j])
		return;
	else
	{
		int x=a[i];
		a[i]=a[j];
		a[j]=x;
		Shift(a,j,n);
	}
}

void HeapSort(int a[], int n)
{
	int i=n/2-1;
	while (i>=0){
		Shift(a,i,n);
		i--;
	}
	int right=n-1;
	while(right > 0)
	{
		Swap (a[0],a[right]);
		right--;
		if(right>0)
			Shift(a,0,right);
	}
}

//1.10 tim kiem tuan tu
void SearchSequence (int a[], int n, int x)
{
	int i=0;
	while(i<n && a[i]!=x)
		i++;
	if(i==n)
		cout<<"Khong tim thay ";
	else
		cout<<"Tim thay tai vi tri i="<<i;
}

//1.11 tim kiem nhi phan
int BinarySearch(int a[], int l,int r, int x)
{
	int mid=0;
	if(r>=1){
		 mid=l+(r-1)/2;
	if(a[mid]==x)
		return mid;
	if(a[mid]>x)
		return BinarySearch(a,l,mid-1,x);
	return BinarySearch(a,mid+1,r,x);
	}
	return -1;
}

int main()
{
	int b[MAX];
	clock_t start;
	double duration;
	int choice, x, i;
	system("cls");
	cout<<"---------Bai tap 1 Chuong 3 Xep Thu Tu va Tim Kiem---------"<<endl;
	cout<<"0. Khoi tao danh sach ngau nhien"<<endl;
	cout<<"1. Nhap danh sach"<<endl;
	cout<<"2. Xuat danh sach"<<endl;
	cout<<"3. Xep thu tu danh sach SELECTION SORT"<<endl;
	cout<<"4. Xep thu tu danh sach INSERTION SORT"<<endl;
	cout<<"5. Xep thu tu danh sach BUBBLE SORT"<<endl;
	cout<<"6. Xep thu tu danh sach INTERCHANGE SORT"<<endl;
	cout<<"7. Xep thu tu danh sach QUICK SORT"<<endl;
	cout<<"8. Xep thu tu danh sach HEAP SORT"<<endl;
	cout<<"9. Tim kiem phan tu x bang TIM KIEM TUAN TU"<<endl;
	cout<<"10.Tim kiem phan tu x bang TIM KIEM NHI PHAN"<<endl;
	cout<<"11. Thoat"<<endl;
	do
	{
		cout<<"Vui long chon so thuc hien :";
		cin>>choice;
		switch (choice)
		{
		case 0:
				init(a,n);
				break;
		case 1:
				input(a,n);
				break;
		case 2:
				output(a,n);
				break;
		case 3:
				CopyArray(a,b,n);
				start=clock();
				SelectionSort(b,n);
				duration= (clock() - start) / (double) CLOCKS_PER_SEC;
				if(n<100)
				{
					cout<<"DS sau khi xep thu tu voi SELECTION SORT la: "<<endl;
					output(b,n);
				}
				if(duration > 0)
					cout<<"Thoi gian SELECTION SORT"<<duration*1000000<<endl;
				break;
		case 4:
				CopyArray(a,b,n);
				start=clock();
				InsertionSort(b,n);
				duration= (clock() - start) / (double) CLOCKS_PER_SEC;
				if(n<100)
				{
					cout<<"DS sau khi xep thu tu voi INSERTION SORT la: "<<endl;
					output(b,n);
				}
				if(duration > 0)
					cout<<"Thoi gian INSERTION SORT"<<duration*1000000<<endl;
				break;
		case 5:
				CopyArray(a,b,n);
				start=clock();
				BubbleSort(b,n);
				duration= (clock() - start) / (double) CLOCKS_PER_SEC;
				if(n<100)
				{
					cout<<"DS sau khi xep thu tu voi BUBBLE SORT la: "<<endl;
					output(b,n);
				}
				if(duration > 0)
					cout<<"Thoi gian BUBBLE SORT"<<duration*1000000<<endl;
				break;
		case 6:
				CopyArray(a,b,n);
				start=clock();
				InterchangeSort(b,n);
				duration= (clock() - start) / (double) CLOCKS_PER_SEC;
				if(n<100)
				{
					cout<<"DS sau khi xep thu tu voi INTERCHAGE SORT la: "<<endl;
					output(b,n);
				}
				if(duration > 0)
					cout<<"Thoi gian INTERCHANGE SORT"<<duration*1000000<<endl;
				break;
		case 7:
				CopyArray(a,b,n);
				start=clock();
				QuickSort(b,0,n-1);
				duration= (clock() - start) / (double) CLOCKS_PER_SEC;
				if(n<100)
				{
					cout<<"DS sau khi xep thu tu voi QUICK SORT la: "<<endl;
					output(b,n);
				}
				if(duration > 0)
					cout<<"Thoi gian QUICK SORT"<<duration*1000000<<endl;
				break;
		case 8:
				CopyArray(a,b,n);
				start=clock();
				HeapSort(b,n);
				duration= (clock() - start) / (double) CLOCKS_PER_SEC;
				if(n<100)
				{
					cout<<"DS sau khi xep thu tu voi HEAP SORT la: "<<endl;
					output(b,n);
				}
				if(duration > 0)
					cout<<"Thoi gian HEAP SORT"<<duration*1000000<<endl;
				break;
		case 9:
				cout<<"Vui long nhap gia tri";
				cin>>x;
				start=clock();
				SearchSequence(a,n,x);
				duration= (clock() - start) / (double) CLOCKS_PER_SEC;
				if(duration>0)
					cout<<"Thoi gian tim kiem TUAN TU :"<<duration*1000000<<endl;
				break;
		case 10:
				cout<<"Vui long nhap gia tri";
				cin>>x;
				start=clock();
				i=BinarySearch(b,0,n,x);
				duration= (clock() - start) / (double) CLOCKS_PER_SEC;
				if(i==-1)
					cout<<"Khong tim thay x="<<x<<" trong day "<<endl;
				else
					cout<<"Tim thay x="<<x<<" trong day tai vi tri i="<<i<<endl;
				if(duration>0)
					cout<<"Thoi gian tim kiem NHI PHAN:"<<duration*1000000<<endl;
				break;
		case 11:
				cout<<"Bye <3"<<endl;
				break;
		default:
				break;
		}
	}while (choice!=11);
	return 0;
}
