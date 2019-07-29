//#include<iostream>
//using namespace std;
//#define MAX 100
//int a[MAX];
//int n;
//void nhap(int a[], int n)
//{
//	for (int i=0; i< n;i++)
//		{
//			cout<<"Nhap a["<<i<<"] = ";
//			cin>>a[i];
//		}
//}
//void xuat(int a[], int n)
//{
//	for(int i=0;i<n;i++)
//		cout<<a[i]<<endl;
//}
//void swap(int &a, int &b)
//{
//	int c;
//	c=a;
//	a=b;
//	b=c;
//}
//void insertionsort(int a[] , int n)
//{
//	int x, j;
//	for(int i=1;i<n;i++)
//	{
//		x=a[i];
//		j=i-1;
//		while(0<=j && x<a[j])
//		{
//			a[j+1]=a[j];
//			j--;
//		}
//		a[j+1]=x;
//	}
//}
//void selectionsort(int a[], int n)
//{
//	int min_pos, i, j;
//	for(i=0;i<n-1;i++)
//	{
//		min_pos=i;
//		for(j=i+1;j<n;j++)
//			if(a[j]<a[min_pos])
//				min_pos=j;
//		swap(a[min_pos],a[i]);
//	}
//}
//void interchangesort(int a[],int n)
//{
//	for(int i=0;i<n-1;i++)
//		for(int j=i+1;j<n;j++)
//			if(a[i]>a[j])
//				swap(a[i],a[j]);
//}
//void bubblesort(int a[], int n)
//{
//	for(int i=0;i<n-1;i++)
//		for(int j=n-1;j>i;j--)
//			if(a[j-1]>a[j])
//				swap(a[j],a[j-1]);
//}
//void quicksort(int a[], int left, int right)
//{
//	int x=a[(left+right)/2];
//	int i= left;
//	int j=right;
//	while(i<j)
//	{
//		while(a[i]<x) i++;
//		while(a[i]>x) i--;
//		quicksort(a,0,n+1);
//		if(i<=j){
//			swap(a[i],a[j]);
//				i++;
//			j--;
//		}
//	}
//	if(left<j)
//		quicksort(a,left,j);
//	if(i<right)
//		quicksort(a,i,right);
//}
//void shift(int a[],int i, int n)
//{
//	int j = 2*i+1;
//	if(j>=n)
//		return ;
//	if(j+1<n)
//		if(a[j]<a[j+1])
//			j++;
//	if(a[i]>=a[j])
//		return ;
//	else
//	{
//		int x= a[i];
//		a[i]=a[j];
//		a[j]=x;
//		shift(a,j,n);
//	}
//}
//void heapsort(int a[], int n)
//{
//	int i=n/2;
//	while(i>=0)
//	{
//		shift(a,i,n-1);
//		i--;
//	}
//	int right=n-1;
//	while(right>0)
//	{
//		swap(a[0],a[right]);
//		right--;
//		if(right>0)
//			shift(a,0,right);
//	}
//}
//int search(int a[], int n, int x)
//{
//	int i=0;
//	while(i<n&&a[i]!=x)
//		i++;
//	if(i<n)
//		return i;
//	return -1;
//}
//int binarysearch(int a[],int n,int x)
//{
//	int left=0,right=n-1,mid;
//	while(left<=right)
//	{
//		mid=(left+right)/2;
//		if(a[mid]==x)
//			return mid;
//		if(x>a[mid])
//			left=mid+1;
//		else
//			right=mid-1;
//	}
//	return -1;
//}
//int menu()
//{
//	int choose = 0;
//
//	cout << "====================\n";
//	cout << " 0. Thoat\n";
//	cout << " 1. Khoi tao\n";
//	cout << " 2. Xuat\n";
//	cout << " 3. Sap xep selectionsort\n";
//	cout << " 4. Sap xep insertionsort\n";
//	cout << " 5. Sap xep bubblesort\n";
//	cout << " 6. Sap xep quicksort\n";
//	cout << " 7. Sap xep heapsort\n";
//	cout << " 8. tim kiem tuan tu\n";
//	cout << " 9. tim kiem nhi phan\n";
//	cout << "====================\n";
//	cout << "Chon chuc nang: ";
//	cin >> choose;
//
//	return choose;
//}
//int main()
//{
//	int choose,x;
//	int left=0;
//	int right=n-1;
//	do{
//		choose = menu();
//
//		switch(choose)
//		{
//		case 0:
//			cout << "Nhan nut bat ki de thoat => ";
//			break;
//		//---------------------------------------------
//		case 1:
//			cout<<"Nhap so phan tu: ";
//			cin>>n;
//			nhap(a,n);
//			break;
//		//---------------------------------------------	
//		case 2:
//			cout << "Danh sach lien ket vua khoi tao la:\n";
//			xuat(a,n);
//			break;
//		//---------------------------------------------
//		case 3:
//			cout << "Sap xep selectionsort:\n";
//			selectionsort(a,n);
//			xuat(a,n);
//			break;
//		//---------------------------------------------
//		case 4:
//			cout << "Sap xep insertionsort\n";
//			insertionsort(a,n);
//			xuat(a,n);
//			break;
//		//---------------------------------------------
//		case 5:
//			cout << "Sap xep bubblesort\n";
//			bubblesort(a,n);
//			xuat(a,n);
//			break;
//		//---------------------------------------------
//		case 6:
//			cout << "Sap xep quicksort\n";
//			quicksort(a,left,right);
//			xuat(a,n);
//			break;
//		//---------------------------------------------
//		case 7:
//			cout << "Sap xep heapsort\n";
//			heapsort(a,n);
//			xuat(a,n);
//			break;
//		//---------------------------------------------
//		case 8:
//			cout << "Nhap gia tri tim kiem tuan tu:\n ";
//			cin >>x;
//			if(search(a,n,x) !=-1 )
//				cout << "tim thay "<<x<<" tai vi tri "<<search(a,n,x)<<"\n";
//			else
//				cout << "tim khong thanh cong\n";
//			break;
//		case 9:
//			cout << "Nhap gia tri tim kiem nhi phan:\n ";
//			cin >>x;
//			if(binarysearch(a,n,x) !=-1 )
//				cout << "tim thay "<<x<<" tai vi tri "<<binarysearch(a,n,x)<<"\n";
//			else
//				cout << "tim khong thanh cong\n";
//			break;
//		//---------------------------------------------
//		default:
//			cout << "Chuc nang khong ton tai\n";
//			break;
//		}
//	}while(choose != 0);
//	system("pause");
//	return 0;
//}