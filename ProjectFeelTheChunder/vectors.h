#ifndef VECTORS_H
#define VECTORS_H

//#include "vectors.h"
#include <iostream>
using namespace std;

const int START_CAP = 4;
 
template <class T>
class Vectors
{
public:
	//constructors
	Vectors <T>();
	Vectors <T>(const Vectors <T>&);
	Vectors <T>(int);
	
	/* operator[]
	*	-function overloads the indexing brackets
	*	-preconditions: index must be positive or exception is thrown
	*	-postconditions: element at index is returned
	*/
	T& operator[](int);

	/* at
	*	-function that returns the item at a certain index
	*	-postconditions: returns a const reference to the item at the given index
	*					 does not change the array
	*	-preconditions: the parameter must be positive, if negative, exception is thrown */
	T at(int);
	
	/* insert
	*	-function that inserts an item before a specific item
	*	-preconditions: the index should be positive and within range, otherwise an exception is thrown
	*	-postconditions: the item is inserted at the index specified, and every other item is shifted right
	*/
	void insert(const T &, int);
	
	/* push_back
	*	-function that inserts an item at the end of the list
	*	-preconditions: n/a
	*	-postconditions: the item is inserted at the end of the list, and end is updated
	*/
	void push_back(const T &);
	
	/* set
	*	-function that sets an index to a specific item
	*	-preconditions: the index should be positive and within range, otherwise an exception is thrown
	*	-postconditions: the item is inserted at the index specified, and every other item is shifted right
	*/
	void set(const T &, int);
	
	/* erase
	*	-function that erases an item at a specified index
	*	-preconditions: the index should be positive and within range, otherwise an exception is thrown
	*	-postconditions: the item is erased at the index specified, and every advanced item is shifted left
	*/
	void erase(int);
	
	/* size
	*	-function that returns the size of the array in question
	*	-preconditions: n/a
	*	-postconditions: the size is returned
	*/
	int getSize();
	
	/* empty
	*	-function that returns the bool of whether the array in question is empty
	*	-preconditions: n/a
	*	-postconditions: true is returned if the vector is empty, else false
	*/
	bool empty();
	
	/* print
	*	-function that prints all elemens with their indices
	*	-preconditions: if empty, error message is printed
	*	-postconditions: vector is printed to screen
	*/
	void print();
	
	/* capacity
	*	-function that returns the capacity of the vector used
	*	-preconditions: n/a
	*	-postconditions: returns the number of elements that are able to be stored in array
	*/
	int getCapacity();
	
	
private:
	T *array;
	int size;
	int capacity;
	int front;
	int end;
	
	/* recapacitize
	*	-function to double the capacityof the array
	*	-preconditions: n/a
	*	-postconditions: the capacity is doubled, front becomes the first element at index 0 */
	void recapacitize();
};

/***********************************************************************************************************/
/*			DEFINITIONS																					   */
/***********************************************************************************************************/
template <class T>
Vectors<T>::Vectors()
{
	array = new T [START_CAP];
	capacity = START_CAP;
	size = 0;
	front = 0;
	end = 0;
}

template <class T>
Vectors<T>::Vectors(const Vectors <T> &other)
{
	//if(this != &other)
	//{
		array = other.array;
		capacity = other.capacity;
		size = other.size;
		front = other.front;
		end = other.end;
	//}
}

template <class T>
Vectors<T>::Vectors(int cap)
{
	if(cap > 0)
	{
		T *temp = array;
		//temp = array;
		array = new T [cap];
		delete temp;
		
		capacity = cap;
		size = 0;
		front = 0; 
		end = 0;
	}
	else
	{
		size = 0;
		front = 0;
		end = 0;
		capacity = START_CAP;
	}
}


template <class T>
void Vectors<T>::print()
{
	if(!empty())
	{
		if(front < end)
			for(int i = front; i <= end; i++)
				cout << "Index [" << i << "] is: " << array[i] << endl;
		else if(front == end)
			cout << "=Index [" << front << "] is: " << array[front] << endl;
		else
		{
			for(int j = front; j < capacity; j++)
				cout << "Index [" << j << "] is: " << array[j] << endl;
			for(int j = 0; j <= end; j++)
				cout << "Index [" << j << "] is: " << array[j] << endl;
		}
	}
	else
		cout << "Cannot print empty list.";
	cout << endl;
}

