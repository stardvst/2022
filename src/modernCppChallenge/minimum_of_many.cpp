#include <iostream>

template <typename T>
T minimum(const T a, const T b)
{
	return a < b ? a : b;
}

template <typename T1, typename ...T>
T1 minimum(const T1 a, const T ...args)
{
	return minimum(a, minimum(args...));
}

template <class Compare, typename T>
T minimumc(Compare comp, const T a, const T b)
{
	return comp(a, b) ? a : b;
}

template <class Compare, typename T1, typename ...T>
T1 minimumc(const Compare comp, const T1 a, const T ...args)
{
	return minimumc(comp, a, minimumc(comp, args...));
}

int main()
{
	std::cout << minimum(5, 4, 2, 3) << '\n';
	std::cout << minimum(5, 4, 2, 3, -100) << '\n';
	std::cout << minimum(-100, 5, 4, 2, 3) << '\n';

	std::cout << minimumc(std::less<>(), 5, 4, 2, 3) << '\n';
	std::cout << minimumc(std::less<>(), 5, 4, 2, 3, -100) << '\n';
	std::cout << minimumc(std::less<>(), -100, 5, 4, 2, 3) << '\n';
}
