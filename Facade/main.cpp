#include "stdafx.h"

typedef uint8_t byte; // std::byte (since C++17)

namespace
{

const size_t BOOT_ADDRESS = 42;

const size_t BOOT_SECTOR = 24;

}

class CCPU
{
public:
	void Freeze() {};
	void Jump(size_t address) {};
	void Execute() {};
};

class CRAM
{
public:
	void Load(size_t address, byte data) {};
};

class CHDD
{
public:
	byte Read(size_t address) { return byte(); };
};

class CPC
{
public:
	CPC() = default;

	void Start()
	{
		m_cpu.Freeze();
		m_ram.Load(BOOT_ADDRESS,
		           m_hdd.Read(BOOT_SECTOR));
		m_cpu.Jump(BOOT_ADDRESS);
		m_cpu.Execute();
	}

private:
	CCPU m_cpu;
	CRAM m_ram;
	CHDD m_hdd;
};

int main()
{
	CPC computer;
	computer.Start();
	return 0;
}
