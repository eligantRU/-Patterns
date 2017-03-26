#include "stdafx.h"

class IObserver
{
public:
	virtual ~IObserver() = default;
	virtual void Update(const std::string &) = 0;
};

class IObservable
{
public:
	virtual ~IObservable() = default;
	virtual void AddObserver(IObserver &) = 0;
	virtual void RemoveObserver(IObserver &) = 0;
	virtual void NotifyObserver(const std::string &) = 0;
};

class CObservable
	:public IObservable
{
public:
	virtual ~CObservable() = default;

	void AddObserver(IObserver & ref) override
	{
		m_observers.push_back(&ref);
	}

	void RemoveObserver(IObserver & ref) override
	{
		m_observers.remove(&ref);
	}

	void NotifyObserver(const std::string & msg) override
	{
		for (auto &observer : m_observers)
		{
			observer->Update(msg);
		}
	}

private:
	std::list<IObserver*> m_observers;
};

class CNewspaper
	:public CObservable
{
public:
	void AddNews(const std::string & news)
	{
		NotifyObserver(news);
	}
};

class CCitizen
	:public IObserver
{
public:
	CCitizen(const std::string & name)
		:m_name(name)
	{

	}

	void Update(const std::string & msg) override
	{
		std::cout << m_name << " know that "
		          << msg << std::endl;
	}

private:
	std::string m_name;
};

int main()
{
	CCitizen citizen1("Petr");
	CCitizen citizen2("Vasya");
	CNewspaper newspaper;
	newspaper.AddObserver(citizen1);
	newspaper.AddObserver(citizen2);
	newspaper.AddNews("IBM shares fell in price");

	return 0;
}
