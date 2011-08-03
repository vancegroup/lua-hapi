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

//          Copyright Iowa State University 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


// Internal Includes
#include "DeviceLog.h"
#include "AutoRef.h"

// Library/third-party includes
#include <luabind/class.hpp>
#include <luabind/object.hpp>

#include <HAPI/DeviceLog.h>

// Standard includes
// - none

namespace {
	HAPI::DeviceLog::LogTypeVector createLogTypeVector(luabind::object const arg) {
		using namespace luabind;
		HAPI::DeviceLog::LogTypeVector ret;
		for (luabind::iterator i(arg), end; i != end; ++i) {
			ret.push_back(object_cast<HAPI::DeviceLog::LogType>(*i));
		}
		return ret;
	}
}
template<> luabind::scope getLuaBinding<HAPI::DeviceLog>() {
	using namespace luabind;

	return
	    class_<HAPI::DeviceLog, HAPI::HAPIForceEffect, H3DUtil::AutoRef<HAPI::HAPIForceEffect> >("DeviceLog")
	    .scope[
	        class_<HAPI::DeviceLog::LogTypeVector>("LogTypeVector"),
	        def("LogTypeVector", &createLogTypeVector)
	    ]
	    .def(constructor<string, HAPI::DeviceLog::LogTypeVector>())
	    .enum_("LogType")
	    [
	        value("TIME", HAPI::DeviceLog::TIME)
	        , value("POSITION", HAPI::DeviceLog::POSITION)
	        , value("ORIENTATION", HAPI::DeviceLog::ORIENTATION)
	        , value("VELOCITY", HAPI::DeviceLog::VELOCITY)
	        , value("FORCE", HAPI::DeviceLog::FORCE)
	        , value("TORQUE", HAPI::DeviceLog::TORQUE)
	        , value("BUTTONS", HAPI::DeviceLog::BUTTONS)

	        , value("RAW_POSITION", HAPI::DeviceLog::RAW_POSITION)
	        , value("RAW_ORIENTATION", HAPI::DeviceLog::RAW_ORIENTATION)
	        , value("RAW_VELOCITY", HAPI::DeviceLog::RAW_VELOCITY)
	        , value("RAW_FORCE", HAPI::DeviceLog::RAW_FORCE)
	        , value("RAW_TORQUE", HAPI::DeviceLog::RAW_TORQUE)
	    ]
	    ;
}


