#pragma once

#include <boost/algorithm/string.hpp>

static const auto YANDEX_DOMEN_NAME = "yandex.ru";
static const auto BING_DOMEN_NAME = "bing.com";

std::string ToLower(const std::string & str)
{
	auto clone(str);
	boost::to_lower(clone);
	return clone;
}

class IEmailBuilder
{
public:
	virtual ~IEmailBuilder() = default;

	virtual std::string GetEmail() = 0;
	virtual void BuildLogin(const std::string &) = 0;
	virtual void BuildDomenName() = 0;
};

class CEmailBuilder
	:public IEmailBuilder
{
public:	
	std::string GetEmail() override
	{
		return (m_login + "@" + m_domenName);
	}

	void BuildLogin(const std::string & login) override
	{
		m_login = ToLower(login);
	}

protected:
	std::string m_login;
	std::string m_domenName;
};

class CYandexEmailBuilder
	:public CEmailBuilder
{
public:
	void BuildDomenName() override
	{
		m_domenName = ToLower(YANDEX_DOMEN_NAME);
	}
};

class CBingEmailBuilder
	:public CEmailBuilder
{
public:
	void BuildDomenName() override
	{
		m_domenName = ToLower(BING_DOMEN_NAME);
	}
};
