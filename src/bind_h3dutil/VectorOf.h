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
#ifndef INCLUDED_VectorOf_h_GUID_a60ba17b_c90e_4a78_8b1e_4547d8b7b701
#define INCLUDED_VectorOf_h_GUID_a60ba17b_c90e_4a78_8b1e_4547d8b7b701

// Internal Includes
#include "VectorFwd.h"

// Library/third-party includes
// - none

// Standard includes
// - none

template<int Dimension, class Scalar>
struct H3DVectorOf;

template<>
struct H3DVectorOf<2, double> {
	typedef H3DUtil::ArithmeticTypes::Vec2d type;
};

template<>
struct H3DVectorOf<2, float> {
	typedef H3DUtil::ArithmeticTypes::Vec2f type;
};

template<>
struct H3DVectorOf<3, double> {
	typedef H3DUtil::ArithmeticTypes::Vec3d type;
};

template<>
struct H3DVectorOf<3, float> {
	typedef H3DUtil::ArithmeticTypes::Vec3f type;
};

template<>
struct H3DVectorOf<4, double> {
	typedef H3DUtil::ArithmeticTypes::Vec4d type;
};

template<>
struct H3DVectorOf<4, float> {
	typedef H3DUtil::ArithmeticTypes::Vec4f type;
};

#endif // INCLUDED_VectorOf_h_GUID_a60ba17b_c90e_4a78_8b1e_4547d8b7b701
