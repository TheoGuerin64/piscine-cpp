#ifndef EASYFIND_HPP_
#define EASYFIND_HPP_

#include <vector>
#include <algorithm>

template <typename T>
int *easyfind(T &container, int value)
{
	typename T::iterator result = std::find(container.begin(), container.end(), value);
	if (result != container.end())
		return &*result;
	else
		return NULL;
}

#endif  // EASYFIND_HPP_
