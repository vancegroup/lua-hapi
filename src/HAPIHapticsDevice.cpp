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

//          Copyright Iowa State University 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


// Internal Includes
#include "HAPIHapticsDevice.h"
//#include "HAPIHapticsDeviceErrorCode.h"

#include "AnyHapticsDevice.h"
#include "PhantomHapticsDevice.h"
#include "HaptionHapticsDevice.h"

// Library/third-party includes
#include <luabind/class.hpp>
#include <HAPI/HAPIHapticsDevice.h>

// Standard includes
// - none


namespace {
	HAPI::HAPIHapticsDevice::ErrorCode initDevice0(HAPI::HAPIHapticsDevice & hd) {
		return hd.initDevice();
	}
	void setHapticsRenderer1(HAPI::HAPIHapticsDevice & hd, HAPI::HAPIHapticsRenderer * r) {
		hd.setHapticsRenderer(r);
	}

	HAPI::HAPIInt32 getButtonStatus0(HAPI::HAPIHapticsDevice & hd) {
		return hd.getButtonStatus();
	}

	bool getButtonStatus1(HAPI::HAPIHapticsDevice & hd, unsigned int button_nr) {
		return hd.getButtonStatus(button_nr);
	}
}

template<> luabind::scope getLuaBinding<HAPI::HAPIHapticsDevice>() {
	using namespace luabind;

	return
	    class_<HAPI::HAPIHapticsDevice>("HAPIHapticsDevice")
	    .def("initDevice", &HAPI::HAPIHapticsDevice::initDevice)
	    .def("initDevice", &initDevice0)

	    .def("enableDevice", &HAPI::HAPIHapticsDevice::enableDevice)

	    .def("disableDevice", &HAPI::HAPIHapticsDevice::disableDevice)

	    .def("releaseDevice", &HAPI::HAPIHapticsDevice::releaseDevice)

	    .def("setHapticsRenderer", &HAPI::HAPIHapticsDevice::setHapticsRenderer)
	    .def("setHapticsRenderer", &setHapticsRenderer1)

	    .def("addShape", &HAPI::HAPIHapticsDevice::addShape)
	    .def("addShape", (void (HAPI::HAPIHapticsDevice::*)(HAPI::HAPIHapticShape *))&HAPI::HAPIHapticsDevice::addShape)

	    .def("removeShape", &HAPI::HAPIHapticsDevice::removeShape)
	    .def("removeShape", (void (HAPI::HAPIHapticsDevice::*)(HAPI::HAPIHapticShape *))&HAPI::HAPIHapticsDevice::removeShape)

	    .def("clearShapes", &HAPI::HAPIHapticsDevice::clearShapes)
	    .def("clearShapes", (void (HAPI::HAPIHapticsDevice::*)())&HAPI::HAPIHapticsDevice::clearShapes)


	    .def("addEffect", &HAPI::HAPIHapticsDevice::addEffect)
	    .def("addEffect", (void (HAPI::HAPIHapticsDevice::*)(HAPI::HAPIForceEffect *))&HAPI::HAPIHapticsDevice::addEffect)

	    .def("removeEffect", &HAPI::HAPIHapticsDevice::removeEffect)
	    .def("removeEffect", (void (HAPI::HAPIHapticsDevice::*)(HAPI::HAPIForceEffect *))&HAPI::HAPIHapticsDevice::removeEffect)

	    .def("clearEffects", &HAPI::HAPIHapticsDevice::clearEffects)
	    .def("clearEffects", (void (HAPI::HAPIHapticsDevice::*)())&HAPI::HAPIHapticsDevice::clearEffects)


	    .def("getButtonStatus", &getButtonStatus0)
	    .def("getButtonStatus", &getButtonStatus1)

	    .def("getPosition", &HAPI::HAPIHapticsDevice::getPosition)
	    .def("getLastPosition", &HAPI::HAPIHapticsDevice::getLastPosition)

	    .def("getLastErrorMsg", &HAPI::HAPIHapticsDevice::getLastErrorMsg)

	    ,getLuaBinding<HAPI::AnyHapticsDevice>()
		,getLuaBinding<HAPI::PhantomHapticsDevice>()
		,getLuaBinding<HAPI::HaptionHapticsDevice>()
	    ;
}
