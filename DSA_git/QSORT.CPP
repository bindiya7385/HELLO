#include "iostream.h"
#include "conio.h"
#include "stdlib.h"
class LIST
{
		int *A,size;
	public:
		LIST(int);
		void SET_LIST();
		void VIEW_LIST();
		void QUICK_SORT(int,int);
		void PARTITION(int,int &);
};
LIST::LIST(int par)
{
	size=par;
	A =new int[size+1];
}
void LIST::SET_LIST()
{
	//cout<<endl<<"Enter list elements : ";
	for(int i=1;i<=size;i++)
		A[i]=random(1000);
	A[i+1]=9999; // +infinity
}
void LIST::VIEW_LIST()
{
	cout<<"List elements are : ";
	for(int i=1;i<=size;i++)
		cout<<A[i]<<" ";
}
void LIST::PARTITION(int m,int & p) // in-out type 'p'
{
	int v=A[m]; int i=m;
	do
	{
		do
		{
			i=i+1;
		}while(A[i]<v);
		do
		{
			p=p-1;
		}while(A[p]>v);
		if(i<p)
		{
		   int temp=A[i];
		   A[i]=A[p];
		   A[p]=temp;
		}
		else
			break;
	}while(1);
	A[m]=A[p];
	A[p]=v;
}

void LIST::QUICK_SORT(int p,int q)
{
	if(p<q)
	{
		int j=q+1;
		PARTITION(p,j);
		QUICK_SORT(p,j-1);
		QUICK_SORT(j+1,q);
	}
}
////////////////////////////////////////////////////
void main()
{
	int n;
	clrscr();
	cout<<"\n Enter size of array : ";
	cin>>n;
	LIST obj(n);
	obj.SET_LIST();
	cout<<endl<<"List before sorting : \n";
	obj.VIEW_LIST();
	obj.QUICK_SORT(1,n);
	cout<<endl<<"List after sorting : \n";
	obj.VIEW_LIST();
	getch();
}











