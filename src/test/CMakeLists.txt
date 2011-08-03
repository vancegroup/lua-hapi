set(LUATESTS
	devicelog
	module
	vector)
find_program(LUA_COMMAND lua)

set(LAUNCHER ${LUA_COMMAND})
foreach(LUATEST ${LUATESTS})
	add_test(NAME luatest_${LUATEST}
		WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/.."
		COMMAND ${LAUNCHER} -e "package.path='${CMAKE_CURRENT_SOURCE_DIR}/../../submodules/lunatest/?.lua;' .. package.path" "${CMAKE_CURRENT_SOURCE_DIR}/${LUATEST}.lua" -v)
endforeach()
