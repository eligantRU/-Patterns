#include "stdafx.h"

#include "Builder.h"

int main()
{
	CBuilder builder;
	auto juiceBox = builder.BuildJuiceBox(IJuice::JuiceType::Apple);
	return 0;
}
