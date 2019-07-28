//Chuong 3 : Xep thu tu va tim kiem - bai 1 - PHAM TRUNG KIEN - Nhom 5 - IT81
#include <iostream>
#include<stdio.h>
#include<ctime>
using namespace std;

#define MAX 5000

int a[MAX];
int n;

void init(int a[], int &n)
{
	cout << "Nhap vao so luong phan tu danh sach: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10000 + 1;
	}
	cout << "Danh sach duoc nhap ngau nhien: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "   ";
	}cout << endl;
}

void input(int a[], int& n)
{
	cout << "Nhap vao so luong phan tu: ";
	cin >> n;
	cout << "Nhap vao cac phan tu: ";
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
}

void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "	";
	}cout << endl;
}

void copyArray(int b[], int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}
}

void insertionSort(int a[], int n)
{
	int i; 
	int j;
	int key;
	for (int i = 0; i < n; i++)
	{
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j - j - 1;
		}
		a[j + 1] = key;
	}
}

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void selectionSort(int a[], int n)
{
	int i;
	int j;
	int min_idx;
	for (int i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (int j = 0; j < n; j++)
		{
			if (a[j] < a[min_idx])
				min_idx = j;
			swap(a[min_idx], a[i]);
		}
	}
}

void interchangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
}

void bubbleSort(int a[], int n)
{
	int i, j;
	bool haveSwap = false;
	for (i = 0; i < n-1; i++)
	{ 
		haveSwap = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				haveSwap = true;
			}
		}
		if (haveSwap == false)
			break;
	}
}

int partition(int a[], int low, int high)
{
	int pivot = a[high];
	int left = low;
	int right = high - 1;
	while (true)
	{
		while (left <= right && a[left] < pivot)
			left++;
		while (right >= left && a[right] > pivot)
			right++;
		if (left >= right)
			break;
		swap(a[left], a[right]);
		left++;
		right--;
	}
	swap(a[left], a[high]);
	return left;
}

void quickSort(int a[], int low, int high)
{
	if (low < high)
	{
		int	pi = partition(a, low, high);
		quickSort(a, low, pi - 1);
		quickSort(a, pi + 1, high);
	}
}

void heapify(int a[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l<n && a[l]>a[largest])
		largest = l;
	if (r<n && a[r]>a[largest])
		largest = r;
	if (largest != i)
	{
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}

void heapSort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}

void searchSequence(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
	{
		i++;
	}
	if (i == n)
		cout << "Khong tim thay!";
	else
		cout << "Tim thay tai vi tri" << i;	
}

int searchBinary(int a[], int l, int r, int x)
{
	if (r > l)
	{
		int mid = l + (r - l) / 2;
		if (a[mid] == x)
			return mid;
		if (a[mid] > x)
			return searchBinary(a, l, mid - 1, x);
		return searchBinary(a, mid + 1, r, x);
	}
	else
		return -1;
}

int main()
{
	int b[MAX];
	clock_t start;
	double duration;
	int choice, x, i;
	system("cls");
	cout << "0. Khoi tao danh sach ngau nhien\n";
	cout << "1. Nhap danh sach\n";
	cout << "2. Xuat danh sach\n";
	cout << "3. Xep thu tu phan tu danh sach bang SELECTION SORT\n";
	cout << "4. Xep thu tu phan tu danh sach bang INSERTION SORT\n";
	cout << "5. Xep thu tu phan tu danh sach bang BUBBLE SORT\n";
	cout << "6. Xep thu tu phan tu danh sach bang INTERCHANGE SORT\n";
	cout << "7. Xep thu tu phan tu danh sach bang QUICK SORT\n";
	cout << "8. Xep thu tu phan tu danh sach bang HEAP SORT\n";
	cout << "9. Tim kiem phan tu bang tim kiem tuan tu\n";
	cout << "10. Tim kiem phan tu bang tim kiem nhi phan\n";
	cout << "11. Thoat" << endl;
	do {
		cout << "Ban chon: ";
		cin >> choice;
		if (choice < 0 || choice > 11)
			cout << "Nhap sai.Nhap lai\n";
		switch (choice)
		{
		case 0:
			init(a,n);
			break;
		case 1:
			input(a, n);
			break;
		case 2:
			cout << "Danh sach la: ";
			output(a,n);
			cout << endl;
			break;
		case 3:
			copyArray(a, b, n);
			start = clock();
			selectionSort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n > 100)
			{
				cout << "Danh sach sau khi xep voi SELECTION SORT: ";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian SELECTION SORT: " << duration * 1000000 << "Microseconds" << endl;
			break;
		case 4:
			copyArray(a, b, n);
			start = clock();
			insertionSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n > 100)
			{
				cout << "Danh sach sau khi xep voi INSERTION  SORT: ";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian INSERTION SORT: " << duration * 1000000 << "Microseconds" << endl;
			break;
		case 5:
			copyArray(a, b, n);
			start = clock();
			bubbleSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n > 100)
			{
				cout << "Danh sach sau khi xep voi BUBBLE  SORT: ";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian BUBBLE SORT: " << duration * 1000000 << "Microseconds" << endl;
			break;
		case 6:
			copyArray(a, b, n);
			start = clock();
			interchangeSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n > 100)
			{
				cout << "Danh sach sau khi xep voi INTERCHANGE  SORT: ";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian INTERCHANGE SORT: " << duration * 1000000 << "Microseconds" << endl;
			break;
		case 7:
			copyArray(a, b, n);
			start = clock();
			quickSort(b, 0, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n > 100)
			{
				cout << "Danh sach sau khi xep voi QUICK SORT: ";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian QUICK SORT: " << duration * 1000000 << "Microseconds" << endl;
			break;
		case 8:
			copyArray(a, b, n);
			start = clock();
			heapSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n > 100)
			{
				cout << "Danh sach sau khi xep voi HEAP SORT: ";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian HEAP SORT: " << duration * 1000000 << "Microseconds" << endl;
			break;
		case 9:
			cout << "Nhap x: ";
			cin >> x;
			start = clock();
			searchSequence(a, n, x);	
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (duration > 0)
				cout << "Thoi gian tim kiem tuan tu: " << duration * 1000000 << "Microseconds" << endl;
			break;
		case 10:
			cout << "Nhap x: ";
			cin >> x;
			start = clock();
			searchBinary(b, 0, n, x);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (i == -1)
				cout << "Khong tim thay!" << endl;
			else
				cout << "Tim thay tai vi tri " << i << endl;
			if (duration > 0)
				cout << "Thoi gian tim kiem nhi phan: " << duration * 1000000 << "Microseconds" << endl;
			break;
		case 11:
			cout << "Thoat" << endl;
			break;
		default:
			break;
		}
	} while (choice != 11);
	return 0;
}