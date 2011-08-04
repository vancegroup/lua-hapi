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

#include <HAPI/ParsedFunction.h>

// Standard includes
// - none

#define FORWARDING_OBJECT_TYPE HAPI::ParsedFunction
#include "ForwardingMacros.h"
FORWARDER1(bool, setFunctionString, const std::string)
#include "ForwardingMacrosUndef.h"

template<> luabind::scope getLuaBinding<HAPI::ParsedFunction>() {
	using namespace luabind;

	return
	    class_<HAPI::ParsedFunction, HAPI::HAPIFunctionObject>("ParsedFunction")
	    .def(constructor<>())
	    .def("setFunctionString", &HAPI::ParsedFunction::setFunctionString)
	    .def("setFunctionString", &setFunctionString1)
	    .def("haveValidFunction", &HAPI::ParsedFunction::haveValidFunction)
	    .def("getFunction", &HAPI::ParsedFunction::getFunction)
	    .def("getParams", &HAPI::ParsedFunction::getParams)
	    ;
}

