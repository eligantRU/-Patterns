#pragma once

#include <memory>

class IBox
{
public:
	virtual ~IBox() = default;

	virtual void SetJuice(std::unique_ptr<IJuice> juice) = 0;

	// virtual void SetLogo(const ILogo & logo) = 0;
};

class CBox
	:public IBox
{
public:
	void SetJuice(std::unique_ptr<IJuice> juice) override
	{
		m_pJuice = std::move(juice);
	}

private:
	std::unique_ptr<IJuice> m_pJuice = nullptr;
};

class IBoxFactory
{
public:
	virtual ~IBoxFactory() = default;
	virtual std::unique_ptr<IBox> GetBox() const = 0;
};

class CBoxFactory
	:public IBoxFactory
{
public:
	std::unique_ptr<IBox> GetBox() const override
	{
		return std::make_unique<CBox>();
	}
};
