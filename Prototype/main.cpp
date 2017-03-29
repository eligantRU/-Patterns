#include "stdafx.h"

class IShip
{
public:
	virtual ~IShip() = default;
	virtual std::unique_ptr<IShip> Clone() const = 0;
};

class CWreckedShip
	:public IShip
{
public:
	std::unique_ptr<IShip> Clone() const override
	{
		return std::make_unique<CWreckedShip>(*this);
	}
};

int main()
{
	CWreckedShip ship;
	auto shipClone = ship.Clone();
	return 0;
}
