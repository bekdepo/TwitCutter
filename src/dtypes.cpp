#include "dtypes.h"

CLSID::CLSID()
{
	Data1 = { };
	Data2 = { };
	Data3 = { };
	for (int i = 0; i < 8; ++i)
	{
		Data4[i] = { };
	}
}

CLSID::~CLSID()
{
}

FILETIME::FILETIME()
{
	dwLowDateTime = { };
	dwHighDateTime = { };
}

FILETIME::~FILETIME()
{
}
