#include <iostream>
#include <string_view>

enum class MonsterType
{
	ogre,
	dragon,
	orc,
	giantSpider,
	slime,
};

struct Profile
{
	MonsterType type{};
	std::string_view name{};
	int health{};
};

constexpr std::string_view getMonsterTypeString(MonsterType type)
{
	switch (type)
	{
	case MonsterType::ogre: return "ogre";
	case MonsterType::dragon: return "dragon";
	case MonsterType::orc: return "orc";
	case MonsterType::giantSpider: return "giantSpider";
	case MonsterType::slime: return "slime";
	default: return "Unknown";
	}
}

void printMonster(const Profile& m)
{
	std::cout << "This " << getMonsterTypeString(m.type) << " is named " << m.name
		<< " and has " << m.health << " health." << std::endl;
}

template <typename T>
struct Triad
{
	T num1{};
	T num2{};
	T num3{};
};

template <typename T>
void print(const Triad<T>& t)
{
	std::cout << '[' << t.num1 << ", " << t.num2 << ", " << t.num3 << ']';
}

int main()
{
	Profile ogre{ MonsterType::ogre, "Torg", 145 };
	Profile slime{ MonsterType::slime, "Blurp", 23 };

	printMonster(ogre);
	printMonster(slime);

	Triad t1{ 1,2,3 };
	print(t1);

	Triad t2{ 1.2, 3.4, 5.6 };
	print(t2);
	return 0;
}