#include <vector>
#include <algorithm>
#include <iostream>

struct point
{
	double x;
	double y;

	bool operator<(const point &p) const
	{
		//return x < p.x && y < p.y;
		return std::tie(x, y) < std::tie(p.x, p.y); // lexicographical compare, or total order compare
	}
};

int main()
{
	std::vector<point> shape1
	{
		{ -10000, -53000 },
		{ -10000, -45000 },
		{ -6000, -45000 },
		{ -6000, -53000 },
		{ 10000, -53000 },
		{ 10000, -45000 },
		{ 14000, -45000 },
		{ 14000, -53000 },
		{ 26000, -53000 },
		{ 26000, -26000 },
		{ 30000, -26000 },
		{ 30000, -53000 },
		{ 42000, -53000 },
		{ 42000, -48000 },
		{ 46000, -48000 },
		{ 46000, -53000 },
		{ 74000, -34000 },
		{ 78000, -34000 },
		{ 78000, -53000 },
		{ 82000, -53000 },
		{ 82000, -57000 },
		{ -15000, -57000 },
		{ -15000, -53000 }
	};

	std::vector<point> shape2
	{
		{ -15000, -53000 },
		{ -10000, -53000 },
		{ -10000, -45000 },
		{ -6000, -45000 },
		{ -6000, -53000 },
		{ 10000, -53000 },
		{ 10000, -45000 },
		{ 14000, -45000 },
		{ 14000, -53000 },
		{ 26000, -53000 },
		{ 26000, -26000 },
		{ 30000, -26000 },
		{ 30000, -53000 },
		{ 42000, -53000 },
		{ 42000, -48000 },
		{ 46000, -48000 },
		{ 46000, -53000 },
		{ 74000, -34000 },
		{ 78000, -34000 },
		{ 78000, -53000 },
		{ 82000, -53000 },
		{ 82000, -57000 },
		{ -15000, -57000 }
	};

	std::sort(shape1.begin(), shape1.end());
	std::sort(shape2.begin(), shape2.end());

	for (const auto &pt : shape1)
	{
		std::cout << pt.x << ' ' << pt.y << ' ';
	}
	std::cout << '\n';
	for (const auto &pt : shape2)
	{
		std::cout << pt.x << ' ' << pt.y << ' ';
	}
}
