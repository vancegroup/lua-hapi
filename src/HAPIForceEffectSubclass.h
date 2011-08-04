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
#ifndef INCLUDED_HAPIForceEffectSubclass_h_GUID_5917fb57_4d82_45b5_9015_d30b6d615bd4
#define INCLUDED_HAPIForceEffectSubclass_h_GUID_5917fb57_4d82_45b5_9015_d30b6d615bd4

// Internal Includes
#include "AutoRef.h"

// Library/third-party includes
#include <luabind/class.hpp>

#include <HAPI/HAPIForceEffect.h>

// Standard includes
// - none

template<typename T>
struct HAPIForceEffectSubclass : luabind::class_<T, HAPI::HAPIForceEffect, H3DUtil::AutoRef<HAPI::HAPIForceEffect> > {
	HAPIForceEffectSubclass(const char * name)
		: luabind::class_<T, HAPI::HAPIForceEffect, H3DUtil::AutoRef<HAPI::HAPIForceEffect> >(name)
	{}
};

#endif // INCLUDED_HAPIForceEffectSubclass_h_GUID_5917fb57_4d82_45b5_9015_d30b6d615bd4
