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
#include <luabind/adopt_policy.hpp>

#include <HAPI/HapticPositionFunctionEffect.h>

// Standard includes
// - none

namespace HAPI {
	class HAPIFunctionObject;
}

template<> luabind::scope getLuaBinding<HAPI::HapticPositionFunctionEffect>() {
	using namespace luabind;

	return
	    HAPIForceEffectSubclass<HAPI::HapticPositionFunctionEffect>("HapticPositionFunctionEffect")
	    .def(constructor<HAPI::HAPIFunctionObject *, HAPI::HAPIFunctionObject *, HAPI::HAPIFunctionObject *>(), adopt(_2) + adopt(_3) + adopt(_4))
	    ;
}

