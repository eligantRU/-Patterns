#include "stdafx.h"

class ISolver
{
public:
	virtual ~ISolver() = default;

	virtual std::tuple<float, float> Solve2(float a, float b, float c) const = 0;
};

class CSolver1
	:public ISolver
{
public:
	std::tuple<float, float> Solve2(float a, float b, float c) const override
	{
		std::cout << "Solver1" << std::endl;
		return { 0.f, 0.f };
	}
};

class CSolver2
	:public ISolver
{
public:
	std::tuple<float, float> Solve2(float a, float b, float c) const override
	{
		std::cout << "Solver2" << std::endl;
		return { 0.f, 0.f };
	}
};

class CServiceLocator
{
public:
	CServiceLocator(const CServiceLocator &) = delete;
	CServiceLocator & operator=(const CServiceLocator &) = delete;

	static CServiceLocator & GetInstance()
	{
		static CServiceLocator instance;
		return instance;
	}

	void SetSolver(std::shared_ptr<ISolver> solver)
	{
		m_solver = solver;
	}

	auto GetSolver()
	{
		return m_solver;
	}

private:
	CServiceLocator() = default;
	std::shared_ptr<ISolver> m_solver = nullptr;
};

int main()
{
	auto solver1 = std::make_shared<CSolver1>();
	auto solver2 = std::make_shared<CSolver2>();

	auto & instance = CServiceLocator::GetInstance();
	{
		instance.SetSolver(solver1);
		auto bla = instance.GetSolver()->Solve2(0, 0, 0);
	}
	{
		instance.SetSolver(solver2);
		auto bla = instance.GetSolver()->Solve2(0, 0, 0);
	}
	return 0;
}
