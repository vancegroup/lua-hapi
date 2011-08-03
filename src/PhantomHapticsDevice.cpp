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
#include "PhantomHapticsDevice.h"

// Library/third-party includes
#include <luabind/class.hpp>

#include <HAPI/PhantomHapticsDevice.h>

// Standard includes
// - none

template<> luabind::scope getLuaBinding<HAPI::PhantomHapticsDevice>() {
	using namespace luabind;
#ifdef HAVE_OPENHAPTICS
	return
	    class_<HAPI::PhantomHapticsDevice, HAPI::HAPIHapticsDevice>("PhantomHapticsDevice")
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

