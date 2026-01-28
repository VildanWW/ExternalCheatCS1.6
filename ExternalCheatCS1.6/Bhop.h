#pragma once
#include "IBaseFeature.h"
#include "Offsets.h"
#include "Memory.h"
namespace ExternalCheat {
	namespace Features {
        class Bhop : public IBaseFeature {
        private:
            DWORD jump = 0;
            DWORD air = 0;
        public:
            Bhop() {
                jump = Core::clientBase + Offsets::responseJump;
                air = Core::clientBase + Offsets::flagJump;
            }

            void UpDate() override;
            void MenuRender() override;
        };
	}
}