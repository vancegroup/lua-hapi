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

#include "AnyHapticsDevice.h"

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
	    .def("initDevice", &HAPI::HAPIHapticsDevice::initDevice)
	    .def("enableDevice", &HAPI::HAPIHapticsDevice::enableDevice)
	    .def("disableDevice", &HAPI::HAPIHapticsDevice::disableDevice)
	    .def("releaseDevice", &HAPI::HAPIHapticsDevice::releaseDevice)
	    .def("setHapticsRenderer", &HAPI::HAPIHapticsDevice::setHapticsRenderer)
	    //.def("setHapticsRenderer", tag_function<void (HAPI::HAPIHapticsDevice *, HAPI::HAPIHapticsRenderer *)>(boost::bind(&HAPI::HAPIHapticsDevice::setHapticsRenderer, _1, _2)))
	    .def("setHapticsRenderer", (void (HAPI::HAPIHapticsDevice::*)(HAPI::HAPIHapticsRenderer *))(&HAPI::HAPIHapticsDevice::setHapticsRenderer))
	    ,
	    bind<HAPI::AnyHapticsDevice>()
	    ;
}
