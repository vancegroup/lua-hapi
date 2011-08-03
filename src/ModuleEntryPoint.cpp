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
#include "ModuleEntryPoint.h"
#include "BindingFwd.h"
#include "bind_h3dutil/Vector.h"

// Library/third-party includes
#include <luabind/open.hpp>

// Standard includes
// - none

namespace HAPI {
	class HAPIHapticsDevice;
	class HAPIHapticsRenderer;
	class HAPIForceEffect;
}

int luaopen_luahapi(lua_State *L) {
	using namespace luabind;
	open(L);
	module(L, "HAPI")
	[
	    bindVector(),
	    getLuaBinding<HAPI::HAPIHapticsDevice>(),
	    getLuaBinding<HAPI::HAPIHapticsRenderer>(),
	    getLuaBinding<HAPI::HAPIForceEffect>(),

	    scope() // trailing empty scope so we can put commas after each binding call
	];
	return 0;
}
