#include "stdafx.h"

#include "Builder.h"
#include "Director.h"

int main()
{
	CEmailDirector director;
	auto yandexEmailBuilder =
		std::make_shared<CYandexEmailBuilder>();
	auto bingEmailBuilder =
		std::make_shared<CBingEmailBuilder>();

	director.SetBuilder(yandexEmailBuilder);
	director.ConstructEmail("ElIganT.Ru");
	std::cout << director.GetEmail() << std::endl;

	director.SetBuilder(bingEmailBuilder);
	director.ConstructEmail("ElIganT.Ru");
	std::cout << director.GetEmail() << std::endl;

	return 0;
}
