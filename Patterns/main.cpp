#include "stdafx.h"

#include "Singleton.h"

int main()
{
	{
		auto & instance = CSingleton::GetInstance();
		instance.SetOwnerName("Nick");
	}
	{
		auto & instance = CSingleton::GetInstance();
		std::cout << instance.GetOwnerName() << std::endl;
	}
	return 0;
}
