#include <iostream>

#include "Span.hpp"

int main(void)
{
	{
		Span sp = Span(20000);
		std::vector<int> v;
		for (int i = 0; i < 20000; i++)
			v.push_back(i);
		sp.fill(v.begin(), v.end());

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		Span sp = Span(10);
		try
		{
			sp.shortestSpan();
		}
		catch (Span::SpanTooSmallException const &e)
		{
			std::cout << e.what() << std::endl;
		}

		sp.addNumber(-3);
		sp.addNumber(0);
		sp.addNumber(21);
		sp.addNumber(18);
		sp.addNumber(6);
		sp.addNumber(12);
		sp.addNumber(3);
		sp.addNumber(9);
		sp.addNumber(15);
		sp.addNumber(28);
		try
		{
			sp.addNumber(69);
		}
		catch (Span::SpanFullException const &e)
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
}
