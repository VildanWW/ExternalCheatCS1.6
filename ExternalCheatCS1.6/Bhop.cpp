#include "Bhop.h"
#include "Memory.h"
#include <Windows.h>

void ExternalCheat::Features::Bhop::UpDate() {
	if (GetAsyncKeyState(VK_SPACE)) {
		int airState;

		ReadProcessMemory(Core::hProcess, (LPCVOID)air, &airState, 4, NULL);

		if (airState == 0) {
			int valueFive = 5;
			int valueFour = 4;

			WriteProcessMemory(Core::hProcess, (LPVOID)jump, &valueFive, 4, NULL);

			Sleep(10);

			WriteProcessMemory(Core::hProcess, (LPVOID)jump, &valueFour, 4, NULL);
		}
	}
}

void ExternalCheat::Features::Bhop::MenuRender()
{
}


