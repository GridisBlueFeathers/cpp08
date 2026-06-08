#include "MutantStack.hpp"
#include <iostream>

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "Stack top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Stack size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "Stack: " << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "mstack using for:";
	for (MutantStack<int>::iterator i = mstack.begin();
		i != mstack.end();
		i++)
		std::cout << " " << *i;
	std::cout << std::endl;

	MutantStack<std::string> stringStack;
	stringStack.push("Hello");
	stringStack.push("there");
	stringStack.push("general");
	stringStack.push("Kenobi");

	std::cout << "String stack:";
	for (MutantStack<std::string>::iterator i = stringStack.begin();
		i != stringStack.end();
		i++)
		std::cout << " " << *i;
	std::cout << std::endl;

	return 0;
}
