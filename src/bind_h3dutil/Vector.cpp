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
#include "Vector.h"

#include "VectorOf.h"
#include "VectorTraits.h"

// Library/third-party includes
#include <luabind/class.hpp>
#include <luabind/operator.hpp>

#include <HAPI/HAPITypes.h>

// Standard includes
// - none

template<class T>
struct VectorBindingBase : public luabind::class_<T> {
	public:
		typedef typename H3DVectorTraits<T>::scalar Scalar;
		static int getDimension(const T &) {
			return H3DVectorTraits<T>::dimension;
		}
		VectorBindingBase(const char * classname)
			: luabind::class_<T>(classname) {
			using namespace luabind;

			(*this)
			.def(constructor<>()) // default constructor
			.def(constructor<T const&>()) // copy constructor
			.property("dimension", &VectorBindingBase::getDimension)
			.def(const_self == const_self)
			.def(const_self + const_self)
			.def(const_self - const_self)
			.def(const_self * const_self)
			.def("dotProduct", &HAPI::Vec3::dotProduct)
			.def(const_self * other<Scalar>())
			.def(- const_self)
			.def(tostring(const_self));
		}
};

template<class T>
struct VectorBinding : public VectorBindingBase<T> {

	VectorBinding(const char * classname)
		: VectorBindingBase<T>(classname) {
		using namespace luabind;

		(*this)
		.def("normalize", &T::normalize)
		.def("normalizeSafe", &T::normalizeSafe)
		.property("length", &T::length)
		.property("lengthSqr", &T::lengthSqr);
	}
};

template<>
struct VectorBinding<HAPI::Vec4> : public VectorBindingBase<HAPI::Vec4> {
	VectorBinding(const char * classname) : VectorBindingBase<HAPI::Vec4>(classname) {}
};


luabind::scope bindVector() {
	using namespace luabind;
	typedef HAPI::HAPIFloat Scalar;
	return
	    VectorBinding<HAPI::Vec2>("Vec2")
	    .def(constructor<Scalar, Scalar>())
	    .def_readwrite("x", &HAPI::Vec2::x)
	    .def_readwrite("y", &HAPI::Vec2::y)
	    ,
	    VectorBinding<HAPI::Vec3>("Vec3")
	    .def(constructor<Scalar, Scalar, Scalar>())
	    .def("crossProduct", &HAPI::Vec3::crossProduct)
	    .def_readwrite("x", &HAPI::Vec3::x)
	    .def_readwrite("y", &HAPI::Vec3::y)
	    .def_readwrite("z", &HAPI::Vec3::z)
	    ,
	    VectorBinding<HAPI::Vec4>("Vec4")
	    .def(constructor<Scalar, Scalar, Scalar, Scalar>())
	    .def_readwrite("x", &HAPI::Vec4::x)
	    .def_readwrite("y", &HAPI::Vec4::y)
	    .def_readwrite("z", &HAPI::Vec4::z)
	    .def_readwrite("w", &HAPI::Vec4::w)
	    ;
}
