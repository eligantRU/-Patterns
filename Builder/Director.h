#pragma once

#include <memory>

#include "Builder.h"

class CEmailDirector
{
public:
	CEmailDirector() = default;

	void ConstructEmail(const std::string & login)
	{
		m_pBuilder->BuildLogin(login);
		m_pBuilder->BuildDomenName();
	}

	void SetBuilder(std::shared_ptr<IEmailBuilder> builder)
	{
		m_pBuilder = builder;
	}

	std::string GetEmail()
	{
		return m_pBuilder->GetEmail();
	}

private:
	std::shared_ptr<IEmailBuilder> m_pBuilder = nullptr;
};
