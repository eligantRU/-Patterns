#include "stdafx.h"

#include "Factory.h"

int main()
{
	CJuiceFactory factory;
	auto juice = factory.GetAppleJuice();
	return 0;
}
