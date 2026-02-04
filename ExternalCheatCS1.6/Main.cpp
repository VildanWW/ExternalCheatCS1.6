#include <Windows.h>
#include <vector>
#include <thread>
#include <memory>
#include "Memory.h"
#include "Bhop.h"
#include "Esp.h"
#include "Aim.h"
#include "IBaseFeature.h"
#include "Menu.h"
#include "NoRecoil.h"
#include "Settings.h"
#include <typeinfo>

namespace EF = ExternalCheat::Features;
namespace EC = ExternalCheat::Core;

int main() {
	if (!EC::AttachToProcess()) return 0;

	EC::clientBase = EC::FindModuleAddress(EC::procId, L"client.dll");
	EC::hwBase = EC::FindModuleAddress(EC::procId, L"hw.dll");

	feature.push_back(std::make_unique<EF::Bhop>());
	feature.push_back(std::make_unique<EF::Esp>());
	feature.push_back(std::make_unique<EF::Aim>());
	feature.push_back(std::make_unique<EF::NoRecoil>());

	for (auto& f : feature) {
		if (f->getBackGround()) {
			auto rawPtr = f.get();
			std::thread([rawPtr]() {
				while (true) {
					if (rawPtr->getEnabled()) {
						rawPtr->UpDate();
					}
					if (typeid(*rawPtr) != typeid(EF::Bhop)) {
						Sleep(1);
					}
				}
			}).detach();
		}
	}
	
	std::thread(Menu::MenuThread).detach();

	while (!Settings::bShouldQuit) {
		ExternalCheat::Update();
		for (auto& f : feature) {
			if (!f->getBackGround()) {
				f->UpDate();
			}
		}
		Sleep(1);
	}

	return 0;
}