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
#ifndef INCLUDED_VectorTraits_h_GUID_f06d1937_e273_4d30_a050_181244c95aef
#define INCLUDED_VectorTraits_h_GUID_f06d1937_e273_4d30_a050_181244c95aef

// Internal Includes
#include "VectorFwd.h"

// Library/third-party includes
// - none

// Standard includes
// - none

template<typename T>
struct H3DVectorTraits;

#define H3D_VECTOR_NAME(_DIM, _SCALARLETTER) H3DUtil::ArithmeticTypes::Vec ## _DIM ## _SCALARLETTER
//#define H3D_VECTOR_NAME_STRING(_DIM, _SCALARLETTER) "Vec" #_DIM #_SCALARLETTER
#define H3D_DEFINE_VECTOR_TRAITS(_DIM, _SCALARLETTER, _SCALAR) \
	template<> \
	struct H3DVectorTraits<H3D_VECTOR_NAME(_DIM, _SCALARLETTER)> { \
		static const int dimension = _DIM; \
		typedef _SCALAR scalar; \
		static const char * getName() { return "Vec" #_DIM #_SCALARLETTER; } \
	};

#define H3D_DEFINE_VECTOR_TRAITS_DIMENSION(_DIM) \
	H3D_DEFINE_VECTOR_TRAITS(_DIM, f, float) \
	H3D_DEFINE_VECTOR_TRAITS(_DIM, d, double)

//H3D_DEFINE_VECTOR_TRAITS(2, f, float)
//H3D_DEFINE_VECTOR_TRAITS(2, d, double)
H3D_DEFINE_VECTOR_TRAITS_DIMENSION(2)
H3D_DEFINE_VECTOR_TRAITS_DIMENSION(3)
H3D_DEFINE_VECTOR_TRAITS_DIMENSION(4)

#undef H3D_VECTOR_NAME
//#undef H3D_VECTOR_NAME_STRING
#undef H3D_DEFINE_VECTOR_TRAITS

#endif // INCLUDED_VectorTraits_h_GUID_f06d1937_e273_4d30_a050_181244c95aef
