#pragma once

#include "Builder.h"

class CJuiceBoxDirector
{
public:
	CJuiceBoxDirector() = default;

	void ConstructJuiceBox()
	{
		m_pBuilder->BuildBox();
		m_pBuilder->BuildJuice();
	}

	void SetBuilder(std::shared_ptr<IJuiceBoxBuilder> builder)
	{
		m_pBuilder = builder;
	}

	std::unique_ptr<IBox> GetJuiceBox()
	{
		return m_pBuilder->GetJuiceBox();
	}

private:
	std::shared_ptr<IJuiceBoxBuilder> m_pBuilder = nullptr;
};
