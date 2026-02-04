#include "NoRecoil.h"

ExternalCheat::Features::NoRecoil::NoRecoil() : IBaseFeature (false, true) {}

void ExternalCheat::Features::NoRecoil::UpDate() {
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
		float currentPunch;
		ReadProcessMemory(Core::hProcess, (LPCVOID)(Core::hwBase + Offsets::punch), &currentPunch, 4, NULL);
		float deltaZ = currentPunch - prevPunchZ;

		if (deltaZ < -0.01) {
			float currentPitch;
			ReadProcessMemory(Core::hProcess, (LPCVOID)(Core::hwBase + Offsets::viewAngles), &currentPitch, 4, NULL);
		
			float newPitch = currentPitch - (deltaZ * recoilFactor);

			WriteProcessMemory(Core::hProcess, (LPVOID)(Core::hwBase + Offsets::viewAngles), &newPitch, 4, NULL);
		}

		prevPunchZ = currentPunch;
	} 

	else {
		prevPunchZ = 0.0f;
	}
}

void ExternalCheat::Features::NoRecoil::MenuRender() {}
