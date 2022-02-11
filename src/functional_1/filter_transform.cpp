#include <algorithm>
#include <iostream>
#include <vector>

#include "person.h"

using tStringList = std::vector<std::string>;

template <typename T>
tStringList filterFemalesNames(T people)
{
	// filter
	T females{};
	std::copy_if(people.begin(), people.end(), std::back_inserter(females), isFemale);

	// transform
	tStringList femaleNames(females.size());
	std::transform(females.begin(), females.end(), femaleNames.begin(), name);

	return femaleNames;
}

int main()
{
	std::vector<Person> people;
	people.emplace_back("Peter", false);
	people.emplace_back("Marta", true);
	people.emplace_back("Jane", true);
	people.emplace_back("David", false);
	people.emplace_back("Rose", true);
	people.emplace_back("Tom", false);

	std::cout << "females:\n";
	for (const auto &femaleNames = filterFemalesNames(people); const auto &name : femaleNames)
		std::cout << name << '\n';
}
