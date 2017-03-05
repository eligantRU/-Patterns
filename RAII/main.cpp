#include "stdafx.h"

class CFile
{
public:
	CFile(const CFile &) = delete;
	CFile & operator=(const CFile &) = delete;

	CFile(const char * filename)
		:m_file_handle(std::fopen(filename, "w+"))
	{
		if (!m_file_handle)
		{
			throw std::exception("file open failure");
		}
	}

	~CFile()
	{
		if (std::fclose(m_file_handle) != 0)
		{
			// It is very bad
		}
	}

	void Write(const char * str)
	{
		if (std::fputs(str, m_file_handle) == EOF)
		{
			throw std::exception("file write failure");
		}
	}

private:
	std::FILE * m_file_handle;
};

int main()
{
	CFile logfile("logfile.txt");
	logfile.Write("Lorem ipsum dolor sit amet");

	return 0;
}
