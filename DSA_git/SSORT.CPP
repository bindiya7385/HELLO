// Exam seat n0 :
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
		int MIN(int);
		void SELECTION_SORT();
		void SWAP(int,int);
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
}
void LIST::VIEW_LIST()
{
	cout<<"List elements are : ";
	for(int i=1;i<=size;i++)
		cout<<A[i]<<" ";
}
int LIST::MIN(int i)
{
	int min=A[i], pos=i;
	for(int j=i+1;j<=size;j++)
	{
		if(A[j]<min)
		{
			min=A[j]; pos=j;
		}
	}
	return pos;
}
void LIST::SWAP(int i, int j)
{
	int temp= A[i];
	A[i]=A[j];
	A[j]=temp;
}
void LIST::SELECTION_SORT()
{
	for(int i=1;i<=size-1;i++)
	{
		int min_pos = MIN();
		SWAP(i,min_pos);
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
	obj.SELECTION_SORT();
	cout<<endl<<"List after sorting : \n";
	obj.VIEW_LIST();
	getch();
}











