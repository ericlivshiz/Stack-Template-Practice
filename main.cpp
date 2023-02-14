#include <iostream>
#include "Stack.h"

int main()
{
	char stackSize = 50;
	string test = "Apple";

	Stack<string> stack{ stackSize };

	stack.pop(test);
	stack.push(test);
}