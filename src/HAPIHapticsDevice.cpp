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
#include "BindingFwd.h"
#include "HAPIHapticsDeviceSubclasses.h"

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

	void addShape1(HAPI::HAPIHapticsDevice & hd, HAPI::HAPIHapticShape * a) {
		hd.addShape(a);
	}

	void removeShape1(HAPI::HAPIHapticsDevice & hd, HAPI::HAPIHapticShape * a) {
		hd.removeShape(a);
	}

	void clearShapes0(HAPI::HAPIHapticsDevice & hd) {
		hd.clearShapes();
	}

	void addEffect1(HAPI::HAPIHapticsDevice & hd, HAPI::HAPIForceEffect * a) {
		hd.addEffect(a);
	}

	void removeEffect1(HAPI::HAPIHapticsDevice & hd, HAPI::HAPIForceEffect * a) {
		hd.removeEffect(a);
	}

	void clearEffects0(HAPI::HAPIHapticsDevice & hd) {
		hd.clearEffects();
	}
}

template<> luabind::scope getLuaBinding<HAPI::HAPIHapticsDevice>() {
	using namespace luabind;

	return
	    class_<HAPI::HAPIHapticsDevice>("HAPIHapticsDevice")
	    .enum_("ErrorCode")
	    [
	        value("SUCCESS", HAPI::HAPIHapticsDevice::SUCCESS),
	        value("NOT_INITIALIZED", HAPI::HAPIHapticsDevice::NOT_INITIALIZED),
	        value("NOT_ENABLED", HAPI::HAPIHapticsDevice::NOT_ENABLED),
	        value("FAIL", HAPI::HAPIHapticsDevice::FAIL)
	    ]
	    .def("initDevice", &HAPI::HAPIHapticsDevice::initDevice)
	    .def("initDevice", &initDevice0)

	    .def("enableDevice", &HAPI::HAPIHapticsDevice::enableDevice)

	    .def("disableDevice", &HAPI::HAPIHapticsDevice::disableDevice)

	    .def("releaseDevice", &HAPI::HAPIHapticsDevice::releaseDevice)

	    .def("setHapticsRenderer", &HAPI::HAPIHapticsDevice::setHapticsRenderer)
	    .def("setHapticsRenderer", &setHapticsRenderer1)

	    .def("addShape", &HAPI::HAPIHapticsDevice::addShape)
	    .def("addShape", &addShape1)

	    .def("removeShape", &HAPI::HAPIHapticsDevice::removeShape)
	    .def("removeShape", &removeShape1)

	    .def("clearShapes", &HAPI::HAPIHapticsDevice::clearShapes)
	    .def("clearShapes", &clearShapes0)


	    .def("addEffect", &HAPI::HAPIHapticsDevice::addEffect)
	    .def("addEffect", &addEffect1)

	    .def("removeEffect", &HAPI::HAPIHapticsDevice::removeEffect)
	    .def("removeEffect", &removeEffect1)

	    .def("clearEffects", &HAPI::HAPIHapticsDevice::clearEffects)
	    .def("clearEffects", &clearEffects0)

	    .def("getButtonStatus", &getButtonStatus0)
	    .def("getButtonStatus", &getButtonStatus1)

	    .def("getPosition", &HAPI::HAPIHapticsDevice::getPosition)
	    .def("getLastPosition", &HAPI::HAPIHapticsDevice::getLastPosition)

	    .def("getLastErrorMsg", &HAPI::HAPIHapticsDevice::getLastErrorMsg)

	    .def("transferObjects", &HAPI::HAPIHapticsDevice::transferObjects)

	    , getLuaBinding<HAPI::AnyHapticsDevice>()
	    , getLuaBinding<HAPI::EntactHapticsDevice>()
	    , getLuaBinding<HAPI::FalconHapticsDevice>()
	    , getLuaBinding<HAPI::ForceDimensionHapticsDevice>()
	    , getLuaBinding<HAPI::HaptionHapticsDevice>()
	    , getLuaBinding<HAPI::PhantomHapticsDevice>()
	    ;
}
