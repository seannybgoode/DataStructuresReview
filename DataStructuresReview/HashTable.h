#pragma once
#include <cstdlib>
#include "LinkedList.h"
#include "Hashable.h"

using namespace std;


template <class Hashable> class HashTable
{
	public:
		HashTable();
		~HashTable();

		void insert(Hashable* item);
		bool remove(int key);
		Hashable* lookup(int key);
		friend std::ostream& operator<< (std::ostream& outputStream, const HashTable<Hashable>& rhs)
		{
			for (int i = 0; i < rhs.size; i++)
			{
				outputStream << "[" << i << "]";
				if (rhs.table[i] == nullptr)
					outputStream << "nullptr" << "\n";
				else
					outputStream << *rhs.table[i] << "\n";
			}
			return outputStream;
		};

		int getSize() const { return size; };

	private:
		static const unsigned __int64 FIBBONACCI_HASH_MULTIPLIER = 11400714819323198485llu; //credit to Malte Skarupke - www.probablydance.com
		static const int DEFAULT_TABLE_SIZE = 16;
		int size = DEFAULT_TABLE_SIZE;
		LinkedList<Hashable>** table;

		unsigned int hash(int key);
		void rehash();
		void initArray(LinkedList<Hashable>** ary);

};

