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
            Bhop() : jump(Core::clientBase + Offsets::responseJump), air(Core::clientBase + Offsets::flagJump) {
                bindKey = 'J';
            }

            void UpDate() override;
            void MenuRender() override;

            ~Bhop() override = default;
        };
	}
}