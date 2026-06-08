template<typename T>
MutantStack<T>::MutantStack() {
#if DEBUG
	std::cerr << "MutantStack was constructed (default)" << std::endl;
#endif
}

template<typename T>
MutantStack<T>::MutantStack(MutantStack &other): std::stack<T>(other) {
#if DEBUG
	std::cerr << "MutantStack was constructed (copy)" << std::endl;
#endif
}

template<typename T>
MutantStack<T>::~MutantStack() {
#if DEBUG
	std::cerr << "MutantStack was deconstructed" << std::endl;
#endif
}

template<typename T>
MutantStack<T>	&MutantStack<T>::operator=(MutantStack	&other) {
	if (this != &other)
		std::stack<T>::operator=(other);
	return (*this);
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin() {
	return (std::stack<T>::c.begin());
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end() {
	return (std::stack<T>::c.end());
}
