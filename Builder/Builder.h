#pragma once

#include <memory>
#include <exception>

#include "Juice.h"
#include "Box.h"

class IJuiceBoxBuilder
{
public:
	virtual ~IJuiceBoxBuilder() = default;

	virtual std::unique_ptr<IBox> GetJuiceBox() = 0;

	virtual void BuildJuice() = 0;
	virtual void BuildBox(/*const ILogo & logo*/) = 0;

private:
};

class CJuiceBoxBuilder
	:public IJuiceBoxBuilder
{
public:
	void BuildBox(/*const ILogo & logo*/) override
	{
		m_pBox = std::move(m_boxFactory.GetBox());
		// m_box.SetLogo(logo);
	}
	
	std::unique_ptr<IBox> GetJuiceBox() override
	{
		return std::move(m_pBox);
	}

protected:
	CJuiceFactory m_juiceFactory;
	CBoxFactory m_boxFactory;
	std::unique_ptr<IBox> m_pBox = nullptr;
};

class CAppleJuiceBoxBuilder
	:public CJuiceBoxBuilder
{
public:
	void BuildJuice() override
	{
		auto juice = m_juiceFactory.GetAppleJuice();
		m_pBox->SetJuice(std::move(juice));
	}
};

class CBananaJuiceBoxBuilder
	:public CJuiceBoxBuilder
{
public:
	void BuildJuice() override
	{
		auto juice = m_juiceFactory.GetBananaJuice();
		m_pBox->SetJuice(std::move(juice));
	}
};
