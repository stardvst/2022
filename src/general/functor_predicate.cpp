#include <functional>
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using tFunctor = std::function<bool(std::string)>;

struct Checker
{
	explicit Checker(std::vector<std::string> strings, tFunctor functor)
		: m_strings(std::move(strings))
		, m_functor(std::move(functor))
	{
	}

	void check() const
	{
		for (const auto &s : m_strings)
		{
			if (m_functor(s))
				std::cout << "predicate met: " << s << '\n';
		}
	}

private:
	std::vector<std::string> m_strings;
	tFunctor m_functor;
};

struct MaxLenPredicate
{
	explicit MaxLenPredicate(int maxLen) : m_maxLen(maxLen) {}
	MaxLenPredicate(MaxLenPredicate &&o) noexcept = default;

	bool operator()(const std::string &s) const
	{
		if (auto it = m_cache.find(s); it != m_cache.end())
			return it->second;

		auto isLong = (s.length() >= m_maxLen);
		m_cache.try_emplace(s, isLong);
		return isLong;
	}

private:
	struct StringHash
	{
		using is_transparent = void; // enables heterogeneous lookup

		std::size_t operator()(std::string_view sv) const
		{
			std::hash<std::string_view> hasher;
			return hasher(sv);
		}
	};

	mutable std::unordered_map<std::string, bool, StringHash, std::equal_to<>> m_cache;
	int m_maxLen{};
};

int main()
{
	std::vector<std::string> strings{ "a", "bbbb", "ccc", "ddddd" };

	Checker checker{ strings, MaxLenPredicate{ 4 } };
	checker.check();

	return 0;
}
