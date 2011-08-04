set(LUATESTS
	class_info
	devicelog
	module
	vector)

set(LAUNCHER ${LUA_COMMAND})

if(WIN32)
	set(LAUNCHER "${CMAKE_CURRENT_BINARY_DIR}/testrunner.bat" "$<CONFIGURATION>")
	if("${CMAKE_GENERATOR}" MATCHES "Visual Studio")
		set(CONFIGDIR %CONFIG%)
		set(SPAWN_LAUNCHER "start" "Lua with access to luahapi and lunatest" ${LAUNCHER})
	else()
		set(CONFIGDIR)
		set(SPAWN_LAUNCHER ${LAUNCHER})
	endif()
	set(EXTRA_PATH) #TODO
	configure_file("${CMAKE_CURRENT_SOURCE_DIR}/testrunner.bat.in"
		"${CMAKE_CURRENT_BINARY_DIR}/testrunner.bat"
		@ONLY)
else()
	set(SPAWN_LAUNCHER ${LAUNCHER})
endif()

foreach(LUATEST ${LUATESTS})
	add_test(NAME luatest_${LUATEST}
		WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/.."
		COMMAND
		${LAUNCHER}
		-e
		"package.path='${CMAKE_CURRENT_SOURCE_DIR}/../../submodules/lunatest/?.lua;' .. package.path"
		"${CMAKE_CURRENT_SOURCE_DIR}/${LUATEST}.lua"
		-v)
endforeach()

add_custom_command(OUTPUT lua_launcher_dummy_stamp
	COMMAND
	${SPAWN_LAUNCHER}
	-e
	"package.path='${CMAKE_CURRENT_SOURCE_DIR}/../../submodules/lunatest/?.lua;' .. package.path" -i
	WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/..")
add_custom_target(RUN_LUA
	DEPENDS lua_launcher_dummy_stamp)
