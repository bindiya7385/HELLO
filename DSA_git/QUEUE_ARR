#include "iostream.h"
#include "conio.h"

class QUEUE
{
		int A[50],size,rear,front;
	public:
		QUEUE(int);
		void ADD_QUE(int);
		int DEL_QUE();
		void LIST_QUE();
};
QUEUE::QUEUE(int par)
{
	size= par;
	rear = front = 0;
}
void QUEUE::ADD_QUE(int ele)
{
	if(rear==size)
		cout<<endl<<"Que is full";
	else
	{
		if(front==0)
			front=1;
		rear = rear + 1;
		A[rear] = ele;
	}
}
int QUEUE::DEL_QUE()
{
	if(front==0)
	{
		cout<<endl<<"Que is empty";
		return NULL;
	}
	else
	{
		int ele = A[front];
		if(front == rear) // only 1 ele in Que
			rear =front = 0;
		else
			front = front + 1;
		return ele;
	}
}
void QUEUE::LIST_QUE()
{
	if(front==0)
		cout<<endl<<"Que is empty";
	else
	{
		cout<<endl<<"Que elements are : ";
		for(int i= front;i<=rear;i++)
			cout<<A[i]<<" ";
	}
}
void MENU()
{
	int n,ele,opt;
	cout<<endl<<"Enter the size of Queue : ";
	cin>>n;
	QUEUE obj(n);
	do
	{
		cout<<endl<<"\n1 Add element";
		cout<<endl<<"2 Delete element";
		cout<<endl<<"3 View Queue";
		cout<<endl<<"4 Exit Menu";
		cout<<endl<<"================\n";
		cout<<endl<<"Enter your choice : ";
		cin>>opt;
		switch(opt)
		{
			case 1:
				cout<<endl<<"Enter ele to add : ";
				cin>>ele;
				obj.ADD_QUE(ele);
				break;
			case 2:
				ele = obj.DEL_QUE();
				if(ele)
					cout<<endl<<"Deleted ele = "<<ele;
				break;
			case 3:
				obj.LIST_QUE();
				break;
			case 4:
				return;
			default:
				cout<<endl<<"invalid input";
		}
	}while(1);
}
void main()
{
	clrscr();
	MENU();
	getch();
}









