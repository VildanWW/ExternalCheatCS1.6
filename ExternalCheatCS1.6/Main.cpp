#include <Windows.h>
#include <vector>
#include <memory>
#include "Memory.h"
#include "Bhop.h"
#include "IBaseFeature.h"

namespace EF = ExternalCheat::Features;
namespace EC = ExternalCheat::Core;

int main() {
	if (!EC::AttachToProcess()) return 0;

	EC::clientBase = EC::FindModuleAddress(EC::procId, L"client.dll");
	EC::hwBase = EC::FindModuleAddress(EC::procId, L"hw.dll");

	std::vector<std::unique_ptr<EF::IBaseFeature>> feature;

	feature.push_back(std::make_unique<EF::Bhop>());

	while (true) {
		for (auto& f : feature) {
			if (GetAsyncKeyState(f->bindKey) & 1) {
				f->enabled = !f->enabled;
			}

			if (f->enabled) {
				f->UpDate();
			}
		}
		Sleep(0);
	}

	return 0;
}