#include "Stack.h"

template<class T>
Stack<T>::~Stack()
{
	while (pop() != nullptr)
	{
		;
	}
}

template<class T>
void Stack<T>::push(T* item)
{
	if (item == nullptr)
	{
		throw invalid_argument("Can't push a Null item T");
	}
	Node<T>* newNode = new Node<T>(item);
	if (this->head == nullptr)
	{
		head = newNode;
	}
	else 
	{
		newNode->next = head;
		head = newNode;
	}
}

template<class T>
T* Stack<T>::pop()
{
	if (head == nullptr)
		return nullptr;
	Node<T> * temp = head;
	T* item = temp->item;
	head = head->next;	
	delete temp;
	return item;
}

template<class T>
T* Stack<T>::peek()
{
	if (head == nullptr)
		return nullptr;
	return head->item;
}
 