#pragma once

#include <memory>
#include <exception>

#include "Juice.h"
#include "Box.h"

class IBuilder
{
public:
	virtual ~IBuilder() = default;
	virtual std::unique_ptr<IBox> BuildJuiceBox(IJuice::JuiceType) const = 0;

private:
};

class CBuilder
	:public IBuilder
{
public:
	std::unique_ptr<IBox> BuildJuiceBox(IJuice::JuiceType type) const
	{
		auto box = m_boxFactory.GetBox();
		// box.SetLogo(DEFAULT_LOGO);

		std::unique_ptr<IJuice> juice;
		switch (type)
		{
		case IJuice::JuiceType::Apple:
			juice = m_juiceFactory.GetAppleJuice();
			break;
		case IJuice::JuiceType::Banana:
			juice = m_juiceFactory.GetBananaJuice();
			break;
		default:
			throw std::exception("Unsupported juice type");
		}
		box->SetJuice(std::move(juice));
		return box;
	}

private:
	CJuiceFactory m_juiceFactory;
	CBoxFactory m_boxFactory;
};
