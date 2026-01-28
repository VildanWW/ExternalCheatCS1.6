#include "Memory.h"
#include <TlHelp32.h>

uintptr_t ExternalCheat::Core::GetModuleBaseAddress(DWORD procId, const wchar_t* moduleName) {
	uintptr_t moduleBaseAddr = 0;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);

	if (hSnap != INVALID_HANDLE_VALUE) {
		MODULEENTRY32W moduleEntry;

		moduleEntry.dwSize = sizeof(moduleEntry);

		if (Module32FirstW(hSnap, &moduleEntry)) {
			do {
				if (!_wcsicmp(moduleEntry.szModule, moduleName)) {
					moduleBaseAddr = (uintptr_t)moduleEntry.modBaseAddr;
					break;
				}
			} while (Module32NextW(hSnap, &moduleEntry));
		}
	}

	CloseHandle(hSnap);
	return moduleBaseAddr;
}
