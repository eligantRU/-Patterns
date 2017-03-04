#include "stdafx.h"

#include "Builder.h"
#include "Director.h"

int main()
{
	{
		CJuiceBoxDirector director;
		auto bananaJuiceBoxBuilder =
			std::make_shared<CBananaJuiceBoxBuilder>();
		auto appleJuiceBoxBuilder =
			std::make_shared<CAppleJuiceBoxBuilder>();

		director.SetBuilder(bananaJuiceBoxBuilder);
		director.ConstructJuiceBox();
		auto juiceBox1 = director.GetJuiceBox();

		director.SetBuilder(appleJuiceBoxBuilder);
		director.ConstructJuiceBox();
		auto juiceBox2 = director.GetJuiceBox();
	}

	return 0;
}
