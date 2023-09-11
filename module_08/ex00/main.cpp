#include <iostream>
#include <vector>
#include <list>

#include "easyfind.hpp"

int main()
{
	{
		std::cout << "Vector:\n";

		std::vector<int> vector;
		vector.push_back(0);
		vector.push_back(1);
		vector.push_back(2);
		vector.push_back(3);
		vector.push_back(4);
		vector.push_back(5);
		vector.push_back(6);
		vector.push_back(7);
		vector.push_back(8);
		vector.push_back(9);

		std::cout << "0: " << *easyfind(vector, 0) << "\n";
		std::cout << "5: " << *easyfind(vector, 5) << "\n";
		std::cout << "9: " << *easyfind(vector, 9) << "\n";
		std::cout << "10: " << (easyfind(vector, 10) ? "FOUND": "NULL") << "\n\n";
	}
	{
		std::cout << "List:\n";

		std::list<int> list;
		list.push_back(0);
		list.push_back(1);
		list.push_back(2);
		list.push_back(3);
		list.push_back(4);
		list.push_back(5);
		list.push_back(6);
		list.push_back(7);
		list.push_back(8);
		list.push_back(9);

		std::cout << "0: " << *easyfind(list, 0) << "\n";
		std::cout << "5: " << *easyfind(list, 5) << "\n";
		std::cout << "9: " << *easyfind(list, 9) << "\n";
		std::cout << "10: " << (easyfind(list, 10) ? "FOUND": "NULL") << "\n";
	}
}
