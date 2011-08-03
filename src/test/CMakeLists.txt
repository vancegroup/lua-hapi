set(LUATESTS
	devicelog
	module
	vector)
find_program(LUA_COMMAND lua)

set(LAUNCHER ${LUA_COMMAND})
if(WIN32)
	if("${CMAKE_GENERATOR}" MATCHES "Visual Studio")
		set(CONFIGDIR %CONFIG%)
	else()
		set(CONFIGDIR)
	endif()
	set(EXTRA_PATH) #TODO
	configure_file("${CMAKE_CURRENT_SOURCE_DIR}/testrunner.bat.in" "${CMAKE_CURRENT_BINARY_DIR}/testrunner.bat" @ONLY)
	set(LAUNCHER "${CMAKE_CURRENT_BINARY_DIR}/testrunner.bat" "$<CONFIGURATION>")
endif()
foreach(LUATEST ${LUATESTS})
	add_test(NAME luatest_${LUATEST}
		WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/.."
		COMMAND ${LAUNCHER} -e "package.path='${CMAKE_CURRENT_SOURCE_DIR}/../../submodules/lunatest/?.lua;' .. package.path" "${CMAKE_CURRENT_SOURCE_DIR}/${LUATEST}.lua" -v)
endforeach()
