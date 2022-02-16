#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#include "person.h"

class OlderThan
{
public:
	explicit constexpr OlderThan(const int limit)
		: m_limit(limit)
	{
	}

	template <typename T>
	bool operator()(T &&object)
	{
		return std::forward<T>(object).getAge() > m_limit;
	}

private:
	int m_limit{};
};

int main()
{
	std::vector<Person> people;
	people.emplace_back("Peter", false, 56);
	people.emplace_back("Marta", true, 24);
	people.emplace_back("Jane", true, 52);
	people.emplace_back("David", false, 84);
	people.emplace_back("Rose", true, 32);
	people.emplace_back("Tom", false, 31);

	std::cout << std::count_if(people.cbegin(), people.cend(), OlderThan(42)) << std::endl;
}
