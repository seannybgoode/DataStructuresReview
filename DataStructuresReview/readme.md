#Data Structures review in C++ 
Written by Sean Brophy, June 2nd, 2020 - sjbrophy.eastvan@gmail.com
All Rights Reserved (why are you using this anyway?)

#Fibbonacci Hashing
In college, the hashing algorithm was given to us. So, I wanted to take a stab at an implementation of my own. 
By using the irrational number phi, we've been able to create a hash that fairly evenly spaces our Hashables.

#Hashable
We created a virtual class, Hashable, that we'll need to extend to make this work. Hashable requires that two functions
be implemented. 

1) hash()

and

2) getKey()

This way some user could use our 'library' with their own types, by way of polymorphism.


#Summary
This is intended to be a demonstration of object oriented programming, some half-decent software engineering technique,
and a review of data structures in C++. 

We've used Visual C++, for the sake of getting up and coding a little faster, and to play with a
different flavour of C++. 

You can find me on stack overflow asking silly questions, then (usually) answering them on my own for the sake of the 
next person.

If you try to pass this off as homework, I will rat you out.