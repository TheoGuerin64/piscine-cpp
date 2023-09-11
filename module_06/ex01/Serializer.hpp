#ifndef SERIALIZER_HPP_
#define SERIALIZER_HPP_

#include <stdint.h>

struct Data {
	int data;
};

class Serializer {
	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);

	private:
		Serializer(void);
		Serializer(Serializer const &other);
		Serializer &operator=(Serializer const &other);
		~Serializer();
};

#endif  // SERIALIZER_HPP_
