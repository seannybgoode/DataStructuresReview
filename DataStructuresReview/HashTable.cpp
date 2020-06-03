#include "HashTable.h"

template<class Hashable>
HashTable<Hashable>::HashTable()
{
	table = new LinkedList<Hashable>* [DEFAULT_TABLE_SIZE];
	initArray(table);
};

template<class Hashable>
HashTable<Hashable>::~HashTable()
{
	for (int i = 0; i < table->length; i++)
	{
		if(table[i] != nullptr)
			delete table[i];
	}
	delete table;
}

template<class Hashable>
void HashTable<Hashable>::insert(Hashable* item)
{
	int key = item->getKey();
	unsigned int hash = this->hash(key);
	if (table[hash] == nullptr)
	{
		table[hash] = new LinkedList <Hashable>();
	}
	table[hash]->insert(item);
	if (table[hash]->length() > 3) //if we get more than 3 collisions resize and rehash the table
	{
		rehash(); 
	}
}

template<class Hashable>
bool HashTable<Hashable>::remove(int key)
{
	int hash = hash(key);
	return table[hash]->remove(key);
}

template<class Hashable>
Hashable* HashTable<Hashable>::lookup(int key)
{
	unsigned int hash = this->hash(key);
	Hashable* item = table[hash]->find(key);
	return item;
}

template<class Hashable>
unsigned int HashTable<Hashable>::hash(int key)
{
	int length = size - 1;
	int numBits = 0;
	int shiftHashBits = 0;
	unsigned int hash = 0;
	//determine the number of bits we need to shift
	while (length > 0)
	{
		length = length >> 1;
		numBits++;
	}
	shiftHashBits = 64 - numBits;
	
	//multiply the key by our magic fibbonacci number, to get an even position of our number in the 
	//table - basically, it evenly spaces our hashes without overlapping
	hash = key * FIBBONACCI_HASH_MULTIPLIER; // TODO - fix 32 bit limitations
	
	//shift the hash by the number of bits needed, to get a position within our array
	//this is less expensive that modulo, which is the reason for the esoteric code here
	hash = hash >> shiftHashBits;
	return hash;
}


template<class Hashable>
void HashTable<Hashable>::rehash()
{
	this->size = this->size * 2;  //increase by a power of 2 for each resize
	LinkedList<Hashable>** oldTable = table;
	this->table = new LinkedList<Hashable>* [this->size]; //apply the size to the table
	initArray(table);

	Hashable* item = nullptr;
	for (int i = 0; i < size/2; i++)
	{
		while ((item = oldTable[i]->first()) != nullptr)
		{
			if (!oldTable[i]->remove(*item)) //if the item isn't in the list, something has gone very wrong
				throw;
			insert(item);
		}
		delete oldTable[i];
	}
	delete oldTable;
}
template<class Hashable>
void HashTable<Hashable>::initArray(LinkedList<Hashable>** ary)
{
	for (int i = 0; i < this->size; i++)
	{
		ary[i] = nullptr; //if only the C++ compiler would initialize this memory when I call new *sigh*
	}
}

;


