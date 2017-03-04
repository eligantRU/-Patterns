#pragma once

#include <memory>

class IJuice
{
public:
	virtual ~IJuice() = default;

	enum class JuiceType
	{
		Apple,
		Banana
	};
};

class CJuice
	:public IJuice
{
public:
	CJuice() = delete;
	CJuice(JuiceType type)
		:m_type(type)
	{

	}

private:
	JuiceType m_type;
};

class IJuiceFactory
{
public:
	~IJuiceFactory() = default;
	virtual std::unique_ptr<IJuice> GetAppleJuice() const = 0;
	virtual std::unique_ptr<IJuice> GetBananaJuice() const = 0;
};

class CJuiceFactory
	:public IJuiceFactory
{
public:
	std::unique_ptr<IJuice> GetAppleJuice() const override
	{
		return std::make_unique<CJuice>(IJuice::JuiceType::Apple);
	}

	std::unique_ptr<IJuice> GetBananaJuice() const override
	{
		return std::make_unique<CJuice>(IJuice::JuiceType::Banana);
	}
};
