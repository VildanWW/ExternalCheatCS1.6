#pragma once

namespace ExternalCheat {
	namespace Features {
		class IBaseFeature {
		public:
			virtual void UpDate() = 0;
			virtual void MenuRender() = 0;
		};
	}
}