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
#include "AutoRef.h"

// Library/third-party includes
#include <luabind/class.hpp>

#include <HAPI/HapticSpring.h>

// Standard includes
// - none

template<> luabind::scope getLuaBinding<HAPI::HapticSpring>() {
	using namespace luabind;

	return
	    class_<HAPI::HapticSpring, HAPI::HAPIForceEffect, H3DUtil::AutoRef<HAPI::HAPIForceEffect> >("HapticSpring")
	    .def(constructor<>())
	    .def(constructor<const HAPI::Vec3 &, HAPI::HAPIFloat>())
	    .def(constructor<const HAPI::Vec3 &, HAPI::HAPIFloat, HAPI::HAPIFloat>())
	    .def("setPosition", &HAPI::HapticSpring::setPosition)
	    .def("setDamping", &HAPI::HapticSpring::setDamping)
	    .def("setSpringConstant", &HAPI::HapticSpring::setSpringConstant)
	    .def("getPosition", &HAPI::HapticSpring::getPosition)
	    .def("getDamping", &HAPI::HapticSpring::getDamping)
	    .def("getSpringConstant", &HAPI::HapticSpring::getSpringConstant)
	    .def("getLatestForce", &HAPI::HapticSpring::getLatestForce)
	    ;
}

