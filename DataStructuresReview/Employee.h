#pragma once
#include "Hashable.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;


class Employee : public Hashable
{	
	public:
		Employee(string firstName, string lastName, int employeeNumber); 
		
		~Employee();

		Employee operator= (Employee& other);
		friend bool operator== (const Employee& lhs, const Employee& rhs);
		friend bool operator< (const Employee& lhs, const Employee& rhs);
		friend bool operator> (const Employee& lhs, const Employee& rhs);
		friend bool operator<= (const Employee& lhs, const Employee& rhs);
		friend bool operator>= (const Employee& lhs, const Employee& rhs);
		friend ostream& operator<< (ostream& outputStream, const Employee& rhs);

		virtual int hash();
		virtual int getKey();

		string getFirstName() { return this->firstName; };
		string getLastName() { return this->lastName; };

		void setFirstName(string update) { this->firstName = update; }
		void setLastName(string update) { this->lastName = update; }
		void setFirstName(int update) { this->employeeNumber = update; }

	private:
		string firstName;
		string lastName;
		int employeeNumber;
		
};

