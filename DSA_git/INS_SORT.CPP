#include "iostream.h"
#include "conio.h"
#include "stdlib.h"
class LIST
{
		//  data
		int *A,size;
	public:
		// operations
		LIST(int);
		void READ_ELE();
		void INS_SORT();
		void LIST_ALL();
};
LIST::LIST(int par)
{
	// def of function
	size  = par;
	A = new int[size+1];
}
void LIST::READ_ELE()
{
	cout<<endl<<"Enter list elements : ";
	for(int i=1;i<=size;i++)
		//cin>>A[i];
		A[i]=random(1000);
}
void LIST::INS_SORT()
{
	for(int i=2;i<=size ;i++)
	{
		int ele = A[i];
		int j= i-1;
		while( j>=1 && ele>A[j] )
		{
			A[j+1]=A[j];
			j=j-1;
		}
		A[j+1]=ele;
	}
}
void LIST::LIST_ALL()
{
	// def of function
	cout<<endl<<"List elements are : \n";
	for(int i=1;i<=size;i++)
		cout<<A[i]<<" ";
}
///////////////////////////////////////////////////////
void main()
{
	int n;
	clrscr();
	cout<<endl<<"Enter size of arry : ";
	cin>>n;
	LIST obj(n);
	/////////////////////////////////////////
	obj.READ_ELE();
	cout<<endl<<"Elements before sorting";
	obj. LIST_ALL();
	obj.INS_SORT();
	cout<<endl<<"Elements after sorting";
	obj.LIST_ALL();
	getch();
}











