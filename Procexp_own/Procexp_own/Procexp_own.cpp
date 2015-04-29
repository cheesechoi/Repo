// Procexp_own.cpp : Defines the entry point for the console application.
//

#pragma comment(lib, "Psapi.lib")

#include "stdafx.h"
#include <Windows.h>
#include <Psapi.h>
#include "EnumProcess.h"


int _tmain(int argc, _TCHAR* argv[])
{
	DWORD _index = 0;
	DWORD aProcesses[1024], cbNeeded, cProcesses;
	_AboutProcess ap;

	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
	{
		return 1;
	}
	
	cProcesses = cbNeeded / sizeof(DWORD);

	
	for (; _index < cProcesses; _index++)
	{
		ap.PrintProcessNameAndID(aProcesses[_index]);
	}

	return 0;
}

