#include <string>
#include <unordered_set>
#include <vector>
#include <iostream>

struct WordAtLevel
{
	std::string word;
	std::size_t level;
};

const std::string openingBracket("{");
const std::string closingBracket("}");

using tWordLevels = std::vector<WordAtLevel>;

class TclFormatter
{
public:
	explicit TclFormatter(std::string tclString);
	std::string formatted() const;

private:
	tWordLevels parse() const;
	static std::string build(tWordLevels wordAtLevels);
	std::string readUntilDelimiter() const;
	static bool isClosingBracket(const std::string &str);
	static std::string indentation(const std::size_t tabCount);

	std::string m_tclString;
	std::size_t m_strLen = 0;
	mutable std::size_t m_idx = 0;
	static constexpr int tabWidth = 4;

	mutable bool m_bPrevWordReserved = false;
	const std::unordered_set<std::string> m_reservedWords{ "coords", "properties" };
};

TclFormatter::TclFormatter(std::string tclString)
	: m_tclString(std::move(tclString))
	, m_strLen(m_tclString.length())
{
}

std::string TclFormatter::formatted() const
{
	const tWordLevels wordLevels = parse();
	return build(wordLevels);
}

tWordLevels TclFormatter::parse() const
{
	tWordLevels wordAtLevels;
	int level = 0;

	for (m_idx = 0; m_idx < m_strLen; ++m_idx)
	{
		switch (auto ch = m_tclString[m_idx])
		{
			case '}':
			{
				if (m_bPrevWordReserved)
					m_bPrevWordReserved = false;
				else
					--level;
				wordAtLevels.emplace_back(closingBracket, level);
				break;
			}
			case '{':
				wordAtLevels.emplace_back(openingBracket, level);
				if (!m_bPrevWordReserved)
					++level;
				[[fallthrough]];
			default:
			{
				std::string word = readUntilDelimiter();
				if (!word.empty())
				{
					if (m_reservedWords.contains(word))
						m_bPrevWordReserved = true;

					wordAtLevels.emplace_back(word, level);
				}
				break;
			}
		}
	}

	return wordAtLevels;
}

std::string TclFormatter::build(tWordLevels wordAtLevels)
{
	std::string result;
	const auto wordCount = wordAtLevels.size();
	bool previousIsClosingBracket = false;
	int idx = 0;
	while (idx < wordCount)
	{
		const auto &[word, level] = wordAtLevels[idx];

		result += indentation(level);
		result += word;

		previousIsClosingBracket = isClosingBracket(word);
		while (++idx < wordCount)
		{
			const auto &[nextWord, nextLevel] = wordAtLevels[idx];
			if (nextLevel != level)
				break;

			if (previousIsClosingBracket && !isClosingBracket(nextWord))
				break;
			
			result += ' ';
			result += nextWord;
		}

		result += '\n';
	}
	return result;
}

std::string TclFormatter::readUntilDelimiter() const
{
	std::string word;
	while (++m_idx < m_strLen)
	{
		const auto ch = m_tclString[m_idx];
		if (ch == ' ' || ch == '{' || ch == '}')
		{
			--m_idx;
			break;
		}
		word += ch;
	}
	return word;
}

bool TclFormatter::isClosingBracket(const std::string& str)
{
	return str == closingBracket;
}

std::string TclFormatter::indentation(const std::size_t tabCount)
{
	return std::string(tabCount * tabWidth, ' ');
}

int main()
{
	const TclFormatter f1("{data {a {obj {coords {10 10} comment {} radius 260 type circle}}}}");
	std::cout << f1.formatted() << '\n';

	const TclFormatter f2("{data {b {obj {coords {-95 -85 -70 -85 -75 -95} comment {abc} type polygon}}}}");
	std::cout << f2.formatted() << '\n';

	const TclFormatter f3("{data {c {obj {coords {-55 -65 -70 -65 -25 -64} comment {abc def} type polygon}}}}");
	std::cout << f3.formatted() << '\n';

	const TclFormatter f4("{data {d {obj {coords {59 60} comment {} type point}} e {obj {coords {928 324} comment {} type point}}}}");
	std::cout << f4.formatted() << '\n';
}
