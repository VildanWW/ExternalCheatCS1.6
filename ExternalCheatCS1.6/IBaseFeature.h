#pragma once

namespace ExternalCheat {
	namespace Features {
		class IBaseFeature {
		public:
			virtual void UpDate() = 0;
			virtual void MenuRender() = 0;

			bool enabled = false;
			int bindKey;

			virtual ~IBaseFeature() = default;
		};
	}
}