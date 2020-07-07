#pragma once
#include <cstdlib>
#include "Node.h"

template <class T> class Stack
{
	public:
		Stack<T>() { this->head = nullptr;};
		~Stack();

		void push(T* item);
		T* pop();
		T* peek();

	private:
		Node<T>* head;

};

