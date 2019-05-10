#ifndef AWESOMEVECTOR_H
#define AWESOMEVECTOR_H
#include <iostream>

using namespace std;

const int DEFAULTCAP = 15;

template<typename T>
class AwesomeVector
{
public:
	//AwesomeVector constructor
	/** sets array size to default*/
	AwesomeVector();
	
	//AwesomeVector cap-arg constructor
	/** creates new vector of capacity cap
	@param cap - the new capacity of type int
	*/
	AwesomeVector(int cap);
	
	//AwesomeVector copy constructor
	/** Creates new vector using other vector
	@param other - other vector as const ref
	*/
	AwesomeVector(const AwesomeVector<T>& other);
	
	//AwesomeVector destructor
	/** deletes the list*/
	~AwesomeVector();
	
	//copy assignment overload
	/** Copies the other vector into the invoking vector
	@param other - an AwesomeVector to be copied
	@return vector using *this
	*/
	const AwesomeVector<T>& operator=(const AwesomeVector<T>& other);
	
	//overloaded bracket
	/** returns the contents of the vector at the specified index
	@param index - the index to return
	@return a value of the templated type
	*/
	const T& operator[](int index);
	
	//isEmpty
	/** Checks whether the vector is 0
	@return the boolean of whether the vector size is 0
	*/
	bool isEmpty();
	
	//
	/** Changes string to enum of shape type
	@param shapeTypeStr - string of shape type
	@return Enum of shapeType
	*/
	void destroy();
	int  sizeOf();
	int  capacityOf();
	void push_back(const T&);
	const T& front();
	const T& back();
//	theVectorator<T> begin();
//	theVectorator<T> end();
	int   search(const T&);
	bool  chop(const T&);
    void set(int index, const T& stuff);
	void erase(int i);
	void print();
private:
	void copyV(const AwesomeVector<T> &other);
	void recapacitize();
	
	T *list;
	int size;
	int capacity;
	int head;
	int butt;
};

/**************************************************************************/

template<typename T>
void AwesomeVector<T>::copyV(const AwesomeVector<T> &other)
{
	int k = 0;
	T *temp = list;
	list = new T[other.capacity];
	
	for(int i = 0; i < other.capacity() || i < capacity; i++)
	{
		list[i] = temp[i];
	}
	
	capacity = other.capacity();
	size     = other.size();
	head	 = other.head;
	butt	 = other.butt;
}	

template<typename T>
void AwesomeVector<T>::set(int index, const T& stuff)
{
    if(index < capacity)
        list[index] = stuff;
}

template<typename T>
void AwesomeVector<T>::recapacitize()
{
	int oldCap = capacity;
	T * temp;
	temp = list;
	capacity *= 2;
	list = new T[capacity];
	
	int i = 0;
	
	for(int j = head; j != butt; j = (j + 1) % oldCap)
	{
		list[i] = temp[j];
		i++;
	}
	
	delete []temp;
}

template<typename T>
AwesomeVector<T>::AwesomeVector()
{
	list = new T[DEFAULTCAP];
	size = 0;
	capacity = DEFAULTCAP;
	head = 0;
	butt = 0;
}

template<typename T>
AwesomeVector<T>::AwesomeVector(int cap)
{
	capacity = cap;
	size = 0;
	list = new T[cap];
	head = 0;
	butt = 0;
}

template<typename T>
AwesomeVector<T>::AwesomeVector(const AwesomeVector<T> &other)
{
	copyV(other);
}

template<typename T>
AwesomeVector<T>::~AwesomeVector()
{
	delete []list;
}

template<typename T>
const T& AwesomeVector<T>::operator[](int i)
{
	if(i >= 0 && i < capacity)
		return list[i];
}

template<typename T>
const AwesomeVector<T> & AwesomeVector<T>::operator=(const AwesomeVector<T> &other)
{
	if(this != &other)
		copyV(other);
	
	return *this;
}

template<typename T>
void AwesomeVector<T>::destroy()
{
	delete [] list;
	list = new T[DEFAULTCAP];
	head = 0;
	butt = 0;
	size = 0;
	capacity = DEFAULTCAP;
}

template<typename T>
int AwesomeVector<T>::capacityOf()
{
	return capacity;
}

template<typename T>
int AwesomeVector<T>::sizeOf()
{
	return size;
}

template<typename T>
bool AwesomeVector<T>::isEmpty()
{
	return head == butt && size == 0;
}

