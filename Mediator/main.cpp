#include "stdafx.h"

class IChatUser
{
public:
	virtual ~IChatUser() = default;
	virtual void Send(const std::string &, IChatUser *) = 0;
	virtual void Recieve(const std::string &) = 0;
};

class IMediator
{
public:
	virtual ~IMediator() = default;
	virtual void Send(const std::string &, IChatUser *) = 0;
};

class CChatUser
	:public IChatUser
{
public:
	virtual ~CChatUser() = default;
	CChatUser(IMediator & mediator)
		:m_mediator(mediator)
	{}

	void Send(const std::string & msg,
	          IChatUser * user) override
	{
		m_mediator.Send(msg, user);
	}

private:
	IMediator & m_mediator;
};

class CDialog
	:public IMediator
{
public:
	void Send(const std::string & msg,
	          IChatUser * user) override
	{
		if (user == m_user1)
		{
			m_user2->Recieve(msg);
		}
		else if (user == m_user2)
		{
			m_user1->Recieve(msg);
		}
		else
		{
			throw std::runtime_error("Fuck-up");
		}
	}

	void SetFirstUser(IChatUser * user)
	{
		m_user1 = user;
	}

	void SetSecondUser(IChatUser * user)
	{
		m_user2 = user;
	}
	
private:
	IChatUser * m_user1;
	IChatUser * m_user2;
};

class CBoss
	:public CChatUser
{
public:
	CBoss(IMediator & mediator)
		:CChatUser(mediator)
	{}

	void Send(const std::string & msg)
	{
		CChatUser::Send(msg, this);
	}

	void Recieve(const std::string & msg) override
	{
		std::cout << "Boss gets message: " << msg << std::endl;
	}
};

class CVassal
	:public CChatUser
{
public:
	CVassal(IMediator & mediator)
		:CChatUser(mediator)
	{}

	void Send(const std::string & msg)
	{
		CChatUser::Send(msg, this);
	}

	void Recieve(const std::string & msg) override
	{
		std::cout << "Vassal gets message: " << msg << std::endl;
	}
};

int main()
{
	CDialog dial;
	CBoss boss(dial);
	CVassal vassal(dial);
	
	dial.SetFirstUser(&boss);
	dial.SetSecondUser(&vassal);

	boss.Send("We have a problem!");
	vassal.Send("Don't worry! I'll fix it!");
	return 0;
}
