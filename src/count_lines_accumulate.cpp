#include <iostream>
#include <string>
#include <numeric>

int f(const int previousCount, const int ch)
{
	return (ch == '\n') ? previousCount + 1 : previousCount;
}

int countLines(const std::string &str)
{
	return std::accumulate(str.begin(), str.end(), 0, f);
}

int main()
{
	const std::string str = "a\nbc\ndef\n";
	std::cout << countLines(str) << '\n';
}
