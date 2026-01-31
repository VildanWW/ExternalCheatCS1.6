#pragma once
#include "IBaseFeature.h"

namespace ExternalCheat {
	namespace Features {
		class Aim : public IBaseFeature {
		private:
		public:
			Aim();

			void UpDate() override;
			void MenuRender() override;

			~Aim() override = default;
		};
	}
}