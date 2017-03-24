#include "stdafx.h"

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

typedef CJuice CRussianJuice;

class IJuiceStore
{
public:
	virtual ~IJuiceStore() = default;
	virtual std::unique_ptr<IJuice> OrderJuice(IJuice::JuiceType) const = 0;
};

class CJuiceStore
	:public IJuiceStore
{
public:
	std::unique_ptr<IJuice> OrderJuice(IJuice::JuiceType type) const override
	{
		return CreateJuice(type);
	}
protected:
	virtual std::unique_ptr<IJuice> CreateJuice(IJuice::JuiceType) const = 0;
};

class CRussianJuiceStore
	:public CJuiceStore
{
protected:
	std::unique_ptr<IJuice> CreateJuice(IJuice::JuiceType type) const override
	{
		switch (type)
		{
		case IJuice::JuiceType::Apple:
			return std::make_unique<CRussianJuice>(IJuice::JuiceType::Apple);
		case IJuice::JuiceType::Banana:
			return std::make_unique<CRussianJuice>(IJuice::JuiceType::Banana);
		default:
			throw std::exception("Unsupported juice type");
		}
	}
};

void OrderJuiceWithFactoryMethod(const IJuiceStore & store)
{
	auto juice = store.OrderJuice(IJuice::JuiceType::Apple);
}

int main()
{
	CRussianJuiceStore store;
	OrderJuiceWithFactoryMethod(store);
	return 0;
}
