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
#include <HAPI/HapticMasterDevice.h>
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
	    .def(constructor<>())
	    .def("getActualHapticsDevice", &HAPI::AnyHapticsDevice::getActualHapticsDevice)
	    ;
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
	    .def("getWorkspaceDimensions", &HAPI::FalconHapticsDevice::getWorkspaceDimensions, pure_out_value(_2) + pure_out_value(_3))
	    ;
#else
	return scope();
#endif
}

#ifdef HAVE_DHDAPI
#define FORWARDING_OBJECT_TYPE HAPI::ForceDimensionHapticsDevice
#include "ForwardingMacros.h"
VOID_FORWARDER0(waitForReset)
#include "ForwardingMacrosUndef.h"
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

template<> luabind::scope getLuaBinding<HAPI::HapticMasterDevice>() {
	using namespace luabind;

#ifdef HAVE_HAPTIC_MASTER_API
	return
	    HAPIHapticsDeviceSubclass<HAPI::HapticMasterDevice>("HapticMasterDevice")
	    .def(constructor<>())
	    .def(constructor<std::string const&>())
	    .def("getDeviceHandle", &HAPI::HapticMasterDevice::getDeviceHandle)
	    .def("getName", &HAPI::HapticMasterDevice::getName)
	    ;
#else
	return scope();
#endif
}

template<> luabind::scope getLuaBinding<HAPI::HaptikHapticsDevice>() {
	using namespace luabind;

#ifdef HAVE_HAPTIK_LIBRARY
	return
	    HAPIHapticsDeviceSubclass<HAPI::HaptikHapticsDevice>("HaptikHapticsDevice")
	    .def(constructor<>())
	    .def("changeHaptikDevice", &HAPI::HaptikHapticsDevice::changeHaptikDevice)
	    .def("getHaptikIndex", &HAPI::HaptikHapticsDevice::getHaptikIndex)
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

template<> luabind::scope getLuaBinding<HAPI::MLHIHapticsDevice>() {
	using namespace luabind;

#ifdef HAVE_MLHI
	return
	    HAPIHapticsDeviceSubclass<HAPI::MLHIHapticsDevice>("MLHIHapticsDevice")
	    .def(constructor<>())
	    .def(constructor<std::string const&>())
	    .def("allowRotation", &HAPI::MLHIHapticsDevice::allowRotation)
	    ;
#else
	return scope();
#endif
}

template<> luabind::scope getLuaBinding<HAPI::NiFalconHapticsDevice>() {
	using namespace luabind;

#ifdef HAVE_NIFALCONAPI
	return
	    HAPIHapticsDeviceSubclass<HAPI::NiFalconHapticsDevice>("NiFalconHapticsDevice")
	    .def(constructor<>())
	    .def(constructor<unsigned int>())
	    .def("getDeviceIndex", &HAPI::NiFalconHapticsDevice::getDeviceIndex)
	    .def("setDeviceIndex", &HAPI::NiFalconHapticsDevice::setDeviceIndex)
	    ;
#else
	return scope();
#endif
}

#ifdef HAVE_OPENHAPTICS
namespace {
	/// wrapper for getMotorTemperatures that returns a table
	luabind::object getMotorTemperatures(lua_State * L, HAPI::PhantomHapticsDevice & hd) {
		using namespace luabind;
		object o = newtable(L);
		const std::vector<HAPI::HAPIFloat> & ret = hd.getMotorTemperatures();
		const int n = ret.size();
		for (int i = 0; i < n; ++i) {
			o[i + 1] = ret[i];
		}
		return o;
	}
}
#endif

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
	    .def("getDeviceVendor", &HAPI::PhantomHapticsDevice::getDeviceVendor)
	    .def("getDeviceSerialNumber", &HAPI::PhantomHapticsDevice::getDeviceSerialNumber)
	    .def("getMotorTemperatures", &getMotorTemperatures)
	    .def("getMaxWorkspaceDimensions", &HAPI::PhantomHapticsDevice::getMaxWorkspaceDimensions, pure_out_value(_2) + pure_out_value(_3))
	    .def("getUsableWorkspaceDimensions", &HAPI::PhantomHapticsDevice::getUsableWorkspaceDimensions, pure_out_value(_2) + pure_out_value(_3))
	    .def("getTabletopOffset", &HAPI::PhantomHapticsDevice::getTabletopOffset)
	    .def("getMaxForce", &HAPI::PhantomHapticsDevice::getMaxForce)
	    .def("getMaxContinuousForce", &HAPI::PhantomHapticsDevice::getMaxContinuousForce)
	    .def("getInputDOF", &HAPI::PhantomHapticsDevice::getInputDOF)
	    .def("getOutputDOF", &HAPI::PhantomHapticsDevice::getOutputDOF)
	    .def("getJointAngles", &HAPI::PhantomHapticsDevice::getJointAngles)
	    .def("getGimbalAngles", &HAPI::PhantomHapticsDevice::getGimbalAngles)
	    .def("needsCalibration", &HAPI::PhantomHapticsDevice::needsCalibration)
	    .def("calibrateDevice", &HAPI::PhantomHapticsDevice::calibrateDevice)
	    .def("hardwareForceDisabled", &HAPI::PhantomHapticsDevice::hardwareForceDisabled)
	    .def("inCalibrationMode", &HAPI::PhantomHapticsDevice::inCalibrationMode)
	    ;
#else
	return scope();
#endif
}

