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

		void insert(Hashable* item); //returns a key for the lookup later
		bool remove(Hashable* item);
		Hashable* lookup(Hashable* item);

		//compiler doesn't play nice with the namespace for overloaded template friend functions
		//so we define it in the header file and it doens't complain 
		//great documentation on the matter here - https://isocpp.org/wiki/faq/templates#template-friends
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
		int count = 0;
		LinkedList<Hashable>** table;

		//we use safe insert to prevent rehasing while the table is already rehashing
		void safeInsert(Hashable* item, bool isSafeInsert); 
		unsigned int hash(int key);
		void rehash();
		void initArray(LinkedList<Hashable>** ary);

};

