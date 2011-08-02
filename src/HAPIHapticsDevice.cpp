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

template<> luabind::scope getLuaBinding<HAPI::HAPIHapticsDevice>() {
	using namespace luabind;

	return
	    class_<HAPI::HAPIHapticsDevice>("HAPIHapticsDevice")
	    .def("initDevice", &HAPI::HAPIHapticsDevice::initDevice)
	    .def("initDevice", (void (HAPI::HAPIHapticsDevice::*)())(&HAPI::HAPIHapticsDevice::initDevice))

	    .def("enableDevice", &HAPI::HAPIHapticsDevice::enableDevice)

	    .def("disableDevice", &HAPI::HAPIHapticsDevice::disableDevice)

	    .def("releaseDevice", &HAPI::HAPIHapticsDevice::releaseDevice)

	    .def("setHapticsRenderer", &HAPI::HAPIHapticsDevice::setHapticsRenderer)
	    .def("setHapticsRenderer", (void (HAPI::HAPIHapticsDevice::*)(HAPI::HAPIHapticsRenderer *))(&HAPI::HAPIHapticsDevice::setHapticsRenderer))


	    .def("addShape", &HAPI::HAPIHapticsDevice::addShape)
	    .def("addShape", (void (HAPI::HAPIHapticsDevice::*)(HAPI::HAPIHapticShape *))(&HAPI::HAPIHapticsDevice::addShape))

	    .def("removeShape", &HAPI::HAPIHapticsDevice::removeShape)
	    .def("removeShape", (void (HAPI::HAPIHapticsDevice::*)(HAPI::HAPIHapticShape *))(&HAPI::HAPIHapticsDevice::removeShape))

	    .def("clearShapes", &HAPI::HAPIHapticsDevice::clearShapes)
	    .def("clearShapes", (void (HAPI::HAPIHapticsDevice::*)())(&HAPI::HAPIHapticsDevice::clearShapes))


	    .def("addEffect", &HAPI::HAPIHapticsDevice::addEffect)
	    .def("addEffect", (void (HAPI::HAPIHapticsDevice::*)(HAPI::HAPIForceEffect *))(&HAPI::HAPIHapticsDevice::addEffect))

	    .def("removeEffect", &HAPI::HAPIHapticsDevice::removeEffect)
	    .def("removeEffect", (void (HAPI::HAPIHapticsDevice::*)(HAPI::HAPIForceEffect *))(&HAPI::HAPIHapticsDevice::removeEffect))

	    .def("clearEffects", &HAPI::HAPIHapticsDevice::clearEffects)
	    .def("clearEffects", (void (HAPI::HAPIHapticsDevice::*)())(&HAPI::HAPIHapticsDevice::clearEffects))
	    ,
	    getLuaBinding<HAPI::AnyHapticsDevice>()
	    ;
}
