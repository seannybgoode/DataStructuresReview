#pragma once
#include <cstdlib>
#include <iostream>
#include "Node.h"

using namespace std;

template <class T> class LinkedList
{
	public:
		LinkedList<T>() { this->head = nullptr; listSize = 0; };
		~LinkedList();
		friend std::ostream& operator<< <> (std::ostream& outputStream, const LinkedList<T>& list);

		//we don't check if you're putting in a duplicate to keep the insert at O(1)
		//you're on your own if you do that
		void insert(T* item); 

		//O(n) worst case, O(1) best case, we move queried items to the front, to get more best cases
		T* find(T item); //returns nullptr if not found
		T* find(int key);

		T* first();
		
		//complexity same as find
		bool remove(int key);
		bool remove(T item);

		int length() { return listSize; }
		

		Node<T>* getHead() const { return head; };
	private:
		Node<T>* findItemNeighbors(int item, Node<T>* prev, Node<T>* next);
		unsigned int listSize;
		Node<T>* head;

};


