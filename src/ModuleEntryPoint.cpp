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
#include "ModuleEntryPoint.h"

#include "HAPIHapticsDevice.h"
#include "AnyHapticsDevice.h"

// Library/third-party includes
#include <luabind/open.hpp>

// Standard includes
// - none


int luaopen_luahapi(lua_State *L) {
	using namespace luabind;
	open(L);
	module(L, "HAPI")
	[
	    HAPIHapticsDevice::bind(),
	    AnyHapticsDevice::bind(),

	    scope() // trailing empty scope so we can put commas after each binding call
	];
	return 0;
}