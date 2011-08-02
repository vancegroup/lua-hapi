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
#ifndef INCLUDED_BindingFwd_h_GUID_fe617b29_8694_462f_866d_76c72adadf0d
#define INCLUDED_BindingFwd_h_GUID_fe617b29_8694_462f_866d_76c72adadf0d

// Internal Includes
// - none

// Library/third-party includes
#include <luabind/scope.hpp>

// Standard includes
// - none

template<typename T>
luabind::scope getLuaBinding();

#endif // INCLUDED_BindingFwd_h_GUID_fe617b29_8694_462f_866d_76c72adadf0d
