#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>
# include <algorithm>

class NotFoundExeption: public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Value is not in the container");
	}
};

template <typename T>
typename T::iterator easyfind(T &container, int val) {
	typename T::iterator res;

	res = find(container.begin(), container.end(), val);
	if (res == container.end())
		throw NotFoundExeption();

	return (res);
}

#endif
