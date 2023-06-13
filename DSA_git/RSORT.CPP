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
		void RADIX_SORT();
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
		//cin>>A[i];
}
void LIST::VIEW_LIST()
{
	cout<<"List elements are : ";
	for(int i=1;i<=size;i++)
		cout<<A[i]<<" ";
}
void LIST::RADIX_SORT()
{
	// -----declare Queue(s)--------------
	//int F[100],R[100],QUE[10][100];
	// or
	int **QUE, *F,*R;
	QUE = new int* [10];
	for(int i=1;i<=size;i++)
		QUE[i]=new int[size];
	F =new int[10]; // F =new int[size]; this was wrong
	R =new int[10]; // R =new int[size]; this was wrong
	// -----Sort the list now --------------
	int d=1;
	for(i=1;i<=5;i++)
	{
		// -----initialize Queue(s)--------------
		for(int l=0;l<=9;l++)
		{
			F[l]=0;
			R[l]=0;
		}
		//---add all elements in Queues ---
		for(int j=1;j<=size;j++)
		{
			int k=(A[j]/d)%10;
			if(F[k]==0)
				F[k]=1;
			R[k]=R[k]+1;
			QUE[k][R[k]]=A[j];
		}
		//---collect all elements from Queues ---
		j=1;
		for(int qn=0;qn<=9;qn++)
		{
			// here it was wrong
			if(F[qn] != 0) //Que not empty
				for(int m=F[qn]; m<=R[qn];m++)
				{
					A[j]= QUE[qn][m];
					j=j+1;
				}
		}
		d=d*10;
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
	obj.RADIX_SORT();
	cout<<endl<<"List after sorting : \n";
	obj.VIEW_LIST();
	getch();
}











