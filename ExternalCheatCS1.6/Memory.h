#pragma once
#include <Windows.h>

namespace ExternalCheat {
	namespace OffSets {
		const uintptr_t positionPlayers = 0x2F3DB44;
		const uintptr_t statePlayers = 0x3EF8CC;
		const uintptr_t teamStatePlayers = 0x2143DC;
		const uintptr_t viewMatrix = 0x73BB90;
		const uintptr_t viewAngles = 0x2DC2B20;
	}

	namespace Core {
		uintptr_t GetModuleBaseAddress(DWORD procId, const wchar_t* modName);
	}
}