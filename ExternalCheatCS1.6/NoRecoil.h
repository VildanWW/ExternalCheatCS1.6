#pragma once
#include "IBaseFeature.h"
#include "Offsets.h"
#include "Memory.h"
#include <thread>

namespace ExternalCheat {
	namespace Features {
		class NoRecoil : public IBaseFeature {
		private:
			float prevPunchZ = 0.0f;
			float recoilFactor = 1.2f;
		public:
			NoRecoil();

			void UpDate() override;
			void MenuRender() override;

			~NoRecoil() override = default;
		};
	}
}