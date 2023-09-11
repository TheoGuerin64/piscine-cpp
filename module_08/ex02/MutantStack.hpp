#ifndef MUTANTSTACK_HPP_
#define MUTANTSTACK_HPP_

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack(void)
			: std::stack<T>()
		{}

		MutantStack(MutantStack const &other)
			: std::stack<T>(other)
		{}

		MutantStack &operator=(MutantStack const &other)
		{
			std::stack<T>::operator=(other);
			return *this;
		}

		~MutantStack()
		{}

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin(void)
		{
			return std::stack<T>::c.begin();
		}

		iterator end(void)
		{
			return std::stack<T>::c.end();
		}
};

#endif  // MUTANTSTACK_HPP_
