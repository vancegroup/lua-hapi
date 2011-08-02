set(LUATESTS
	module
	vector)
set(LUA_COMMAND lua )
foreach(LUATEST ${LUATESTS})
	add_test(NAME luatest_${LUATEST}
		WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/.."
		COMMAND ${LUA_COMMAND} -e "package.path='${CMAKE_CURRENT_SOURCE_DIR}/../../submodules/lunatest/?.lua;' .. package.path" "${CMAKE_CURRENT_SOURCE_DIR}/${LUATEST}.lua")
endforeach()
