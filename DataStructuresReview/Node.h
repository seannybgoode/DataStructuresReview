#pragma once
#include<cstdlib>
#include<iostream>
using namespace std;

template <class T> class Node
{
	public:
		Node(T* item) { this->item = item; this->next = nullptr; };
		T* item;
		Node<T>* next;
	private:
};

