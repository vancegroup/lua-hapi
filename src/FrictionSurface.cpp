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

#include <HAPI/FrictionSurface.h>

// Standard includes
// - none

template<> luabind::scope getLuaBinding<HAPI::FrictionSurface>() {
	using namespace luabind;

	return
	    class_<HAPI::FrictionSurface, HAPI::HAPIFrictionSurface, H3DUtil::AutoRef<HAPI::HAPISurfaceObject> >("FrictionSurface")
	    .def(constructor<>())
	    .def(constructor<HAPI::HAPIFloat>())
	    .def(constructor<HAPI::HAPIFloat, HAPI::HAPIFloat>())
	    .def(constructor<HAPI::HAPIFloat, HAPI::HAPIFloat, HAPI::HAPIFloat>())
	    .def(constructor<HAPI::HAPIFloat, HAPI::HAPIFloat, HAPI::HAPIFloat, HAPI::HAPIFloat>())
	    .def(constructor<HAPI::HAPIFloat, HAPI::HAPIFloat, HAPI::HAPIFloat, HAPI::HAPIFloat, bool>())
	    .def(constructor<HAPI::HAPIFloat, HAPI::HAPIFloat, HAPI::HAPIFloat, HAPI::HAPIFloat, bool, bool>())
	    ;
}

