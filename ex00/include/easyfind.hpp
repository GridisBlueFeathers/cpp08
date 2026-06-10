#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <stdexcept>
# include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int val) {
	typename T::iterator res;

	res = find(container.begin(), container.end(), val);
	if (res == container.end())
		throw std::runtime_error("Value is not in the container");

	return (res);
}

#endif