template<> luabind::scope getLuaBinding<HAPI::QuanserHapticsDevice>() {
	using namespace luabind;

#ifdef HAVE_QUARC
	return
	    HAPIHapticsDeviceSubclass<HAPI::QuanserHapticsDevice>("QuanserHapticsDevice")
	    .def(constructor<>())
	    .def(constructor<std::string const&>())
	    .def("getDeviceId", &HAPI::QuanserHapticsDevice::getDeviceId)
	    .def("getURI", &HAPI::QuanserHapticsDevice::getURI)
	    .def("schedule_calibration", &HAPI::QuanserHapticsDevice::schedule_calibration)
	    .def("send_calibration", &HAPI::QuanserHapticsDevice::send_calibration)
	    .def("do_calibration", &HAPI::QuanserHapticsDevice::do_calibration)
	    .def("enable_amplifiers", &HAPI::QuanserHapticsDevice::enable_amplifiers)
	    .def("enable_position_watchdog", &HAPI::QuanserHapticsDevice::enable_position_watchdog)
	    .def("set_damping_gains", &HAPI::QuanserHapticsDevice::set_damping_gains)
	    .def("set_stiffness_gains", &HAPI::QuanserHapticsDevice::set_stiffness_gains)
	    .def("set_stiffness_position_setpoints", &HAPI::QuanserHapticsDevice::set_stiffness_position_setpoints)
	    .def("is_fatal_error", &HAPI::QuanserHapticsDevice::is_fatal_error)
	    .def("does_checksum_enable", &HAPI::QuanserHapticsDevice::does_checksum_enable)
	    .def("does_write_timeout_enable", &HAPI::QuanserHapticsDevice::does_write_timeout_enable)
	    .def("does_read_timeout_enable", &HAPI::QuanserHapticsDevice::does_read_timeout_enable)
	    ;
#else
	return scope();
#endif
}

template<> luabind::scope getLuaBinding<HAPI::SimballHapticsDevice>() {
	using namespace luabind;

#ifdef HAVE_SIMBALLMEDICAL_API
	return
	    HAPIHapticsDeviceSubclass<HAPI::SimballHapticsDevice>("SimballHapticsDevice")
	    .def(constructor<>())
	    .def(constructor<int>())
	    .def("getHandleAngle", &HAPI::SimballHapticsDevice::getHandleAngle)
	    ;
#else
	return scope();
#endif
}
