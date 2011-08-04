include_directories(${LUABIND_INCLUDE_DIRS} ${HAPI_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
add_definitions(-DLUAHAPI_BUILDING)

if(OPENHAPTICS_INCLUDE_DIR)
	include_directories(${OPENHAPTICS_INCLUDE_DIR})
endif()
if(VIRTUOSE_INCLUDE_DIR)
	include_directories(${VIRTUOSE_INCLUDE_DIR})
endif()

set(SOURCES
	AutoRef.h
	BindingFwd.h
	HAPIForceEffectSubclass.h
	LuaInclude.h
	LuaInterface.h
	ModuleEntryPoint.cpp)

set(API
	ModuleEntryPoint.h
	LuaInterface.h)

set(HAPI_BINDING
	AnyHapticsDevice.cpp
	#DepthMapSurface.cpp
	DeviceLog.cpp
	#EntactHapticsDevice.cpp
	#FalconHapticsDevice.cpp
	#FeedbackBufferCollector.cpp
	#ForceDimensionHapticsDevice.cpp
	#FrictionSurface.cpp
	GodObjectRenderer.cpp
	HAPIForceEffect.cpp
	#HAPIFrictionSurface.cpp
	#HAPIFunctionObject.cpp
	#HAPIGLShape.cpp
	#HAPIHapticObject.cpp
	HAPIHapticsDevice.cpp
	#HAPIHapticShape.cpp
	HAPIHapticsRenderer.cpp
	HAPIProxyBasedRenderer.cpp
	#HAPIShapeRenderOptions.cpp
	#HAPISurfaceObject.cpp
	#HAPIVariableDepthSurface.cpp
	#HapticForceField.cpp
	#HapticLineSet.cpp
	#HapticMasterDevice.cpp
	#HapticPointSet.cpp
	#HapticPositionFunctionEffect.cpp
	#HapticPrimitive.cpp
	#HapticPrimitiveSet.cpp
	#HapticPrimitiveTree.cpp
	#HapticRotationalSpring.cpp
	#HapticShapeConstraint.cpp
	HapticSpring.cpp
	#HapticTexturesSurface.cpp
	#HapticTimeFunctionEffect.cpp
	#HapticTriangleSet.cpp
	#HapticTriangleTree.cpp
	#HapticViscosity.cpp
	#HaptikHapticsDevice.cpp
	HaptionHapticsDevice.cpp
	#HLThread.cpp
	#ImageInterfaceObject.cpp
	#IntersectionInfo.cpp
	#MLHIHapticsDevice.cpp
	#NiFalconHapticsDevice.cpp
	#ParsedFunction.cpp
	PhantomHapticsDevice.cpp
	#PlaneConstraint.cpp
	#QuanserHapticsDevice.cpp
	#RuspiniRenderer.cpp
	#SimballHapticsDevice.cpp
)

set(H3DUTIL_BINDING
	bind_h3dutil/VectorTraits.h
	bind_h3dutil/VectorOf.h
	bind_h3dutil/Vector.h
	bind_h3dutil/Vector.cpp
	bind_h3dutil/VectorFwd.h
)

add_library(luahapi MODULE ${SOURCES} ${API} ${HAPI_BINDING} ${H3DUTIL_BINDING})
set_property(TARGET luahapi PROPERTY PREFIX "")
target_link_libraries(luahapi ${LUABIND_LIBRARIES} HAPI)

if(BUILD_TESTING)
	if(NOT LUA_COMMAND)
		message(FATAL_ERROR "Can't test without LUA_COMMAND set - either set it or disable BUILD_TESTING!")
	endif()
	add_subdirectory(test)
endif()

install(TARGETS luahapi
	RUNTIME DESTINATION bin COMPONENT binding
	LIBRARY DESTINATION bin COMPONENT binding)

set(LUAHAPI_INSTALL_NAME "${CMAKE_INSTALL_PREFIX}/bin/luahapi${CMAKE_SHARED_MODULE_SUFFIX}")

set(APP)
set(PLUGINS)
set(LIBRARY_DIRS)

if(LUA_COMMAND)
	install(PROGRAMS "${LUA_COMMAND}" DESTINATION bin)
	get_filename_component(LUA_COMMAND_FILENAME "${LUA_COMMAND}" NAME)
	list(APPEND PLUGINS "${LUAHAPI_INSTALL_NAME}")
	set(APP "${CMAKE_INSTALL_PREFIX}/bin/${LUA_COMMAND_FILENAME}")
else()
	set(APP "${LUAHAPI_INSTALL_NAME}")
endif()


if(WIN32)
	install(TARGETS ${PTHREADS_LIBRARY}
		RUNTIME DESTINATION bin COMPONENT hapideps
		PUBLIC_HEADER DESTINATION include COMPONENT extradev
		ARCHIVE DESTINATION lib COMPONENT extradev)
endif()


get_filename_component(LUA_LIBDIR "${LUA_LIBRARY}" PATH)
list(APPEND LIBRARY_DIRS "${LUA_LIBDIR}")

install(CODE "
  include(BundleUtilities)
  fixup_bundle(\"${APP}\" \"${PLUGINS}\" \"${LIBRARY_DIRS}\")
  ")
