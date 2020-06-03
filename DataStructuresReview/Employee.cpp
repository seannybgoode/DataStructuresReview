#include "Employee.h"


Employee::Employee(string firstName, string lastName, int employeeNumber)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->employeeNumber = employeeNumber;
}

Employee::~Employee()
{

}

Employee Employee::operator=(Employee& other)
{
	return Employee(other.firstName, other.lastName, other.employeeNumber);
}

int Employee::hash()
{
	return std::hash<string>{}(this->firstName) * std::hash<string>{}(this->lastName) * std::hash<int>{}(this->employeeNumber);
}

int Employee::getKey()
{
	return this->employeeNumber;
}

bool operator==(const Employee& lhs, const Employee& rhs)
{
	return lhs.employeeNumber == rhs.employeeNumber;
}

bool operator<(const Employee& lhs, const Employee& rhs)
{
	return lhs.employeeNumber < rhs.employeeNumber;
}

bool operator>(const Employee& lhs, const Employee& rhs)
{
	return lhs.employeeNumber > rhs.employeeNumber;
}

bool operator<=(const Employee& lhs, const Employee& rhs)
{
	return lhs < rhs || lhs == rhs;
}

bool operator>=(const Employee& lhs, const Employee& rhs)
{
	return lhs > rhs || lhs == rhs;
}

ostream& operator<<(ostream& outputStream, const Employee& rhs)
{
	outputStream << rhs.employeeNumber << " : " + rhs.lastName+ ", " + rhs.firstName;
	return outputStream;
}
