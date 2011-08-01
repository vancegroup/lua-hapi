/** @file
	@brief Header

	@date 2011

	@author
	Ryan Pavlik
	<rpavlik@iastate.edu> and <abiryan@ryand.net>
	http://academic.cleardefinition.com/
	Iowa State University Virtual Reality Applications Center
	Human-Computer Interaction Graduate Program
*/

#pragma once
#ifndef INCLUDED_ModuleEntryPoint_h_GUID_8690c734_bdd8_45f8_8401_87c948f4090c
#define INCLUDED_ModuleEntryPoint_h_GUID_8690c734_bdd8_45f8_8401_87c948f4090c

// Internal Includes
#include "LuaInterface.h"

// Library/third-party includes
// - none

// Standard includes
// - none

LUAHAPI_BEGIN_LUA_INTERFACE

struct lua_State;
int LUAHAPI_API luaopen_luahapi(lua_State *L);

LUAHAPI_END_LUA_INTERFACE

#endif // INCLUDED_ModuleEntryPoint_h_GUID_8690c734_bdd8_45f8_8401_87c948f4090c
