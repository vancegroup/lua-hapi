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
#define FORWARDER_IMPL_0(_RTYPE, _RET, _METHOD) \
	_RTYPE _METHOD ## 0 (HAPI::HAPIHapticsDevice & hd) { \
		_RET hd. _METHOD(); \
	}
#define VOID_FORWARDER0(_METHOD) FORWARDER_IMPL_0(void, , _METHOD)
#define FORWARDER0(_RTYPE, _METHOD) FORWARDER_IMPL_0(_RTYPE, return, _METHOD)

#define FORWARDER_IMPL_1(_RTYPE, _RET, _METHOD, _T1) \
	_RTYPE _METHOD ## 1 (HAPI::HAPIHapticsDevice & hd, _T1 a1) { \
		_RET hd. _METHOD(a1); \
	}
#define VOID_FORWARDER1(_METHOD, _T1) FORWARDER_IMPL_1(void, , _METHOD, _T1)
#define FORWARDER1(_RTYPE, _METHOD, _T1) FORWARDER_IMPL_1(_RTYPE, return, _METHOD, _T1)

	FORWARDER0(HAPI::HAPIHapticsDevice::ErrorCode, initDevice)

	VOID_FORWARDER1(setHapticsRenderer, HAPI::HAPIHapticsRenderer *)

	FORWARDER0(HAPI::HAPIHapticsRenderer *, getHapticsRenderer)

	FORWARDER0(HAPI::HAPIInt32, getButtonStatus)
	FORWARDER1(bool, getButtonStatus, unsigned int)

	FORWARDER0(HAPI::HAPIInt32, getLastButtonStatus)
	FORWARDER1(bool, getLastButtonStatus, unsigned int)


	VOID_FORWARDER1(addShape, HAPI::HAPIHapticShape *)
	VOID_FORWARDER1(removeShape, HAPI::HAPIHapticShape *)
	VOID_FORWARDER0(clearShapes)

	VOID_FORWARDER1(addEffect, HAPI::HAPIForceEffect *)
	VOID_FORWARDER1(removeEffect, HAPI::HAPIForceEffect *)
	VOID_FORWARDER0(clearEffects)
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

	    .enum_("DeviceState")
	    [
	        value("UNINITIALIZED", HAPI::HAPIHapticsDevice::UNINITIALIZED),
	        value("INITIALIZED", HAPI::HAPIHapticsDevice::INITIALIZED),
	        value("ENABLED", HAPI::HAPIHapticsDevice::ENABLED)
	    ]

	    .scope
	    [
	        class_<HAPI::HAPIHapticsDevice::DeviceValues>("DeviceValues")
	        .def(constructor<>())
	        .def_readwrite("force", &HAPI::HAPIHapticsDevice::DeviceValues::force)
	        .def_readwrite("torque", &HAPI::HAPIHapticsDevice::DeviceValues::torque)
	        .def_readwrite("position", &HAPI::HAPIHapticsDevice::DeviceValues::position)
	        .def_readwrite("velocity", &HAPI::HAPIHapticsDevice::DeviceValues::velocity)
	        //.def_readwrite("orientation", &HAPI::HAPIHapticsDevice::DeviceValues::orientation) /// @todo needs binding for Rotation
	        .def_readwrite("button_status", &HAPI::HAPIHapticsDevice::DeviceValues::button_status)
	    ]

	    .def("initDevice", &HAPI::HAPIHapticsDevice::initDevice)
	    .def("initDevice", &initDevice0)

	    .def("enableDevice", &HAPI::HAPIHapticsDevice::enableDevice)

	    .def("disableDevice", &HAPI::HAPIHapticsDevice::disableDevice)

	    .def("releaseDevice", &HAPI::HAPIHapticsDevice::releaseDevice)

	    .def("getLastErrorMsg", &HAPI::HAPIHapticsDevice::getLastErrorMsg)

	    .def("transferObjects", &HAPI::HAPIHapticsDevice::transferObjects)

	    .def("getDeviceState", &HAPI::HAPIHapticsDevice::getDeviceState)

	    .def("getMaxStiffness", &HAPI::HAPIHapticsDevice::getMaxStiffness)

	    .def("nrLayers", &HAPI::HAPIHapticsDevice::nrLayers)
	    .def("getHapticsRate", &HAPI::HAPIHapticsDevice::getHapticsRate)

	    .def("setHapticsRenderer", &HAPI::HAPIHapticsDevice::setHapticsRenderer)
	    .def("setHapticsRenderer", &setHapticsRenderer1)

	    .def("getHapticsRenderer", &HAPI::HAPIHapticsDevice::getHapticsRenderer)
	    .def("getHapticsRenderer", &getHapticsRenderer0)

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

	    .def("getLastButtonStatus", &getLastButtonStatus0)
	    .def("getLastButtonStatus", &getLastButtonStatus1)

#define DEF_STATE_ATTRIBUTE(_ATTR) \
	    .def("get" #_ATTR, &HAPI::HAPIHapticsDevice::get ## _ATTR) \
	    .def("getLast" #_ATTR, &HAPI::HAPIHapticsDevice::getLast ## _ATTR)

	    DEF_STATE_ATTRIBUTE(DeviceValues)
	    DEF_STATE_ATTRIBUTE(RawDeviceValues)

	    DEF_STATE_ATTRIBUTE(Position)
	    DEF_STATE_ATTRIBUTE(RawPosition)

	    DEF_STATE_ATTRIBUTE(Orientation)
	    DEF_STATE_ATTRIBUTE(RawOrientation)

	    DEF_STATE_ATTRIBUTE(Velocity)
	    DEF_STATE_ATTRIBUTE(RawVelocity)

	    DEF_STATE_ATTRIBUTE(Force)
	    DEF_STATE_ATTRIBUTE(RawForce)

	    DEF_STATE_ATTRIBUTE(Torque)
	    DEF_STATE_ATTRIBUTE(RawTorque)

#undef DEF_STATE_ATTRIBUTE

	    , getLuaBinding<HAPI::AnyHapticsDevice>()
	    , getLuaBinding<HAPI::EntactHapticsDevice>()
	    , getLuaBinding<HAPI::FalconHapticsDevice>()
	    , getLuaBinding<HAPI::ForceDimensionHapticsDevice>()
	    , getLuaBinding<HAPI::HaptikHapticsDevice>()
	    , getLuaBinding<HAPI::HaptionHapticsDevice>()
	    , getLuaBinding<HAPI::MLHIHapticsDevice>()
	    , getLuaBinding<HAPI::NiFalconHapticsDevice>()
	    , getLuaBinding<HAPI::PhantomHapticsDevice>()
	    , getLuaBinding<HAPI::QuanserHapticsDevice>()
	    , getLuaBinding<HAPI::SimballHapticsDevice>()
	    ;
}
