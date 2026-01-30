#pragma once
#include "IBaseFeature.h"
#include "Offsets.h"
#include "Memory.h"
namespace ExternalCheat {
	namespace Features {
        class Bhop : public IBaseFeature {
        private:
            DWORD jump;
            DWORD air;
        public:
            Bhop();

            void UpDate() override;
            void MenuRender() override;

            ~Bhop() override = default;
        };
	}
}