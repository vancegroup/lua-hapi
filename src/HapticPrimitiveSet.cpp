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

// Internal Includes
#include "HapticPrimitiveSet.h"

// Library/third-party includes
#include <luabind/class.hpp>

#include <HAPI/HapticPrimitiveSet.h>

// Standard includes
// - none

template<> luabind::scope bind<HAPI::HapticPrimitiveSet>() {
	using namespace luabind;

	return
	    class_<HAPI::HapticPrimitiveSet>("HapticPrimitiveSet");
}

