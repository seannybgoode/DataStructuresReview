// DataStructuresReview.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Employee.h"
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "HashTable.h"
#include "HashTable.cpp"

using namespace std;

void readFile(string fileName, HashTable<Employee>* ht)
{
    string text = "";
    std::ifstream fileInput;
    fileInput.open(fileName);
    while (std::getline(fileInput, text))
    {
        string lastName, firstName;
        int eeid;
        unsigned int indexPlaceholder = text.find(',');
        eeid = std::stoi(text.substr(0,indexPlaceholder));

        text = text.substr(indexPlaceholder + 2, text.length());
        indexPlaceholder = text.find(',');
        lastName = text.substr(0, indexPlaceholder);

        text = text.substr(indexPlaceholder + 2, text.length());

        firstName = text; 
        ht->insert(new Employee(firstName, lastName, eeid)); 
    }
}

int main()
{
    Employee* test1 = new Employee("Bob", "Smith", 1234);
    Employee* test2 = new Employee("Sally", "Johnson", 1233);
    Employee* test3 = new Employee("Jenna", "Stuart", 1211);
    Employee* test4 = new Employee("Alex", "Herbert", 1101);
    Employee* blank = nullptr;
    //Linked Lists Tests TODO

    //Empty List Tests
    LinkedList<Employee>* list = new LinkedList<Employee>();
    blank = list->find(test1->getKey());
    if (blank == nullptr)
    {
        cout << "empty find passed \n";
    }
    blank = list->find(*test1);
    if (blank == nullptr)
    {
        cout << "empty find 2 passed \n";
    }
    bool success = list->remove(*test1);
    bool success2 = list->remove(test1->getKey());
    if (!success)
    {
        cout << "empty remove 1 passed\n";
    }
    if (!success2)
    {
        cout << "empty remove 2 passed\n";
    }
    list->insert(test1);
    cout << "insert passed\n";
    //Test all fns w/ 1 item list
    blank = list->find(test1->getKey());
    if (blank != nullptr)
    {
        cout << blank->getFirstName() + " " + blank->getLastName();
    }
    else 
    {
        cout << "find test 1 failed";
    }
    
    blank = list->find(*test1);
    if (blank != nullptr)
    {
        cout << blank->getFirstName() + " " + blank->getLastName() + "\n";
    }
    else
    {
        cout << "find test 2 failed\n";
    }
    success = list->remove(test1->getKey());
    if (success)
    {
        cout << "remove test success" << "\n";
        success = false;
    }

    list->insert(test1);
    list->insert(test2);
    list->insert(test3);
    list->insert(test4);

    cout << *test1 << "\n";
    //test list output
    cout << *list << "\n";

    //Test find & delete w/ last item in list
    //success = list->remove(test1->getKey());
    if (success)
    {
        cout << "successfully deleted last item in list, " << test1->getKey() << "\n";
    }

    //delete list;

    HashTable<Employee>* ht = new HashTable<Employee>();
    readFile("employees.txt", ht);

    cout << *ht;

    //cout << (Employee) * (ht->lookup(1234)) << " - lookup success";
    

    //delete *ht;

}

