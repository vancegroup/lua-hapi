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

#include <HAPI/HaptionHapticsDevice.h>

// Standard includes
// - none

namespace HAPI {
	class HaptionHapticsDevice;
}

template<> luabind::scope getLuaBinding<HAPI::HaptionHapticsDevice>() {
	using namespace luabind;
#ifdef HAVE_VIRTUOSEAPI
	return
	    class_<HAPI::HaptionHapticsDevice, HAPI::HAPIHapticsDevice>("HaptionHapticsDevice")
	    .def(constructor<>())
	    .def(constructor<std::string const&>())
	    .def("getIpAddress", &HAPI::HaptionHapticsDevice::getIpAddress)
	    ;
#else
	return scope();
#endif
}

