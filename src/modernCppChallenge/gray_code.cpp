#include <bitset>
#include <iostream>
#include <string>

unsigned int grayEncode(const unsigned int num)
{
	return num ^ (num >> 1);
}

unsigned int grayDecode(unsigned int gray)
{
	for (auto bit = 1U << 31; bit > 1; bit >>= 1)
	{
		if (gray & bit)
			gray ^= bit >> 1;
	}
	return  gray;
}

std::string toBinary(const unsigned int value, const int digits)
{
	return std::bitset<32>(value).to_string().substr(32 - digits, digits);
}

int main()
{
	for (unsigned int n=0;n<32;++n)
	{
		const auto enc = grayEncode(n);
		const auto dec = grayDecode(enc);

		std::cout << toBinary(n, 5) << '\t' << toBinary(enc, 5) << '\t' << dec << '\n';
	}
	return 0;
}
