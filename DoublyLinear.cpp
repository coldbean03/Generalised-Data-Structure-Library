#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
	struct node *prev;
};

template<class T>
class DoublyLL
{
    public:
        struct node<T> *Head;
        int Count;

        DoublyLL();
        void InsertFirst(T);
        void InsertLast(T);
		void InsertAtPosition(T,int pos);
        void Display();
        int CountNode();
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPosition(int pos);
};

template<class T>
DoublyLL<T>::DoublyLL()
{
    Head = NULL;
    Count = 0;
}

template<class T>
void DoublyLL<T>::InsertFirst(T no)
{
	struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;
	newn->prev = NULL;
	
	if(Head == NULL)
	{
		Head= newn;
	}
	else
	{
		Head -> prev = newn;
		newn -> next = Head;
		Head = newn;
	}
	Count++;
}

template<class T>
void DoublyLL<T>::InsertLast(T no)
{
	struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;
	newn-> next = NULL;
	
	if(Head == NULL)
	{
		Head = newn;
	}
	else
	{
		struct node<T> *temp = Head;
		
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		
		temp -> next = newn;
		newn -> prev = temp;
	}
	Count++;
}

template<class T>
void DoublyLL<T>::InsertAtPosition(T no, int pos)
{
	struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;
	newn->prev = NULL;
	
	if((pos < 1) || (pos > Count + 1))
	{
		cout<<"Invalid Position";
	}
	
	if(pos == 1)
	{
		InsertFirst(no);
	}
	
	else if(pos = Count + 1)
	{
		InsertLast(no);
	}
	
	else
	{
		struct node<T> *temp = Head;
		
		for(int iCnt = 1; iCnt < (pos - 1); iCnt++)
		{
			temp = temp -> next;
		}
		newn -> next = temp -> next;
		temp -> next -> prev = newn;
		newn -> prev = temp;
		temp -> next = newn;
		Count++;
	}
}

template<class T>
void DoublyLL<T>::Display()
{
	cout<<"Elements from Linked list are : "<<endl;
    struct node<T> *temp = Head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

template<class T>
int DoublyLL<T>::CountNode()
{
	return Count;
}

template<class T>
void DoublyLL<T>::DeleteFirst()
{
	struct node<T> *temp = Head;
	
	if(Count == 0)
	{
		return;
	}
	
	else
	{
		Head = Head -> next;
		Head -> prev = NULL;
		
		delete temp;
	}
	Count--;
}

template<class T>
void DoublyLL<T>::DeleteLast()
{
	if(Count == 0)
	{
		return;
	}

	else
	{
		struct node<T> *temp = Head;
		
		while((temp -> next) != NULL)
		{
			temp = temp -> next;
		}
		
		temp -> prev -> next = NULL;
		delete temp;
	}
	Count--;;
}

template<class T>
void DoublyLL<T>::DeleteAtPosition(int pos)
{	
	if((pos < 1) || (pos > Count))
	{
		cout<<"Invalid Position";
	}
	
	if(pos == 1)
	{
		DeleteFirst();
	}
	
	else if(pos = Count)
	{
		DeleteLast();
	}
	
	else
	{
		struct node<T> *temp = Head;
		
		for(int iCnt = 1; iCnt < (pos - 1); iCnt++)
		{
			temp = temp -> next;
		}
		temp -> next = temp -> next -> next;
		delete temp -> next -> prev;
		temp -> next -> prev = temp;
		Count++;
	}
}

int main()
{
	DoublyLL <int>obj1;
    DoublyLL <float>obj2;

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

    obj2.InsertFirst(21.11);
    obj2.InsertFirst(11.11);
    obj2.InsertLast(51.11);
    obj2.InsertLast(101.11);

    obj2.Display();
   cout<<"Number of nodes are : "<<obj2.CountNode()<<endl;
    return 0;
}