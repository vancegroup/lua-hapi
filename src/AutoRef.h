/** @file
	@brief Includes <H3DUtil/AutoRef.h> and provides get_pointer overload
	for AutoRef<T> for use by luabind

	@date 2011

	@author
	Ryan Pavlik
	<rpavlik@iastate.edu> and <abiryan@ryand.net>
	http://academic.cleardefinition.com/
	Iowa State University Virtual Reality Applications Center
	Human-Computer Interaction Graduate Program
*/

#pragma once
#ifndef INCLUDED_AutoRef_h_GUID_323bd905_21b3_4fdd_97e1_49a31af7df12
#define INCLUDED_AutoRef_h_GUID_323bd905_21b3_4fdd_97e1_49a31af7df12

// Internal Includes
// - none

// Library/third-party includes
#include <H3DUtil/AutoRef.h>

// Standard includes
// - none


namespace H3DUtil {
	template<typename T>
	class AutoRef;

	template<typename T>
	T * get_pointer(AutoRef<T> const& ptr) {
		return ptr.get();
	}
}

#endif // INCLUDED_AutoRef_h_GUID_323bd905_21b3_4fdd_97e1_49a31af7df12