template<typename T>
void AwesomeVector<T>::push_back(const T& item)
{

	size++;
	if(size == capacity)
		recapacitize();
	list[butt] = item;
	
	butt++;
	butt %= capacity;
}

template<typename T>
const T& AwesomeVector<T>::front()
{
	return list[head];
}

template<typename T>
const T& AwesomeVector<T>::back()
{
	if(butt != 0)
		return list[(butt - 1)];
	else
		return list[capacity - 1];
}

template<typename T>
bool AwesomeVector<T>::chop(const T& chosenOne)
{
	for(int i = 0; i < capacity; i++)
	{
		if(list[i] == chosenOne)
		{
			for(int j = i; j != butt; j = (j + 1) % capacity)
				list[j] = list[(j + 1) % capacity];
			return true;
		}
	}
	
	return false;
}


template <typename T>
void AwesomeVector<T>::erase(int i){
	if(i >= 0 && i < capacity){
		if(head < butt){
			if(i <= butt && i >= head && size != capacity){
				for(int j = i; j < butt; j++)
					list[j] = list[j + 1];
				butt--;
				size--;
			}else if(i <= butt && i >= head && size == capacity){
				for(int j = i; j < butt - 1; j++)
					list[j] = list[j + 1];
				butt--;
				size--;
			}else{
                qDebug() << "Element at specified index contains no info...\n";
			}
		}else if(head > butt){
			if(i > butt && i >= head){
				for (int j = i; j > head; j--)
					list[j] = list[j - 1];
				head++;
				size--;
			}else if(i <= butt && i < head){
				for(int j = i; j < butt; j++)
					list[j] = list[j + 1];
				butt--;
				size--;
			}else{
                qDebug() << "Element at specified index contains no info..\n";
			}
		}else if (head == butt){
			if(i == head){
				size = 0;
				head = 0;
				butt = 0;
			}
		}else if(isEmpty()){
            qDebug() << "Cannot delete from an empty vector...\n";
		}else{ 
            qDebug() << "ERROR: head and butt are in disarray\n";
		}
	}else{
        qDebug() << "Your index sucks. It needs to be between 0 - " << capacity - 1 << endl;
	}
}

template<typename T>
int AwesomeVector<T>::search(const T& chosenOne)
{
	for(int i = 0; i < capacity; i++)
	{
		if(list[i] == chosenOne)
		{
			return i;
		}
	}
	
	return -1;
}

template<typename T>
void AwesomeVector<T>::print()
{
	if(size == 0)
		cout << "Empty";
	else
	for(int i = head; i != butt; i = (i + 1) % capacity)
		cout << list[i] << " ";
	
	cout << endl;
}

/********************ITERATOR CLASS***********************************/
/*
template <typename T>
class theVectorator
{
public:
   theVectorator();
     //Default constructor
     //Postcondition: current = nullptr;

   theVectorator(int i);
     //Constructor with a parameter.
     //Postcondition: current = ptr;

   T operator*();
     //Function to overload the dereferencing operator *.
     //Postcondition: Returns the info contained in the node.

   theVectorator<T> operator++();    
     //Overload the pre-increment operator.
     //Postcondition: The iterator is advanced to the next 
     //               node.
	 
	theVectorator<T> operator--();

   bool operator==(const theVectorator<T>& right) const; 
     //Overload the equality operator.
     //Postcondition: Returns true if this iterator is equal to 
     //               the iterator specified by right, 
     //               otherwise it returns the value false.

   bool operator!=(const theVectorator<T>& right) const; 
     //Overload the not equal to operator.
     //Postcondition: Returns true if this iterator is not  
     //               equal to the iterator specified by  
     //               right; otherwise it returns the value 
     //               false.

private:
   T *current; //pointer to point to the current 
                            //node in the linked list
};

template <typename T>
theVectorator<T>::theVectorator()
{
    current = nullptr;
}

template <typename T>
theVectorator<T>::theVectorator(const AwesomeVector<T> & vec)
{
    current = 
}

template <typename T>
T theVectorator<T>::operator*()
{
    return current->info;
}

template <typename T>
theVectorator<T> theVectorator<T>::operator++()   
{
    current = current->next;

    return *this;
}

template <typename T>
theVectorator<T> theVectorator<T>::operator--()   
{
    current = current->back;

    return *this;
}

template <typename T>
bool theVectorator<T>::operator==
               (const theVectorator<T>& right) const
{
    return (current == right.current);
}

template <typename T>
bool theVectorator<T>::operator!=
                 (const theVectorator<T>& right) const
{    return (current != right.current);
}
*/

#endif
