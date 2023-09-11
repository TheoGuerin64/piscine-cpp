#ifndef ITER_HPP_
#define ITER_HPP_

template <typename T>
void iter(T *array, unsigned int size, void (*func)(T &))
{
	for (unsigned int i = 0; i < size; i++)
		func(array[i]);
}

#endif  // ITER_HPP_
