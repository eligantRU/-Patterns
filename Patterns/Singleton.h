#pragma once

#include <string>

class CSingleton
{
public:
	CSingleton(const CSingleton &) = delete;
	CSingleton & operator=(const CSingleton &) = delete;

	static CSingleton & GetInstance()
	{
		static CSingleton instance;
		return instance;
	}

	std::string GetOwnerName() const
	{
		return m_ownerName;
	}

	void SetOwnerName(const std::string & name)
	{
		m_ownerName = name;
	}

private:
	CSingleton() = default;

	std::string m_ownerName;
};
