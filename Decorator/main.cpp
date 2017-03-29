#include "stdafx.h"

template <class T>
void DrawWithSepia(T && fn)
{
	fn();
}

class CPicture
{
public:
	void Draw() const {};
};

class CSepiaPicture
{
public:
	CSepiaPicture(std::unique_ptr<CPicture> picture)
		:m_pPicture(std::move(picture))
	{}

	void Draw() const
	{
		DrawWithSepia([&]() {
			m_pPicture->Draw();
		});
	}

private:
	std::unique_ptr<CPicture> m_pPicture;
};

int main()
{
	return 0;
}
