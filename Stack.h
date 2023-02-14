#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstddef>

using namespace std;

// Stack Template
template <class T>
class Stack
{
private:
	T* stackArray;
	int stackSize;
	int top;

public:
	// Constructor
	Stack(int);

	// Copy Constructor
	// Takes object for existing stack
	Stack(const Stack&);

	// Destructor
	~Stack();

	// Stack operations
	void push(T);
	void pop(T&);
	bool isFull();
	bool isEmpty();
	bool dump();
};

// CONSTRUCTOR
template <class T>
Stack<T>::Stack(int size)
{
	stackArray = new T[size];
	stackSize = size;
	top = -1;
}

// COPY CONSTRUCTOR
template <class T>
Stack<T>::Stack(const Stack& obj)
{
	// Create the stack array
	if (obj.stackSize > 0)
		stackArray = new T[obj.stackSize];
	else
		stackArray = NULL;

	// Copy the stackSize attribute
	stackSize = obj.stackSize;

	// Copy the stack contents
	for (int count = 0; count < stackSize; count++)
		stackArray[count] = obj.stackArray[count];

	// Set the top of the stack.
	top = obj.top;
}

// Destructor
template <class T>
Stack<T>::~Stack()
{
	if (stackSize > 0)
		delete[] stackArray;
}

// Member function push : Pushes the argument onto the stack
template <class T>
void Stack<T>::push(T item)
{
	if (isFull())
		std::cout << "The Stack is full" << std::endl;
	else
	{
		top++;
		stackArray[top] = item;
		std::cout << "Pushed to stack" << std::endl;
	}
}

// Member function pop: Pops the value at the top of the stack off,
// and copies it into the variable passed as an argument
template <class T>
void Stack<T>::pop(T& item)
{
	if (isEmpty())
		std::cout << "The Stack is empty" << std::endl;

	else
	{
		item = stackArray[top];
		top--;
	}
}

// Member function isFull: Returns true if the stack is full, or false otherwise
template <class T>
bool Stack<T>::isFull()
{
	bool status;

	if (top == stackSize - 1)
		status = true;
	else
		status = false;

	return status;
}

// Member function isEmpty: Returns true if the stack is empty, false otherwise
template <class T>
bool Stack<T>::isEmpty()
{
	bool status;

	if (top == -1)
		status = true;
	else
		status = false;

	return status;
}

// Member function dump: Prints the contents of the stack is empty, or false otherwise
template <class T>
bool Stack<T>::dump()
{
	int i;
	std::cout << "Stack Contents: " << std::endl;
	std::cout << "---------------------" << std::endl;
	for (i = 0; i <= top; i++)
		std::cout << '\t' << stackArray[i] << std::endl;
}
#endif 