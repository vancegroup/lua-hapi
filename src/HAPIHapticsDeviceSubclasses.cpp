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

// Library/third-party includes
#include <luabind/class.hpp>
#include <luabind/out_value_policy.hpp>

#include <HAPI/AnyHapticsDevice.h>
#include <HAPI/EntactHapticsDevice.h>
#include <HAPI/HaptionHapticsDevice.h>
#include <HAPI/PhantomHapticsDevice.h>

// Standard includes
// - none

namespace HAPI {
	class AnyHapticsDevice;
	class EntactHapticsDevice;
	class HaptionHapticsDevice;
	class PhantomHapticsDevice;
}

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
	    /// @todo UNIMPLEMENTED STUB
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
