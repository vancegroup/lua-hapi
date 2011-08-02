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
#include "Vec2.h"
#include "VectorBinding.h"

// Library/third-party includes
#include <HAPI/HAPITypes.h>

// Standard includes
// - none






luabind::scope bindVec2() {
	using namespace luabind;
	return VectorBinding<HAPI::Vec2>("Vec2");
}
