#include <iostream>

int mySumOf3And5Divisors(const int upperLimit)
{
	int sum = 0;
	int num = 0;
	while (++num <= upperLimit)
	{
		if (num % 3 == 0 || num % 5 == 0)
			sum += num;
	}
	return  sum;
}

unsigned long long solSumOf3And5Divisors(const unsigned int upperLimit)
{
	unsigned long long sum = 0;
	unsigned int num = 2;
	while (++num <= upperLimit)
	{
		if (num % 3 == 0 || num % 5 == 0)
			sum += num;
	}
	return  sum;
}

int main()
{
	std::cout << "my solution:\n";
	std::cout << mySumOf3And5Divisors(100) << '\n';
	std::cout << mySumOf3And5Divisors(1234) << '\n';
	std::cout << mySumOf3And5Divisors(100005) << '\n';

	std::cout << "\nbook solution:\n";
	std::cout << solSumOf3And5Divisors(100) << '\n';
	std::cout << solSumOf3And5Divisors(1234) << '\n';
	std::cout << solSumOf3And5Divisors(100005) << '\n';
}
