//chuong 3 - Bai 1
#include <iostream>
using namespace std;


void swap(int &a, int &b)
{
	int tam;
	tam = a;
	a = b;
	b = tam;
}
void Coppy(int a[], int b[], int n)
{
	for(int i = 0; i < n; i++)
		b[i] = a[i];
}
//1.1 khai bao cau truc danh sach
#define MAX 100
int a[MAX];
int n;

//1.2 nhap danh sach
void nhap(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << "Nhap gia tri phan tu thu " << i + 1 << ": ";
		cin >> a[i];
	}
}
//1.3 xuat danh sach
void xuat(int a[], int n)
{
	cout << "Danh sach hien tai la: ";
	for(int i = 0; i < n; i++)
		cout << a[i] << "  ";
	cout << endl;
}
//1.4 Sap xep danh sach theo Insertion sort.
void InsertionSort(int a[], int n)
{
	int x, i,j;
	for(i = 1; i < n; i++)
	{
		x = a[i];
		j = i - 1;
		while(j >= 0 && x < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
//1.5 Sap xep danh sach theo Selection sort.
void SelectionSort(int a[], int n)
{
	int min_pos, i, j;
	for(i = 0; i < n - 1; i++)
	{
		min_pos = i;
		for(j = i + 1; j < n; j++)
			if(a[j] < a[min_pos])
				min_pos = j;
		swap(a[min_pos],a[i]);
	}
}
//1.6 Sap xep danh sach theo Interchange sort
void InterchangeSort(int a[], int n)
{
	for(int i = 0; i < n - 1; i++)
		for(int j = i + 1;j < n; j++)
			if(a[i] > a[j])
				swap(a[i],a[j]);
}
//1.7 Sap xep danh sach theo Bubble sort
void BubbleSort(int a[], int n)
{
	for(int i = 0; i< n - 1;i++)
		for(int j = n - 1; j > i; j--)
			if(a[j - 1] > a[j])
				swap(a[j],a[j - 1]);
}
//1.8 Sap xep danh sach theo Quick sort
void QuickSort(int a[], int left, int right)
{
	int x = a[(left + right)/2];
	int i = left;
	int j = right;
	while(i < j)
	{
		while(a[i] < x)
			i++;
		while(a[j] > x)
			j--;
		if(i <= j)
		{
			swap(a[i],a[j]);
			i++;j--;
		}
	}
	if(left < j)
		QuickSort(a,left,j);
	if(right > i)
		QuickSort(a,i,right);
}

//1.9 Sap xep danh sach theo Heap sort
void shift(int a[], int i, int n)
{
	int j = 2*i + 1;
	if(j >= n)
		return;
	if(j+1 < n)
		if(a[j] < a[j + 1])
			j++;
	if(a[i] >= a[j])
		return;
	else
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a,j,n);
	}
}
void HeapSort(int a[], int n)
{
	int i = n/2 -1;
	while(i >= 0)
	{
		shift(a,i,n);
		i--;
	}
	int right = n - 1;
	while(right > 0)
	{
		swap(a[0],a[right]);
		right--;
		if(right > 0)
			shift(a,0,right);
	}
}
//1.10 Tim kiem tuan tu
int Search(int a[], int n, int x)
{
	int i = 0;
	while(i < n && a[i] != x)
		i++;
	if(i < n)
		return i;
	return -1;
}
//1.11 Tim kiem nhi phan
int BinarySearch(int a[], int n, int x)
{
	int left = 0, right = n - 1, mid;
	while(left <= right)
	{
		mid =(left + right)/2;
		if(a[mid] == x)
			return mid;
		if(x > a[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}
int main()

{
	int choose, x;
	int b[MAX];
	cout << "Nhap so luong phan tu can dung: ";
	cin >> n;
	
	int left = 0;
	int right = n - 1;
	do{
		cout << "1.Nhap danh sach\n";
		cout << "2.Xuat danh sach\n";
		cout << "3.Sap xep theo Insertion sort\n";
		cout << "4.Sap xep theo Selection sort\n";
		cout << "5.Sap xep theo Interchange sort\n";
		cout << "6.Sap xep theo Bubble sort\n";
		cout << "7.Sap xep theo Quick sort\n";
		cout << "8.Sap xep theo Heap sort\n";
		cout << "9.Tim kiem tuan tu\n";
		cout << "10.Tim kiem nhi phan\n";
		cout << "11. Thoat\n";
		cout << "Nhap thao tac muon thuc hien: ";
		cin >> choose;
		switch(choose)
		{
		case 1:
			nhap(a,n);
			Coppy(a,b,n);
			xuat(a,n);
			break;
		case 2:
			xuat(b,n);
			break;
		case 3:
			InsertionSort(b,n);
			cout << "Sau khi sap xep bang InsertionSort - ";
			xuat(b,n);
			break;
		case 4:
			SelectionSort(b,n);
			cout << "Sau khi sap xep bang SelectionSort - ";
			xuat(b,n);
			break;
		case 5:
			InterchangeSort(b,n);
			cout << "Sau khi sap xep bang InterchangeSort - ";
			xuat(b,n);
			break;
		case 6:
			BubbleSort(b,n);
			cout << "Sau khi sap xep bang BubbleSort - ";
			xuat(b,n);
			break;

		case 7:
			
			QuickSort(b,left,right);
			cout << "Sau khi sap xep bang QuickSort - ";
			xuat(b,n);
			break;

		case 8:

			HeapSort(b,n);
			cout << "Sau khi sap xep bang HeapSort - ";
			xuat(b,n);
			break;

		case 9:
			
			cout << "Nhap gia tri x can tim: ";
			cin >> x;
			if(Search(b,n,x) != -1)
				cout << x << " co trong danh sach tai vi tri " << Search(b,n,x) + 1 << endl;
			else
				cout << " Khong tim thay " << x << endl;
			break;
		case 10:
			
			cout << "Nhap gia tri x can tim: ";
			cin >> x;
			if(BinarySearch(b,n,x) != -1)
				cout << x << " co trong danh sach tai vi tri " << BinarySearch(b,n,x) + 1 << endl;
			else
				cout << "Khong tim thay " << x << endl;

			break;
		case 11:
			cout << "Ban chon thoat !\n";
			break;
		default:
			break;
		}

	}while(choose != 11);
	return 0;
}

















































