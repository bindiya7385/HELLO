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
		void HEAP_SORT();
		void HEAPIFY();
		void ADJUST(int,int);
};
LIST::LIST(int par)
{
	size = par;
	A = new int[size+1];
}
void LIST::SET_LIST()
{
	//cout<<endl<<"Enter list elements : ";
	for(int i=1;i<=size;i++)
		//A[i]=random(1000);
		cin>>A[i];
}
void LIST::VIEW_LIST()
{
	cout<<"List elements are : ";
	for(int i=1;i<=size;i++)
		cout<<A[i]<<" ";
}
void LIST::HEAP_SORT()
{
	// ---- step 1 ------
	HEAPIFY();
	// ---- step 1 ------
	for(int i=size;i>1;i--)
	{
		// EXCHANAGE ELEMENTS--------
		int temp = A[1];
		A[1] = A[i];
		A[i] = temp;
		//or  EXCH(1,i);
		ADJUST(1,i-1);//ADJUST(int i,int n)
	}
}
void LIST::HEAPIFY()
{
	for(int i=size/2;i>=1;i--)
		ADJUST(i,size);
}
void LIST::ADJUST(int i,int n)
{
	int item = A[i]; int j = 2*i;
	while(j<=n)
	{
		if(j<n && A[j] < A[j+1])
			j = j+1;
		if(item >= A[j])
			break;
		else
			A[j/2] = A[j];
		j = j*2;
	}
	A[j/2] = item;
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
	obj.HEAP_SORT();
	cout<<endl<<"List after sorting : \n";
	obj.VIEW_LIST();
	getch();
}











