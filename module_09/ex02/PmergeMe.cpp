#include <string>
#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include <iomanip>
#include <algorithm>

#include "PmergeMe.hpp"

/* public */

static void insertSort(std::list<int> &input, std::list<int> &output)
{
	std::list<int>::iterator it = std::max_element(input.begin(), input.end());
	output.insert(output.begin(), *it);
	input.erase(it);

	if (!input.empty())
		insertSort(input, output);
}

std::list<int> PmergeMe::_mergeInsertSort(std::list<int> &input)
{
	if (input.size() <= 1)
		return input;

	int reminder = -1;
	if (input.size() % 2 == 1)
	{
		reminder = input.back();
		input.pop_back();
	}

	std::list<int>::iterator middle = input.begin();
	std::advance(middle, input.size() / 2);
	std::list<int> halfInputLow(input.begin(), middle);
	std::list<int> halfInputHigh(middle, input.end());

	std::list<int> sortedHalfInputLow;
	std::list<int> sortedHalfInputHigh;
	insertSort(halfInputLow, sortedHalfInputLow);
	insertSort(halfInputHigh, sortedHalfInputHigh);

	std::merge(sortedHalfInputLow.begin(), sortedHalfInputLow.end(), sortedHalfInputHigh.begin(), sortedHalfInputHigh.end(), input.begin());
	if (reminder != -1)
		input.insert(std::lower_bound(input.begin(), input.end(), reminder), reminder);

	return input;
}

static void insertSort(std::vector<int> &input, std::vector<int> &output)
{
	std::vector<int>::iterator it = std::max_element(input.begin(), input.end());
	output.insert(output.begin(), *it);
	input.erase(it);

	if (!input.empty())
		insertSort(input, output);
}

std::vector<int> PmergeMe::_mergeInsertSort(std::vector<int> &input)
{
	if (input.size() <= 1)
		return input;

	int reminder = -1;
	if (input.size() % 2 == 1)
	{
		reminder = input.back();
		input.pop_back();
	}

	std::size_t const halfSize = input.size() / 2;
	std::vector<int> halfInputLow(input.begin(), input.begin() + halfSize);
	std::vector<int> halfInputHigh(input.begin() + halfSize, input.end());

	std::vector<int> sortedHalfInputLow;
	std::vector<int> sortedHalfInputHigh;
	insertSort(halfInputLow, sortedHalfInputLow);
	insertSort(halfInputHigh, sortedHalfInputHigh);

	std::merge(sortedHalfInputLow.begin(), sortedHalfInputLow.end(), sortedHalfInputHigh.begin(), sortedHalfInputHigh.end(), input.begin());
	if (reminder != -1)
		input.insert(std::lower_bound(input.begin(), input.end(), reminder), reminder);

	return input;
}

static void printVector(std::vector<int> &vector)
{
	for (std::size_t i = 0; i < vector.size(); i++)
	{
		if (i == 4)
		{
			if (vector.size() > 5)
				std::cout << "[...]";
			else
				std::cout << vector[i];
			break;
		}
		std::cout << vector[i];
		if (i != vector.size() - 1)
			std::cout << " ";
	}
	std::cout << "\n";
}

void PmergeMe::merge(int const *input, int size)
{
	std::vector<int> vector(input, input + size);
	std::list<int> list(input, input + size);

	std::cout << "Before:\t";
	printVector(vector);

	double vectorElapsed = _mesureMergeExecTime(vector);
	double listElapsed = _mesureMergeExecTime(list);

	std::cout << "After:\t";
	printVector(vector);

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << std::setw(4) << size
			  << " elements with std::vector: " << vectorElapsed << " us\n";
	std::cout << "Time to process a range of " << std::setw(4) << size
			  << " elements with std::list : " << listElapsed << " us\n";
}

const char *PmergeMe::MergeFailException::what(void) const throw()
{
	return "Merge failed";
}

/* private */

PmergeMe::PmergeMe(void)
{}

PmergeMe::PmergeMe(PmergeMe const &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other)
{
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe()
{}
