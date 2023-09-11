#ifndef RPN_HPP_
#define RPN_HPP_

#include <string>
#include <stack>
#include <exception>

class RPN {
	public:
		static int resolve(std::string const &calcul);

		class CalculNotValidException : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};


	private:
		static std::string const _operators;

		RPN(void);
		RPN(RPN const &other);
		RPN &operator=(RPN const &other);
		~RPN();

		static int _resolveOperation(char op, int a, int b);
};

#endif  // RPN_HPP_
