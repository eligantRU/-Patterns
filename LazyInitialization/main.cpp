#include "stdafx.h"

namespace
{

const size_t DEFAULT_CIRCLE_PRECISION = 100;

}

class CCircle
{
public:
	CCircle() = delete;
	CCircle(size_t precision)
		:m_precision(precision)
	{

	}

	void Draw() const
	{
		std::cout << "Drawing" << std::endl;
		if (!m_isDirty)
		{
			Calculate();
			m_isDirty = true;
		}
	}

private:
	void Calculate() const // expensive operation
	{
		std::cout << "Calculating" << std::endl;
	}

	mutable std::vector<std::pair<float, float>> m_points;
	size_t m_precision = DEFAULT_CIRCLE_PRECISION;
	mutable bool m_isDirty = false;
};

int main()
{
	CCircle circle(1000);
	circle.Draw();
	circle.Draw();
	circle.Draw();
	return 0;
}
