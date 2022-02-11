#include <algorithm>
#include <iostream>
#include <vector>

#include "person.h"

template <typename T>
T partitionPeople(T people)
{
	std::partition(people.begin(), people.end(), isFemale);
	return people;
}

template <typename T>
T stablePartitionPeople(T people)
{
	std::stable_partition(people.begin(), people.end(), isFemale);
	return people;
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

	std::cout << "partition:\n";
	for (const auto &partitioned = partitionPeople(people); const auto &[name, isFemale] : partitioned)
		std::cout << "name: " << name << ", isFemale: " << isFemale << '\n';

	std::cout << "\nstable partition:\n";
	for (const auto &partitioned = stablePartitionPeople(people); const auto &[name, isFemale] : partitioned)
		std::cout << "name: " << name << ", isFemale: " << isFemale << '\n';
}
