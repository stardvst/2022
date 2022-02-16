#pragma once

#include <string>

struct Person
{
	Person() = default;

	explicit Person(std::string n = {}, bool const f = {}, const int a = {})
		: name(std::move(n)), isFemale(f), age(a)
	{
	}

	[[nodiscard]] int getAge() const
	{
		return age;
	}

	std::string name;
	bool isFemale{};
	int age{};
};

inline bool isFemale(const Person &person)
{
	return person.isFemale;
}

inline std::string name(const Person &person)
{
	return person.name;
}
