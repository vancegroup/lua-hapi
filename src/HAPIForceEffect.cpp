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

#include <HAPI/HAPIForceEffect.h>

// Standard includes
// - none
namespace HAPI {
	class DeviceLog;
	class HapticSpring;
}

template<> luabind::scope getLuaBinding<HAPI::HAPIForceEffect>() {
	using namespace luabind;

	return
	    class_<HAPI::HAPIForceEffect, H3DUtil::AutoRef<HAPI::HAPIForceEffect> >("HAPIForceEffect")
	    , getLuaBinding<HAPI::DeviceLog>()
	    /*
	    , getLuaBinding<HAPI::HapticForceField>()
	    , getLuaBinding<HAPI::PositionFunctionEffect>()
	    , getLuaBinding<HAPI::HapticRotationalSpring>()
	    , getLuaBinding<HAPI::HapticShapeConstraint>()
	    */
	    , getLuaBinding<HAPI::HapticSpring>()
	    /*
	    , getLuaBinding<HAPI::HapticTimeFunctionEffect>()
	    , getLuaBinding<HAPI::HapticViscosity>()
	    */
	    ;
}

