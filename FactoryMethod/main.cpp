#include "stdafx.h"

class IWeapon
{
public:
	virtual ~IWeapon() = default;
	virtual void Attack() = 0;
};

class CSword
	:public IWeapon
{
public:
	void Attack() override
	{
		std::puts("Slash!");
	}
};

class CBow
	:public IWeapon
{
public:
	void Attack() override
	{
		std::puts("Pew!");
	}
};

class IHero
{
public:
	virtual ~IHero() = default;
	virtual std::unique_ptr<IWeapon> GetWeapon() = 0;
};

class CKnight
	:public IHero
{
public:
	std::unique_ptr<IWeapon> GetWeapon() override
	{
		return std::make_unique<CSword>();
	}
};

class CRogue
	:public IHero
{
public:
	std::unique_ptr<IWeapon> GetWeapon() override
	{
		return std::make_unique<CBow>();
	}
};

int main()
{
	auto elf = std::make_unique<CRogue>();
	if (true) // If monster
	{
		auto weapon = elf->GetWeapon();
		weapon->Attack();
	}
	return 0;
}
