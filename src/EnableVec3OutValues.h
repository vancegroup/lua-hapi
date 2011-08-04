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

//          Copyright Iowa State University 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once
#ifndef INCLUDED_EnableVec3OutValues_h_GUID_56aa9218_cacc_49a7_a3b0_c7b505a4adc3
#define INCLUDED_EnableVec3OutValues_h_GUID_56aa9218_cacc_49a7_a3b0_c7b505a4adc3

// Internal Includes
// - none

// Library/third-party includes
#include <HAPI/HAPITypes.h>
#include <luabind/out_value_policy.hpp>

// Standard includes
// - none

namespace luabind {
	namespace detail {
		/// Overload for the indirect_sizeof_test for HAPI::Vec3 &: without this,
		/// Visual Studio 2008 doesn't build when an outvalue-using device (like Phantom)
		/// is enabled.
		char_array<sizeof(HAPI::Vec3)> indirect_sizeof_test(by_reference<HAPI::Vec3>);
	} // end of namespace detail
} // end of namespace luabind


#endif // INCLUDED_EnableVec3OutValues_h_GUID_56aa9218_cacc_49a7_a3b0_c7b505a4adc3
