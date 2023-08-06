#include<iostream>
using namespace std;

template<class T>
struct node
{
    int data;
    struct node *next;
	struct node *prev;
};

template<class T>
class DoublyCLL
{
    public:                    
        struct node<T> *Head;
		struct node<T> *Tail;
		int Count;
                    
        DoublyCLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPosition(T no, int pos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int pos);
        void Display();
        int CountNode();
};

template<class T>
DoublyCLL<T>::DoublyCLL()
{
    Head = NULL;
    Tail = NULL;
	Count = 0;
}

template<class T>
void DoublyCLL<T>::InsertFirst(T no)
{
	struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;
	newn->next = NULL;
	
	if((Head == NULL) && (Tail == NULL))   
    {
        Head = newn;
        Tail = newn;
    }
    else        
    {
        Head -> prev = newn;
		newn -> next = Head;
		Head = newn;
    }
    Tail -> next = Head;
	Count++;
}

template<class T>
void DoublyCLL<T>::InsertLast(T no)
{
	struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;
	newn->prev = NULL;
	
	if((Head == NULL) && (Tail == NULL))    
    {
        Head = newn;
        Tail = newn;
    }
    else        
    {
        Head -> prev = newn;
		newn -> next = Head;
		Head = newn;
    }
    Tail -> next = Head;
	Count++;
}
/*
template<class T>
void DoublyCLL<T>::InsertAtPosition(T no, int pos)
{
	if((pos < 1) || (pos > Count + 1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == Count + 1)
    {
        InsertLast(no);
    }
    else
    {
		struct node<T> *newn = NULL;
		newn = new node<T>;

		newn->data = no;
		newn->next = NULL;

		struct node<T> *temp = Head;

		for(int iCnt = 1; iCnt < pos; iCnt++)
		{
			temp = temp->next;
		}

		newn->next = temp -> next;
		temp->next = newn;
		
		Count++;
    }
}

template<class T>
void DoublyCLL<T>::Display()
{
	struct node<T> *temp = Head;

    if(Head == NULL && Tail == NULL)
    {
        return;
    }

    do
    {
        cout<<"|"<<temp->data<<"|-> ";
        temp = temp -> next;
    }while(temp != Head);

    cout<<endl;
}

template<class T>
int DoublyCLL<T>::CountNode()
{
	return Count;
}

template<class T>
void DoublyCLL<T>::DeleteFirst()
{
	if(Head == NULL && Tail ==  NULL)       
    {
        return;
    }
    else if(Head == Tail)       
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else    
    {
        Head = Head -> next;
        delete Tail->next;

        Tail->next = Head;
    }
	Count--;
}

template<class T>
void DoublyCLL<T>::DeleteLast()
{
	if(Head == NULL && Tail ==  NULL)       
    {
        return;
    }
    else if(Head == Tail)       
    {
        delete Tail;
        Head = NULL;
        Tail = NULL;
    }
    else    
    {
        struct node<T> *temp = Head;

        while(temp->next != Tail)
        {
            temp = temp->next;
        }

        delete Tail;
        Tail = temp;

        Tail->next = Head;
	}
	Count--;
}

template<class T>
void DoublyCLL<T>::DeleteAtPosition(int pos)
{
	if((pos < 1) || (pos > Count))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == Count)
    {
        DeleteLast();
    }
    else
    {
		struct node<T> *temp1 = Head;

		for(int iCnt = 1; iCnt < pos-1; iCnt++)
		{
			temp1 = temp1->next;
		}

		struct node<T> *temp2 = temp1 -> next;

		temp1->next = temp2->next;
		delete temp2;
		Count--;
    }
}

int main()
{
	SinglyCLL <int> obj1;
    SinglyCLL <float> obj2;

    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
	obj1.InsertLast(51);
    obj1.InsertLast(101);
	obj1.InsertAtPosition(111,5);
	obj1.DeleteFirst();
	obj1.DeleteLast();
	obj1.DeleteAtPosition(3);

    obj1.Display();
    cout<<"Number of nodes are : "<<obj1.CountNode()<<endl;

    obj2.InsertFirst(10.11);
    obj2.InsertFirst(20.11);
    obj2.InsertLast(50.11);
    obj2.InsertLast(100.11);

    obj2.Display();
    cout<<"Number of nodes are : "<<obj2.CountNode()<<endl;
    return 0;
}