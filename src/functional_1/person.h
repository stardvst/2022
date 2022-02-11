#pragma once

#include <string>

struct Person
{
	std::string name;
	bool isFemale{};
};

inline bool isFemale(const Person &person)
{
	return person.isFemale;
}

inline std::string name(const Person &person)
{
	return person.name;
}
