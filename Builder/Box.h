#pragma once

#include <memory>

class IBox
{
public:
	virtual ~IBox() = default;

	virtual void SetJuice(std::unique_ptr<IJuice> juice) = 0;
};

class CBox
	:public IBox
{
public:
	void SetJuice(std::unique_ptr<IJuice> juice)
	{
		m_juice = std::move(juice);
	}

	// void SetLogo(ILogo & logo);

private:
	std::unique_ptr<IJuice> m_juice = nullptr;
};

class IBoxFactory
{
public:
	~IBoxFactory() = default;
	virtual std::unique_ptr<IBox> GetBox() const = 0;
};

class CBoxFactory
	:public IBoxFactory
{
public:
	std::unique_ptr<IBox> GetBox() const
	{
		return std::make_unique<CBox>();
	}
};
