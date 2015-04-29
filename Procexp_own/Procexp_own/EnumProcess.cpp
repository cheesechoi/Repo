
#include "stdafx.h"
#include "EnumProcess.h"

void _AboutProcess::PrintProcessNameAndID(DWORD _pid)
{
	TCHAR szProcName[MAX_PATH] = TEXT("<unknown>");
		HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
		PROCESS_VM_READ,
		FALSE, _pid);

	if (NULL != hProcess)
	{
		HMODULE hMod;
		DWORD cbNeeded;

		if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeeded))
		{
			GetModuleBaseName(hProcess, hMod, szProcName,
				sizeof(szProcName) / sizeof(TCHAR));
		}
		_tprintf(TEXT("%s	(PID:%u)\n"), szProcName, _pid);
		CloseHandle(hProcess);
	}
}

