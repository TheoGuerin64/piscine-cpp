#include <string>
#include <iostream>
#include <iomanip>

#include "Serializer.hpp"

int main(void)
{
	std::cout << std::boolalpha;

	Data *data = new Data;
	data->data = 42;

	std::cout << "data: " << std::hex << data << "\n";
	uintptr_t serialized = Serializer::serialize(data);
	std::cout << "serialized: " << std::hex << serialized << "\n";
	Data *deserialized = Serializer::deserialize(serialized);
	std::cout << "deserialized: " << std::hex << deserialized << "\n";

	std::cout << "data == deserialized: " << (data == deserialized) << "\n";

	delete data;
}
