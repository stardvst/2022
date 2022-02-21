#include <iostream>

int myGcd(const int x, const int y)
{
	return y == 0 ? x : myGcd(y, x % y);
}

unsigned int solGcd(const unsigned int x, const unsigned int y)
{
	return y == 0 ? x : myGcd(y, x % y);
}

unsigned int sol2Gcd(unsigned int x, unsigned int y)
{
	while (y != 0)
	{
		const unsigned int r = x % y;
		x = y;
		y = r;
	}
	return x;
}

int main()
{
	std::cout << "my solution:\n";
	std::cout << myGcd(12, 8) << '\n';
	std::cout << myGcd(8, 12) << '\n';
	std::cout << myGcd(1000, 468) << '\n';
	std::cout << myGcd(468, 1000) << '\n';

	std::cout << "\nbook solution:\n";
	std::cout << solGcd(12, 8) << '\n';
	std::cout << solGcd(8, 12) << '\n';
	std::cout << solGcd(1000, 468) << '\n';
	std::cout << solGcd(468, 1000) << '\n';

	std::cout << "\nbook solution 2:\n";
	std::cout << sol2Gcd(12, 8) << '\n';
	std::cout << sol2Gcd(8, 12) << '\n';
	std::cout << sol2Gcd(1000, 468) << '\n';
	std::cout << sol2Gcd(468, 1000) << '\n';
}
