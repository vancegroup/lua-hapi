/** @file
	@brief Header defining macros for extern "C" and __declspec as needed.

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


#pragma once
#ifndef INCLUDED_LuaInterface_h_GUID_d1fea0f3_6f4b_4e41_b848_77ed8de156fd
#define INCLUDED_LuaInterface_h_GUID_d1fea0f3_6f4b_4e41_b848_77ed8de156fd

// Internal Includes
// - none

// Library/third-party includes
// - none

// Standard includes
// - none

#ifdef LUAHAPI_LUA_BUILT_AS_CPP
#	define LUAHAPI_BEGIN_LUA_INTERFACE
#	define LUAHAPI_END_LUA_INTERFACE
#else
#	define LUAHAPI_BEGIN_LUA_INTERFACE extern "C" {
#	define LUAHAPI_END_LUA_INTERFACE }
#endif

#ifdef _WIN32
#	ifdef LUAHAPI_BUILDING
#		define LUAHAPI_API __declspec(dllexport)
#	else
#		define LUAHAPI_API __declspec(dllimport)
#	endif
#else
#	define LUAHAPI_API
#endif

#endif // INCLUDED_LuaInterface_h_GUID_d1fea0f3_6f4b_4e41_b848_77ed8de156fd
