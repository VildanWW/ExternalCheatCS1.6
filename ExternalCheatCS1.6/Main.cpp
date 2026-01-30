#include <Windows.h>
#include <vector>
#include <memory>
#include "Memory.h"
#include "Bhop.h"
#include "Esp.h"
#include "IBaseFeature.h"
#include <thread>

namespace EF = ExternalCheat::Features;
namespace EC = ExternalCheat::Core;

int main() {
	if (!EC::AttachToProcess()) return 0;

	EC::clientBase = EC::FindModuleAddress(EC::procId, L"client.dll");
	EC::hwBase = EC::FindModuleAddress(EC::procId, L"hw.dll");

	std::vector<std::unique_ptr<EF::IBaseFeature>> feature;

	feature.push_back(std::make_unique<EF::Bhop>());
	feature.push_back(std::make_unique<EF::Esp>());

	for (auto& f : feature) {
		if (f->getBackGround()) {
			auto rawPtr = f.get();
			std::thread([rawPtr]() {
				while (true) {
					if (rawPtr->getEnabled()) {
						rawPtr->UpDate();
					}
				}
			}).detach();
		}
	}

	while (true) {
		ExternalCheat::Update();
		for (auto& f : feature) {
			if (GetAsyncKeyState(f->getBindKey()) & 1) {
				f->setEnabled(!f->getEnabled());

				if (!f->getEnabled() && !f->getBackGround()) {
					f->UpDate();
				}
			}

			if (f->getEnabled() && !f->getBackGround()) {
				f->UpDate();
			}
		}
		Sleep(1);
	}

	return 0;
}