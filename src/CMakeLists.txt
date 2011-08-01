include_directories(${LUABIND_INCLUDE_DIRS} ${HAPI_INCLUDE_DIRS})
add_definitions(-DLUAHAPI_BUILDING)

set(SOURCES
	LuaInclude.h
	ModuleEntryPoint.cpp)

set(API	
	ModuleEntryPoint.h
	LuaInterface.h)

add_library(luahapi MODULE ${SOURCES} ${API})
set_property(TARGET luahapi PROPERTY PREFIX "")
target_link_libraries(luahapi ${LUABIND_LIBRARIES} HAPI)
