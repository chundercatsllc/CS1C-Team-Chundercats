#ifndef H_linkedQueue
#define H_linkedQueue

#include <iostream>
#include "node.h"
using namespace std;

//Definition of the node
//template <class Type>
//struct nodeType
//{
//	Type info;
//	nodeType<Type> *link;
//};

template<class Type>
class linkedQueueType
{
public:
    const linkedQueueType<Type>& operator=
								(const linkedQueueType<Type>&);
              // overload the assignment operator
    bool isEmptyQueue();
    bool isFullQueue();
    void destroyQueue();
    void initializeQueue();
    void addQueue(const Type& newElement);
	const Type& top();
	void print();
    void deQueue(const Type& deqElement);
    linkedQueueType (); //default constructor
    linkedQueueType(const linkedQueueType<Type>& otherQueue);
		//copy constructor
    ~linkedQueueType(); //destructor

private:
    nodeType<Type> *front; //pointer to the front of the queue
    nodeType<Type> *rear;  //pointer to the rear of the queue
};

//#include "linkedQueue.h"

template<class Type>
linkedQueueType<Type>::linkedQueueType() //default constructor
{
	front = NULL; // set front to null
	rear = NULL;  // set rear to null
}

template<class Type>
void linkedQueueType<Type>::print()
{
	nodeType<Type> *temp;
	temp = front;
	
	while(temp != NULL)
	{
		cout << temp->info << endl;
		temp = temp->next;
	}
}

template<class Type>
const Type& linkedQueueType<Type>::top()
{
	if(front != NULL)
		return front->info;
}

template<class Type>
bool linkedQueueType<Type>::isEmptyQueue()
{
	return(front == NULL);
}

template<class Type>
bool linkedQueueType<Type>::isFullQueue()
{
	return false;
}

template<class Type>
void linkedQueueType<Type>::destroyQueue()
{
	nodeType<Type> *temp;

	while(front != NULL)  //while there are elements left in the queue
	{
	   temp = front;         // set temp to point to the current node
	   front = front ->next; // advance front to the next node
	   delete temp;          // deallocate memory occupied by temp
	}

	rear = NULL;  // set rear to null
}

template<class Type>
void linkedQueueType<Type>::initializeQueue()
{
  destroyQueue();
}

template<class Type>
void linkedQueueType<Type>::addQueue(const Type& newElement)
{
	nodeType<Type> *newNode;

	newNode = new nodeType<Type>;	//create the node
	newNode->info = newElement;		//store the info
    newNode->next = NULL;			//initialize the link field to null

    if(front == NULL)				//if initially queue is empty
    {
		front = newNode;
		rear = newNode;
    }
    else				//add newNode at the end
    {
		rear->next = newNode;
		rear = rear->next;
    }
}//end addQueue

template<class Type>
void linkedQueueType<Type>::deQueue(const Type& deqElement)
{
	nodeType<Type> *temp;

	while(front->info != deqElement)
	{
		temp = front;              //make temp point to the first node
		front = front->next;       //advance front to the next node
		delete temp;               //delete the first node
	}
	
	if(front->info == deqElement)
	{
		cout << "Deleted..\n";
		temp = front;
		front = front->next;
		delete temp;
	}
	
	if(front == NULL) //if after deletion the queue is empty
	{		
		rear = NULL;		   //set rear to NULL
		cout << "List is empty\n";
	}
}//end deQueue



template<class Type>
linkedQueueType<Type>::~linkedQueueType() //destructor
{
	nodeType<Type> *temp;

	while(front != NULL)	  //while there are elements left in the queue
	{
	   temp = front;         //set temp to point to the current node
	   front = front ->next; //advance first to the next node
	   delete temp;          //deallocate memory occupied by temp
	}

	rear = NULL;  // set rear to null
}

template<class Type>
const linkedQueueType<Type>& linkedQueueType<Type>::operator=
								(const linkedQueueType<Type>& otherQueue)
{
	//Write the definition of to overload the assignment operator

}

	//copy constructor
template<class Type>
linkedQueueType<Type>::linkedQueueType(const linkedQueueType<Type>& otherQueue)
{
    //Write the definition of the copy constructor
}//end copy constructor


#endif
