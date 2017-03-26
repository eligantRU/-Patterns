#include "stdafx.h"

class IUnit
{
public:
	virtual ~IUnit() = default;
	virtual void Print() const = 0;
};

class CArcher
	:public IUnit
{
public:
	void Print() const override
	{
		std::cout << "Archer";
	}
};

class CKnight
	:public IUnit
{
public:
	void Print() const override
	{
		std::cout << "Knight";
	}
};

class CSquad
	:public IUnit
{
public:
	void Print() const override
	{
		std::cout << "Squad " << this << " ( ";
		for (auto &unit : m_units)
		{
			unit->Print();
			std::cout << " ";
		}
		std::cout << ")";
	}

	void Add(IUnit & unit)
	{
		m_units.push_back(&unit);
		unit.Print();
		std::cout << " joined squad " << this << std::endl;
	}

	// void Remove(IUnit & unit) {}

private:
	std::list<IUnit*> m_units;
};

int main()
{
	CKnight knight1;
	CKnight knight2;
	CArcher archer1;
	CArcher archer2;

	CSquad squad1;
	squad1.Add(knight1);
	squad1.Add(archer1);

	CSquad squad2;
	squad2.Add(knight2);
	squad2.Add(squad1);
	squad2.Add(archer2);

	squad2.Print();
	return 0;
}
