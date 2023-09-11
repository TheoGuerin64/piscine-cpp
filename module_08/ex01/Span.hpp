#ifndef SPAN_HPP_
#define SPAN_HPP_

#include <exception>
#include <vector>
#include <algorithm>

class Span  {
	public:
		Span(void);
		Span(unsigned int n);
		Span(Span const &other);
		Span &operator=(Span const &other);
		~Span();

		void addNumber(int number);
		int shortestSpan();
		int longestSpan();

		template <typename T>
		void fill(T begin, T end)
		{
			_vector.clear();
			if (std::distance(begin, end) > _max)
				throw SpanFullException();
			for (T it = begin; it != end; it++)
				_vector.insert(std::upper_bound(_vector.begin(), _vector.end(), *it), *it);
		}

		class SpanFullException : public std::exception {
			public:
				char const *what() const throw();
		};
		class SpanTooSmallException : public std::exception {
			public:
				char const *what() const throw();
		};

	private:
		std::vector<int> _vector;
		unsigned int _max;
};

#endif  // SPAN_HPP_
