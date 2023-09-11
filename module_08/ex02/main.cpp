#include <iostream>
#include <list>

#include "MutantStack.hpp"

int main(void)
{
	MutantStack<int> mStack;
	std::list<int> list;

	mStack.push(7);
	mStack.push(8);
	mStack.push(9);
	mStack.push(10);
	std::cout << "mStack.top() = " << mStack.top() << std::endl;

	list.push_back(7);
	list.push_back(8);
	list.push_back(9);
	list.push_back(10);
	std::cout << "list.back() = " << list.back() << std::endl;

	mStack.pop();
	std::cout << "mStack.top() = " << mStack.top() << std::endl;

	list.pop_back();
	std::cout << "list.back() = " << list.back() << std::endl;

	MutantStack<int>::iterator it = mStack.begin();
	MutantStack<int>::iterator ite = mStack.end();
	for (; it != ite; ++it)
		std::cout << "mStack: " << *it << std::endl;

	std::list<int>::iterator it2 = list.begin();
	std::list<int>::iterator ite2 = list.end();
	for (; it2 != ite2; ++it2)
		std::cout << "list: " << *it2 << std::endl;

	return 0;
}
