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
#ifndef INCLUDED_VectorBinding_h_GUID_c5d5f62c_375e_46ab_adf3_fe872e387f7d
#define INCLUDED_VectorBinding_h_GUID_c5d5f62c_375e_46ab_adf3_fe872e387f7d

// Internal Includes
#include "VectorOf.h"
#include "VectorTraits.h"

// Library/third-party includes
#include <luabind/class.hpp>
#include <luabind/operator.hpp>

// Standard includes
// - none

template<class T>
class VectorBinding : public luabind::class_<T> {
	public:
		static int getDimension(const T &) {
			return H3DVectorTraits<T>::dimension;
		}
		VectorBinding(const char * classname) :
			luabind::class_<T>(classname) {
			using namespace luabind;

			(*this)
			.property("dimension", &VectorBinding::getDimension)
			.def(const_self == const_self)
			.def(const_self + const_self)
			.def(const_self - const_self)
			.def(const_self * const_self)
			.def(const_self * other<typename H3DVectorTraits<T>::scalar>())
			.def("normalize", &T::normalize)
			.def("normalizeSafe", &T::normalizeSafe)
			.def(- const_self)
			.def(tostring(const_self));
		}
};

#endif // INCLUDED_VectorBinding_h_GUID_c5d5f62c_375e_46ab_adf3_fe872e387f7d
