/**
	@file
	@brief Implementation

	@date 2011

	@author
	Ryan Pavlik
	<rpavlik@iastate.edu> and <abiryan@ryand.net>
	http://academic.cleardefinition.com/
	Iowa State University Virtual Reality Applications Center
	Human-Computer Interaction Graduate Program
*/

// Internal Includes
#include "HAPIHapticsDevice.h"
#include "HAPIHapticsDeviceErrorCode.h"

// Library/third-party includes
#include <luabind/class.hpp>
#include <luabind/tag_function.hpp>
#include <HAPI/HAPIHapticsDevice.h>

// Standard includes
// - none

template<> luabind::scope bind<HAPI::HAPIHapticsDevice>() {
	using namespace luabind;

	return
	    class_<HAPI::HAPIHapticsDevice>("HAPIHapticsDevice")
	    /*.enum_("ErrorCode")
	    [
	    	value("SUCCESS", HAPI::HAPIHapticsDevice::SUCCESS),
	    	value("NOT_INITIALIZED", HAPI::HAPIHapticsDevice::NOT_INITIALIZED),
	    	value("NOT_ENABLED", HAPI::HAPIHapticsDevice::NOT_ENABLED),
	    	value("FAIL", HAPI::HAPIHapticsDevice::FAIL)
	    ]*/
	    .def("initDevice", &HAPI::HAPIHapticsDevice::initDevice);
}
