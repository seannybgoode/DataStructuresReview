#include "LinkedList.h"

template<class T>
LinkedList<T>::~LinkedList() {
	if (head != nullptr)
	{
		Node<T>* current = head;
		Node<T>* next = current->next;
		while (current != nullptr)
		{
			next = current->next;
			delete current;
			current = next;
		}
	}
}

template<class T>
void LinkedList<T>::insert(T* item)
{
	Node<T>* newNode = new Node<T>(item);
	listSize++;
	if (this->head == nullptr)
	{
		this->head = newNode;
	}
	else
	{
		newNode->next = this->head;
		this->head = newNode;
	}

}

template<class T>
T* LinkedList<T>::find(T item)
{
	return find(item.getKey());
}

template<class T>
T* LinkedList<T>::find(int key)
{
	Node<T>* prev = nullptr;
	Node<T>* next = nullptr;
	Node<T>* returnItem = findItemNeighbors(key, prev, next);
	if (returnItem != nullptr) //if item was found
	{
		if (prev == nullptr) //if front of list don't swap positions
		{
			return returnItem->item;
		}
		else //else if end of list or middle
		{
			prev->next = next;
			returnItem->next = head;
			head = returnItem;
		}
		return returnItem->item;
	}
	return nullptr;
}

template<class T>
T* LinkedList<T>::first()
{
	if (head == nullptr)
		return nullptr;
	else
		return head->item;
}

template<class T>
bool LinkedList<T>::remove(T item)
{
	return remove(item.getKey());
}

template<class T>
bool LinkedList<T>::remove(int key)
{
	Node<T>* prev = nullptr;
	Node<T>* next = nullptr;
	Node<T>* deleteItem = findItemNeighbors(key, prev, next);

	if (deleteItem != nullptr)
	{
		if (prev != nullptr) //if middle or end
		{
			prev->next = next;
		}
		else // if head of list
		{
			head = deleteItem->next;
		}
		delete deleteItem;
		listSize--;
		return true;
	}
	return false;
}


template<class T>
Node<T>* LinkedList<T>::findItemNeighbors(int key, Node<T>* prev, Node<T>* next)
{
	Node<T>* current = head;
	Node<T>* previous = nullptr;
	while (current != nullptr)
	{
		if (current->item->getKey() == key)
		{
			if (prev == nullptr)
			{
				next = current->next;
			}
			return current;
		}
		prev = current;
		current = current->next;
		if (current != nullptr)
		{
			next = current->next;
		}
		else
		{
			next = nullptr;
		}
	}
	prev = nullptr;
	next = nullptr;
	return nullptr;
}

template <class T>
std::ostream& operator<< <> (std::ostream& outputStream, const LinkedList<T>& list)
{
	Node<T>* current = list.getHead();
	while (current != nullptr)
	{
		outputStream << *(current->item) << " -> ";
		current = current->next;
	}
	outputStream << "nullptr";
	return outputStream;
}

;


