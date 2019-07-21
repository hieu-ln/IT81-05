#include <iostream>
using namespace std;

//7.1 Khai bai cau truc queue
#define MAX 100;

//7.2 Tao queue rong
void init(int a[], int &front, int &rear)
{
	front=-1;
	rear=-1;
}

//7.3 Kiem tra queue rong
int isEmpty(int a[], int &front)
{
	if(front == NULL)
		return 1;
	return 0;
}

//7.4 Kien tra queue day
int isFull(int a[], int &front, int &rear)
{
	if((front == 0 && rear == MAX -1) || (front - rear == 1))
		return 1;
	else
		return 0;
}

//7.5 Them 1 phan tu
int Push(int a[], int &front, int &rear, int n)
{
	if(rear-front=MAX-1)
		return 0;
	else
	{
		if(front=-1)		
			front=0;
		if(rear == MAX -1)
		{
			for(int i = front; i <= rear; i++)
				a[i-front]=a[i];
			rear=MAX-1-front;
			front=0;
		}
		a[++rear]=n;
		return 1;
	}
}

//7.6 Xoa phan tu trong queue
int Pop(int a[], int &front, int &rear, int n)
{
	if(front==-1)
		return 0;
	else
	{
		n=a[front+1];
		if(front>rear)
		{
			front=-1;
			rear=-1;
		}
		return 1;
	}
}

//Xuat hang doi
void Xuat(int a[], int front, int rear)
{
	cout << "front = " << front << "  " << "rear = " << rear << endl;
	if(front<rear &&)
	{
		cout<<"<---- ";
		for(int i=front;i<rear+1;i++)
			cout<<a[i]<<" ";
		cout<<"<---- "<<endl;
	}
}
int main()
{
	int a[MAX];
	int choose, front, rear, n, k;
	system("cls");
	cout << "1. Khoi tao Queue rong\n";
	cout << "2. Them phan tu vao Queue\n";
	cout << "3. Lay phan tu ra khoi Queue\n";
	cout << "4. Kiem tra Queue rong\n";
	cout << "5. Kiem tra Queue day\n";
	cout << "6. Xuat Queue\n";
	cout << "7. Thoat\n";
	do{
		cout << "\n Nhap so thu tu muon thuc hien: ";
		cin >> choose;
		switch(choose)
		{
		case 1:
			init(a,front,rear);
			cout << "Khoi tao Queue thanh cong!\n";
			break;
		case 2:
			cout << "Nhap gia tri phan tu can them: ";
			cin >> n;
			k = Push(a,front,rear,n);
			cout << "Queue thay doi la: ";
			xuat(a,front,rear);
			break;
		case 3:
			cout << "Nhap gia tri phan tu can lay ra: ";
			cin >> n;
			k = Pop(a,front,rear,n);
			cout << "Queue sau khi lay ra: ";
			xuat(a,front,rear);
			break;
		case 4: 
			k = isEmpty(a,front,rear);
			if(k == 0)
				cout << "Queue khong rong\n";
			else
				cout << "Queue rong\n";
			break;
		case 5:
			k = isFull(a,front, rear);
			if(k == 0)
				cout << "Queue chua day\n";
			else
				cout << "Queue day\n";
			break;
		case 6:
			cout << "Queue hien tai la: ";
			xuat(a,front,rear);
			break;
		case 7:
			cout << "Ban chon thoat\n";
			break;
		default:
			break;
		}
	} while(choose != 7);
	return 0;
}
