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
#include "EntactHapticsDevice.h"

// Library/third-party includes
#include <luabind/class.hpp>

#include <HAPI/EntactHapticsDevice.h>

// Standard includes
// - none

template<> luabind::scope getLuaBinding<HAPI::EntactHapticsDevice>() {
	using namespace luabind;

	return
	    class_<HAPI::EntactHapticsDevice>("EntactHapticsDevice");
}

