/** @file
	@brief Header defining macros to forward method calls for overloaded
	methods or methods with default arguments.

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


#ifndef FORWARDING_OBJECT_TYPE
#	error "Must define FORWARDING_OBJECT_TYPE before including ForwardingMacros.h!"
#endif

#ifdef FORWARDER_IMPL_0

#	error "Must include ForwardingMacrosUndef.h before re-including ForwardingMacros.h!"

#else

#	define FORWARDER_IMPL_0(_RTYPE, _RET, _METHOD) \
	namespace { \
		_RTYPE _METHOD ## 0 (FORWARDING_OBJECT_TYPE & o) { \
			_RET o. _METHOD(); \
		} \
	}

#	define VOID_FORWARDER0(_METHOD) FORWARDER_IMPL_0(void, , _METHOD)
#	define FORWARDER0(_RTYPE, _METHOD) FORWARDER_IMPL_0(_RTYPE, return, _METHOD)

#	define FORWARDER_IMPL_1(_RTYPE, _RET, _METHOD, _T1) \
	namespace { \
		_RTYPE _METHOD ## 1 (FORWARDING_OBJECT_TYPE & o, _T1 a1) { \
			_RET o. _METHOD(a1); \
		} \
	}

#	define VOID_FORWARDER1(_METHOD, _T1) FORWARDER_IMPL_1(void, , _METHOD, _T1)
#	define FORWARDER1(_RTYPE, _METHOD, _T1) FORWARDER_IMPL_1(_RTYPE, return, _METHOD, _T1)

#endif // FORWARDER_IMPL_0
