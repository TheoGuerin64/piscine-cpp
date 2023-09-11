#ifndef BRAIN_HPP_
#define BRAIN_HPP_

#include <string>

class Brain {
	public:
		Brain(void);
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		~Brain();

		std::string const &getIdea(int index);
		void setIdea(int index, std::string const &value);

	private:
		std::string _ideas[100];
};

#endif  // BRAIN_HPP_
