/** @file
	@brief Header

	@date 2011

	@author
	Ryan Pavlik
	<rpavlik@iastate.edu> and <abiryan@ryand.net>
	http://academic.cleardefinition.com/
	Iowa State University Virtual Reality Applications Center
	Human-Computer Interaction Graduate Program
*/

#pragma once
#ifndef INCLUDED_HAPIHapticsDeviceErrorCode_h_GUID_eb3f5700_ef39_4342_8a7b_a2ce7e3a0836
#define INCLUDED_HAPIHapticsDeviceErrorCode_h_GUID_eb3f5700_ef39_4342_8a7b_a2ce7e3a0836

// Internal Includes
// - none

// Library/third-party includes
#include <HAPI/HAPIHapticsDevice.h>
#include <luabind/luabind.hpp>

// Standard includes
// - none

namespace luabind {
	template<>
	struct default_converter<HAPI::HAPIHapticsDevice::ErrorCode>
			: native_converter_base<HAPI::HAPIHapticsDevice::ErrorCode> {
		void to(lua_State* L, HAPI::HAPIHapticsDevice::ErrorCode const& x) {
			switch (x) {
				case HAPI::HAPIHapticsDevice::SUCCESS:
					object(L, true).push(L);
					break;
				case HAPI::HAPIHapticsDevice::NOT_INITIALIZED:
					throw std::runtime_error("HAPIHapticsDevice::NOT_INITIALIZED");
					break;
				case HAPI::HAPIHapticsDevice::NOT_ENABLED:
					throw std::runtime_error("HAPIHapticsDevice::NOT_ENABLED");
					break;
				case HAPI::HAPIHapticsDevice::FAIL:
					throw std::runtime_error("HAPIHapticsDevice::FAIL");
					break;
			}
		}
	};
}
#endif // INCLUDED_HAPIHapticsDeviceErrorCode_h_GUID_eb3f5700_ef39_4342_8a7b_a2ce7e3a0836
