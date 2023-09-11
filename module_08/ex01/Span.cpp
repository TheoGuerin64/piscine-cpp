#include <algorithm>

#include "Span.hpp"

Span::Span(void) : _max(0)
{}

Span::Span(unsigned int n) : _max(n)
{}

Span::Span(Span const &other)
{
	*this = other;
}

Span &Span::operator=(Span const &other)
{
	_vector = other._vector;
	_max = other._max;
	return *this;
}

Span::~Span()
{}

void Span::addNumber(int number)
{
	if (_vector.size() == _max)
		throw SpanFullException();
	_vector.insert(std::upper_bound(_vector.begin(), _vector.end(), number), number);
}

int Span::shortestSpan()
{
	if (_vector.size() < 2)
		throw SpanTooSmallException();
	int dist = _vector[1] - _vector[0];
	for (std::vector<int>::iterator it = _vector.begin() + 1; (it + 1) != _vector.end(); it++)
	{
		int tmp_dist = *(it + 1) - *it;
		if (tmp_dist < dist)
			dist = tmp_dist;
	}
	return dist;
}

int Span::longestSpan()
{
	if (_vector.size() < 2)
		throw SpanTooSmallException();
	return _vector.back() - _vector.front();
}

char const *Span::SpanFullException::what() const throw()
{
	return "Span is full";
}

char const *Span::SpanTooSmallException::what() const throw()
{
	return "Span is too small";
}
