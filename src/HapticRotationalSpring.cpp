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
#include "HAPIForceEffectSubclass.h"

// Library/third-party includes
#include <luabind/class.hpp>

#include <HAPI/HapticRotationalSpring.h>

// Standard includes
// - none

template<> luabind::scope getLuaBinding<HAPI::HapticRotationalSpring>() {
	using namespace luabind;

	return
	    HAPIForceEffectSubclass<HAPI::HapticRotationalSpring>("HapticRotationalSpring")
	    .def(constructor<>())
	    .def(constructor<HAPI::Vec3 const&, HAPI::HAPIFloat>())
	    .def(constructor<HAPI::Vec3 const&, HAPI::HAPIFloat, HAPI::HAPIFloat>())
	    .def("setDesiredAxis", &HAPI::HapticRotationalSpring::setDesiredAxis)
	    .def("setDamping", &HAPI::HapticRotationalSpring::setDamping)
	    .def("setSpringConstant", &HAPI::HapticRotationalSpring::setSpringConstant)
	    .def("getDesiredAxis", &HAPI::HapticRotationalSpring::getDesiredAxis)
	    .def("getDamping", &HAPI::HapticRotationalSpring::getDamping)
	    .def("getSpringConstant", &HAPI::HapticRotationalSpring::getSpringConstant)
	    .def("getLatestTorque", &HAPI::HapticRotationalSpring::getLatestTorque)
	    ;
}

