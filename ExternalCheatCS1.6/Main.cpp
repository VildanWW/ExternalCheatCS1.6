#include <Windows.h>
#include <vector>
#include "Memory.h"
#include "Bhop.h"
#include "IBaseFeature.h"

namespace EF = ExternalCheat::Features;
namespace EC = ExternalCheat::Core;

int main() {
	if (!EC::AttachToProcess()) return 0;

	EC::clientBase = EC::FindModuleAddress(EC::procId, L"client.dll");
	EC::hwBase = EC::FindModuleAddress(EC::procId, L"hw.dll");

	std::vector<EF::IBaseFeature*> feature = { new EF::Bhop };

	while (true) {
		for (auto f : feature) {
			f->UpDate();
		}

		
	}

	return 0;
}