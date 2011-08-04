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
#ifndef INCLUDED_HAPIHapticsDeviceSubclass_h_GUID_0e471916_0e98_457e_a40f_12483f094d47
#define INCLUDED_HAPIHapticsDeviceSubclass_h_GUID_0e471916_0e98_457e_a40f_12483f094d47

// Internal Includes
// - none

// Library/third-party includes
#include <luabind/class.hpp>

#include <HAPI/HAPIHapticsDevice.h>

// Standard includes
// - none

template<typename T>
struct HAPIHapticsDeviceSubclass : luabind::class_<T, HAPI::HAPIHapticsDevice> {
	HAPIHapticsDeviceSubclass(const char * name)
		: luabind::class_<T, HAPI::HAPIHapticsDevice>(name)
	{}
};

#endif // INCLUDED_HAPIHapticsDeviceSubclass_h_GUID_0e471916_0e98_457e_a40f_12483f094d47