template <class T>
T& Vectors<T>::operator[](int i)
{
	if(i >= 0 && ((i >= front && i <= end) || (i <= end && i <= front)))
		return array[i];
	else 
		cout << "Accessing an invalid index. available indexes are " << front << '-' << end << endl;
}

template <class T>
T Vectors<T>::at(int i)
{
	if(i >= 0 && ((i >= front && i <= end) || (i <= end && i <= front)))
		return array[i];
	else 
		cout << "Accessing an invalid index. available indexes are " << front << '-' << end << endl;
}

template <class T>
void Vectors<T>::push_back(const T & item)
{
	insert(item, end + 1);
}

template <class T>
void Vectors<T>::insert(const T & item, int i)
{
	T temp;
	int j = 0;
	int k = 0;
	if(front < end && (i < front || i > end))
		i = end; 
	if(front > end && (i > end && i < front))
		i = end;
	
	if(front < end && size != capacity && size != 1)
	{
		for(j = end; j >= i; j--)
		{
			array[j + 1] = array[j];
		}
		array[i] = item;
		end++;
	}
	else if (size == 1)
	{
		if(i != 0)
			cout << "Forcing index to 0.\n";
		array[1] = array[0];
		front = 0;
		end = 1;
		array[1] = item;
	}
	else if(empty())
	{
		if(i != 0)
			cout << "Forcing index to 0.\n";
		array[0] = item;
		front = 0;
		end = 0;
	}
	else if(front > end && i <= end && size != capacity)
	{
		for(j = end; j >= i; j--)
		{
			array[j + 1] = array[j];
		}
		array[i] = item;	
		end++;
	}
	else if(front > end && i >= front && size != capacity)
	{
		for(j = front; j <= i; j++)
			array[j - 1] = array[j];
		
		array[i] = item;
		front--;
	}
	else if(size == capacity)
	{
		recapacitize();
		array[++end] = item;
	}
	else
		cout << "Something went wrong - insert" << endl;
	
	size++;
}

template <class T>
void Vectors<T>::recapacitize()
{
	T *temp;
	int k = 0;
	
	temp = array;
	
	array = new T [capacity * 2];
	
	if(front < end)
		for(int j = front; j <= end; j++)
			array[j] = temp[j];
	else
	{	
		k = 0;
		for(int j = front; j < capacity; j++)
			array[k++] = temp[j];
		
		for(int j = 0; j <= end; j++)
			array[k++] = temp[j];
		
		end = k - 1;
		front = 0;
	}
	
	delete temp;
	capacity *= 2;
}		

template <class T>	
void Vectors<T>::set(const T & item, int i)
{
	if(i >= 0 && i < capacity)
		array[i] = item;
	else
		cout << "Index was out of bounds, no effect." << endl;
}

template <class T>
void Vectors<T>::erase(int i)
{
	if(i >= 0 && i < capacity)
	{
		if(front < end)
			if(i <= end && i >= front && size != capacity)
			{
				for(int j = i; j < end; j++)
					array[j] = array[j + 1];
				end--;
				size--;
			}
			else if(i <= end && i >= front && size == capacity)
			{
				for(int j = i; j < end - 1; j++)
					array[j] = array[j + 1];
				array[end] = 0;
				end--;
				size--;
			}
			else
				cout << "Element at specified index contains no info...\n";
		else if(front > end)
			if(i > end && i >= front)
			{
				for (int j = i; j > front; j--)
					array[j] = array[j - 1];
				array[front] = 0;
				front++;
				size--;
			}
			else if(i <= end && i < front)
			{
				for(int j = i; j < end; j++)
					array[j] = array[j + 1];
				array[end] = 0;
				end--;
				size--;
			}
			else
				cout << "Element at specified index contains no info..\n";
		else if (front == end)
		{
			if(i == front)
			{
				array[i] = 0;
				size = 0;
				front = 0;
				end = 0;
			}
		}
		else if(empty())
			cout << "Cannot delete from an empty vector...\n";
		else 
			cout << "ERROR: front and end are in disarray\n";
	}
	else
		cout << "Your index sucks. It needs to be between 0 - " << capacity - 1 << endl;
}
			
template <class T>			
int Vectors<T>::getSize()
{
	return size;
}
	
template <class T>
bool Vectors<T>::empty()
{
	return size == 0;
}

template <class T>			
int Vectors<T>::getCapacity()
{
	return capacity;
}

#endif