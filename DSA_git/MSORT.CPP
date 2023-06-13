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
		void MERGE_SORT(int,int);
		void MERGE(int,int,int);
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
void LIST::MERGE(int low,int mid,int high)
{
	int *B=new int[size+1];
	int h=low,j=mid+1; // pointer for both sublist(l1 & l2)
	int i=low; // pointer for auxilary list (l3)
	while(h<=mid && j<=high)
	{
		if(A[h]<A[j])
		{
			B[i]=A[h];
			h=h+1;
			i=i+1;
		}
		else
		{
			B[i]=A[j];
			j=j+1;
			i=i+1;
		}
	}
	if(h>mid) // l1 exhausted
	{
		// copy remaining l2 in B[]
		for(int k=j;k<=high;k++)
		{
			B[i]=A[k];
			i=i+1;
		}
	}
	else // l2 exhausted
	{
		// copy remaining l1 in B[]
		for(int k=h;k<=mid;k++)
		{
			B[i]=A[k];
			i=i+1;
		}
	}
	for(int k=low; k<=high; k++)
	{
		A[k]=B[k];
	}
	delete B;
}
void LIST::MERGE_SORT(int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		MERGE_SORT(low,mid);
		MERGE_SORT(mid+1,high);
		MERGE(low,mid,high);
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
	obj.MERGE_SORT(1,n);
	cout<<endl<<"List after sorting : \n";
	obj.VIEW_LIST();
	getch();
}











