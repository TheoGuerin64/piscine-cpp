#ifndef PMERGEME_HPP_
#define PMERGEME_HPP_

#include <string>
#include <exception>
#include <list>
#include <vector>
#include <algorithm>

class PmergeMe {
	public:
		static void merge(int const *array, int size);

		class MergeFailException : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};


	private:
		PmergeMe(void);
		PmergeMe(PmergeMe const &other);
		PmergeMe &operator=(PmergeMe const &other);
		~PmergeMe();


		static std::list<int> _mergeInsertSort(std::list<int> &input);
		static std::vector<int> _mergeInsertSort(std::vector<int> &input);

		template <typename T>
		static double _mesureMergeExecTime(T &container)
		{
			clock_t start = clock();
			_mergeInsertSort(container);
			clock_t end = clock();

			return (end - start) / (double)CLOCKS_PER_SEC * 1000 ;
		}
};

#endif  // PMERGEME_HPP_
