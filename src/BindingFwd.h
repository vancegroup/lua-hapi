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

namespace H3DUtil {
	template<typename T>
	class AutoRef;

	template<typename T>
	T * get_pointer(AutoRef<T> const& ptr) {
		return ptr.get();
	}
}

#endif // INCLUDED_BindingFwd_h_GUID_fe617b29_8694_462f_866d_76c72adadf0d
