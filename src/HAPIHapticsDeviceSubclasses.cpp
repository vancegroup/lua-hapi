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
#include "HAPIHapticsDeviceSubclasses.h"
#include "BindingFwd.h"

// Library/third-party includes
#include <luabind/class.hpp>
#include <luabind/out_value_policy.hpp>

#include <HAPI/AnyHapticsDevice.h>
#include <HAPI/EntactHapticsDevice.h>
#include <HAPI/FalconHapticsDevice.h>
#include <HAPI/ForceDimensionHapticsDevice.h>
#include <HAPI/HaptikHapticsDevice.h>
#include <HAPI/HaptionHapticsDevice.h>
#include <HAPI/MLHIHapticsDevice.h>
#include <HAPI/NiFalconHapticsDevice.h>
#include <HAPI/PhantomHapticsDevice.h>
#include <HAPI/QuanserHapticsDevice.h>
#include <HAPI/SimballHapticsDevice.h>

// Standard includes
// - none

template<typename T>
struct HAPIHapticsDeviceSubclass : luabind::class_<T, HAPI::HAPIHapticsDevice> {
	HAPIHapticsDeviceSubclass(const char * name)
		: luabind::class_<T, HAPI::HAPIHapticsDevice>(name)
	{}
};

template<> luabind::scope getLuaBinding<HAPI::AnyHapticsDevice>() {
	using namespace luabind;

	return
	    HAPIHapticsDeviceSubclass<HAPI::AnyHapticsDevice>("AnyHapticsDevice")
	    .def(constructor<>());
}

template<> luabind::scope getLuaBinding<HAPI::EntactHapticsDevice>() {
	using namespace luabind;
#ifdef HAVE_ENTACTAPI
	return
	    HAPIHapticsDeviceSubclass<HAPI::EntactHapticsDevice>("EntactHapticsDevice")
	    .def(constructor<>())
	    .def(constructor<int>())
	    .def("getDeviceId", &HAPI::EntactHapticsDevice::getDeviceId)
	    .def("getSerialNumber", &HAPI::EntactHapticsDevice::getSerialNumber)
	    .def("needsCalibration", &HAPI::EntactHapticsDevice::needsCalibration)
	    .def("calibrateDevice", &HAPI::EntactHapticsDevice::calibrateDevice)
	    .scope
	    [
	        def("getNumberConnectedEntactDevices", &HAPI::EntactHapticsDevice::getNumberConnectedEntactDevices)
	    ]
	    ;
#else
	return scope();
#endif
}

template<> luabind::scope getLuaBinding<HAPI::FalconHapticsDevice>() {
	using namespace luabind;
#ifdef FALCONAPI
	return
	    HAPIHapticsDeviceSubclass<HAPI::FalconHapticsDevice>("FalconHapticsDevice")
	    .def(constructor<>())
	    .def(constructor<int>())
	    .def(constructor<std::string>())
	    .def("getDeviceName", &HAPI::FalconHapticsDevice::getDeviceName)
	    .def("getDeviceModel", &HAPI::FalconHapticsDevice::getDeviceModel)
	    .def("getWorkspaceDimensions", &HAPI::FalconHapticsDevice::getWorkspaceDimensions, pure_out_value(_1) + pure_out_value(_2))
	    ;
#else
	return scope();
#endif
}

#ifdef HAVE_DHDAPI
namespace {
	void waitForReset0(HAPI::ForceDimensionHapticsDevice & hd) {
		hd.reset();
	}
}
#endif

template<> luabind::scope getLuaBinding<HAPI::ForceDimensionHapticsDevice>() {
	using namespace luabind;

#ifdef HAVE_DHDAPI
	return
	    HAPIHapticsDeviceSubclass<HAPI::ForceDimensionHapticsDevice>("ForceDimensionHapticsDevice")
	    .def(constructor<>())
	    .def("getDeviceId", &HAPI::ForceDimensionHapticsDevice::getDeviceId)
	    .def("getDeviceType", &HAPI::ForceDimensionHapticsDevice::getDeviceType)
	    .def("reset", &HAPI::ForceDimensionHapticsDevice::reset)
	    .def("waitForReset", &HAPI::ForceDimensionHapticsDevice::waitForReset)
	    .def("waitForReset", &waitForReset0)
	    .def("useGravityCompensation", &HAPI::ForceDimensionHapticsDevice::useGravityCompensation)
	    .def("setEffectorMass", &HAPI::ForceDimensionHapticsDevice::setEffectorMass)
	    .def("useBrakes", &HAPI::ForceDimensionHapticsDevice::useBrakes)
	    .enum_("DEVICE_TYPE")
	    [
	        value("DHD_DEVICE_3DOF", DHD_DEVICE_3DOF)
	        , value("DHD_DEVICE_6DOF", DHD_DEVICE_6DOF)
	        , value("DHD_DEVICE_OMEGA", DHD_DEVICE_OMEGA)
	        , value("DHD_DEVICE_OMEGA3", DHD_DEVICE_OMEGA3)
	        , value("DHD_DEVICE_OMEGA33", DHD_DEVICE_OMEGA33)
	        , value("DHD_DEVICE_OMEGA331", DHD_DEVICE_OMEGA331)
	        , value("DHD_DEVICE_CONTROLLER", DHD_DEVICE_CONTROLLER)
	        , value("DHD_DEVICE_SIMULATOR", DHD_DEVICE_SIMULATOR)
	        , value("DHD_DEVICE_CUSTOM", DHD_DEVICE_CUSTOM)
	    ]
	    ;
#else
	return scope();
#endif
}
template<> luabind::scope getLuaBinding<HAPI::HaptionHapticsDevice>() {
	using namespace luabind;
#ifdef HAVE_VIRTUOSEAPI
	return
	    HAPIHapticsDeviceSubclass<HAPI::HaptionHapticsDevice>("HaptionHapticsDevice")
	    .def(constructor<>())
	    .def(constructor<std::string const&>())
	    .def("getIpAddress", &HAPI::HaptionHapticsDevice::getIpAddress)
	    ;
#else
	return scope();
#endif
}

template<> luabind::scope getLuaBinding<HAPI::PhantomHapticsDevice>() {
	using namespace luabind;
#ifdef HAVE_OPENHAPTICS
	return
	    HAPIHapticsDeviceSubclass<HAPI::PhantomHapticsDevice>("PhantomHapticsDevice")
	    .def(constructor<>())
	    .def(constructor<std::string>())
	    .def("getDeviceName", &HAPI::PhantomHapticsDevice::getDeviceName)
	    .def("getDeviceFirmwareVersion", &HAPI::PhantomHapticsDevice::getDeviceFirmwareVersion)
	    .def("getHDAPIVersion", &HAPI::PhantomHapticsDevice::getHDAPIVersion)
	    .def("getDeviceModelType", &HAPI::PhantomHapticsDevice::getDeviceModelType)
	    .def("getDeviceDriverVersion", &HAPI::PhantomHapticsDevice::getDeviceDriverVersion)
	    ;
#else
	return scope();
#endif
}
