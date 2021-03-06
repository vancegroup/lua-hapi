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

#include <HAPI/HAPIFunctionObject.h>

// Standard includes
// - none

namespace HAPI {
	class ParsedFunction;
}

namespace {
	HAPI::HAPIFloat evaluate(HAPI::HAPIFunctionObject & o, HAPI::HAPIFloat val) {
		return o.evaluate(&val);
	}
}
template<> luabind::scope getLuaBinding<HAPI::HAPIFunctionObject>() {
	using namespace luabind;

	return
	    class_<HAPI::HAPIFunctionObject>("HAPIFunctionObject")
	    .def("evaluate", &evaluate)
	    , getLuaBinding<HAPI::ParsedFunction>()
	    ;
}

