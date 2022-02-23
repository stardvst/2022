#include <iostream>
#include <vector>

template <class C, class T>
bool contains(const C &c, const T &value)
{
	return std::find(std::begin(c), std::end(c), value) != std::end(c);
}

template <class C, class ...T>
bool containsAny(const C &c, T &&...value)
{
	return (... || contains(c, value));
}

template <class C, class ...T>
bool containsAll(const C &c, T &&...value)
{
	return (... && contains(c, value));
}

template <class C, class ...T>
bool containsNone(const C &c, T &&...value)
{
	return !containsAny(c, std::forward<T>(value)...);
}

int main()
{
	std::vector<int> v{ 5, 7, 8, 2, 10 };
	std::cout << containsAny(v, 4, 3) << '\t' << containsAny(v, 4, 8) << '\n';
	std::cout << containsAll(v, 4, 8) << '\t' << containsAll(v, 2, 8) << '\n';
	std::cout << containsNone(v, 4, 8) << '\t' << containsNone(v, 3, 4) << '\n';
}
