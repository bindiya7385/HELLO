// Implementation of Polynomial Addition / Subtraction (using Linked List)

#include "iostream.h"
#include "conio.h"
class NODE
{
	public:
		int coeff;
		int power;
		NODE *link;
};
class POLYEXPR
{
		NODE *PE1,*PE2,*PE3;
		int order;
	public:
		POLYEXPR(int);
		void READ_POLYEXPR1();
		void READ_POLYEXPR2();
		void ADD_POLYEXPR();
		void SUB_POLYEXPR();
		void VIEW_POLYEXPR();
};
POLYEXPR::POLYEXPR(int para)
{
	order = para;
	PE1 = NULL;
	PE2 = NULL;
	PE3 = NULL;
}
void POLYEXPR::READ_POLYEXPR1()
{
	NODE *last = NULL;
	cout<<endl<<"Enter poly Exp 1 : ";
	for (int i=order;i>=0;i--)
	{
		// ---create new node ---------
		NODE *NN = new NODE();
		// --- fill up new node -------
		cout<<endl<<"Enter Coeff of X^"<<i<<" : ";
		cin>>NN->coeff;
		NN->power = i;
		// --- set the links (ADD at LAST) ---
		if(PE1 == NULL)
			PE1 = last = NN;
		else
		{
			last->link = NN;
			last = NN;
		}
	}
}
void POLYEXPR::READ_POLYEXPR2()
{
	NODE *last = NULL;
	cout<<endl<<"Enter poly Exp 1 : ";
	for (int i=order;i>=0;i--)
	{
		// ---create new node ---------
		NODE *NN = new NODE();
		// --- fill up new node -------
		cout<<endl<<"Enter Coeff of X^"<<i<<" : ";
		cin>>NN->coeff;
		NN->power = i;
		// --- set the links (ADD at LAST) ---
		if(PE2 == NULL)
			PE2 = last = NN;
		else
		{
			last->link = NN;
			last = NN;
		}
	}
}
void POLYEXPR::ADD_POLYEXPR()
{
	NODE *last = NULL;
	NODE *ptr1 =PE1;
	NODE *ptr2 =PE2;
	for (int i=order;i>=0;i--)
	{
		// ---create new node ---------
		NODE *NN = new NODE();
		// --- fill up new node -------
		cout<<endl<<"Enter Coeff of X^"<<i<<" : ";
		NN->coeff = ptr1->coeff + ptr2->coeff ;
		NN->power = i;
		// --- set the links (ADD at LAST) ---
		if(PE3 == NULL)
			PE3 = last = NN;
		else
		{
			last->link = NN;
			last = NN;
		}
		ptr1 = ptr1->link;
		ptr2 = ptr2->link;
	}
}
void POLYEXPR::SUB_POLYEXPR()
{
	NODE *last = NULL;
	NODE *ptr1 =PE1;
	NODE *ptr2 =PE2;
	for (int i=order;i>=0;i--)
	{
		// ---create new node ---------
		NODE *NN = new NODE();
		// --- fill up new node -------
		cout<<endl<<"Enter Coeff of X^"<<i<<" : ";
		NN->coeff = ptr1->coeff - ptr2->coeff ;
		NN->power = i;
		// --- set the links (ADD at LAST) ---
		if(PE3 == NULL)
			PE3 = last = NN;
		else
		{
			last->link = NN;
			last = NN;
		}
		ptr1 = ptr1->link;
		ptr2 = ptr2->link;
	}
}
void POLYEXPR::VIEW_POLYEXPR()
{
	NODE *ptr = PE3;
	cout<<endl<<"Poly Exp 1 : ";
	for (int i=order;i>=0;i--)
	{
		cout<<ptr->coeff<<"X^"<<i<<" + ";
		ptr= ptr->link;
	}
}
void main()
{
	int ord;
	clrscr();
	cout<<endl<<"Enter max order of Poly Expression : ";
	cin>>ord;
	POLYEXPR obj(ord);
	obj.READ_POLYEXPR1();
	obj.READ_POLYEXPR2();
	obj.ADD_POLYEXPR();
	//obj.SUB_POLYEXPR();
	obj.VIEW_POLYEXPR();
	getch();
}
