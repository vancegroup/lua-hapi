include_directories(${LUABIND_INCLUDE_DIRS} ${HAPI_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
add_definitions(-DLUAHAPI_BUILDING)

if(OPENHAPTICS_INCLUDE_DIR)
	include_directories(${OPENHAPTICS_INCLUDE_DIR})
endif()
if(VIRTUOSE_INCLUDE_DIR)
	include_directories(${VIRTUOSE_INCLUDE_DIR})
endif()

set(SOURCES
	BindingFwd.h
	LuaInclude.h
	ModuleEntryPoint.cpp)

set(API	
	ModuleEntryPoint.h
	LuaInterface.h)

set(HAPI_BINDING
	AnyHapticsDevice.cpp
	AnyHapticsDevice.h
#	DepthMapSurface.cpp
#	DepthMapSurface.h
	DeviceLog.cpp
	DeviceLog.h
#	EntactHapticsDevice.cpp
#	EntactHapticsDevice.h
#	FalconHapticsDevice.cpp
#	FalconHapticsDevice.h
#	FeedbackBufferCollector.cpp
#	FeedbackBufferCollector.h
#	ForceDimensionHapticsDevice.cpp
#	ForceDimensionHapticsDevice.h
#	FrictionSurface.cpp
#	FrictionSurface.h
	GodObjectRenderer.cpp
	GodObjectRenderer.h
	HAPIForceEffect.cpp
	HAPIForceEffect.h
#	HAPIFrictionSurface.cpp
#	HAPIFrictionSurface.h
#	HAPIFunctionObject.cpp
#	HAPIFunctionObject.h
#	HAPIGLShape.cpp
#	HAPIGLShape.h
#	HAPIHapticObject.cpp
#	HAPIHapticObject.h
	HAPIHapticsDevice.cpp
	HAPIHapticsDevice.h
#	HAPIHapticShape.cpp
#	HAPIHapticShape.h
	HAPIHapticsRenderer.cpp
	HAPIHapticsRenderer.h
	HAPIProxyBasedRenderer.cpp
	HAPIProxyBasedRenderer.h
#	HAPIShapeRenderOptions.cpp
#	HAPIShapeRenderOptions.h
#	HAPISurfaceObject.cpp
#	HAPISurfaceObject.h
#	HAPIVariableDepthSurface.cpp
#	HAPIVariableDepthSurface.h
#	HapticForceField.cpp
#	HapticForceField.h
#	HapticLineSet.cpp
#	HapticLineSet.h
#	HapticMasterDevice.cpp
#	HapticMasterDevice.h
#	HapticPointSet.cpp
#	HapticPointSet.h
#	HapticPositionFunctionEffect.cpp
#	HapticPositionFunctionEffect.h
#	HapticPrimitive.cpp
#	HapticPrimitive.h
#	HapticPrimitiveSet.cpp
#	HapticPrimitiveSet.h
#	HapticPrimitiveTree.cpp
#	HapticPrimitiveTree.h
#	HapticRotationalSpring.cpp
#	HapticRotationalSpring.h
#	HapticShapeConstraint.cpp
#	HapticShapeConstraint.h
#	HapticSpring.cpp
#	HapticSpring.h
#	HapticTexturesSurface.cpp
#	HapticTexturesSurface.h
#	HapticTimeFunctionEffect.cpp
#	HapticTimeFunctionEffect.h
#	HapticTriangleSet.cpp
#	HapticTriangleSet.h
#	HapticTriangleTree.cpp
#	HapticTriangleTree.h
#	HapticViscosity.cpp
#	HapticViscosity.h
#	HaptikHapticsDevice.cpp
#	HaptikHapticsDevice.h
	HaptionHapticsDevice.cpp
	HaptionHapticsDevice.h
#	HLThread.cpp
#	HLThread.h
#	ImageInterfaceObject.cpp
#	ImageInterfaceObject.h
#	IntersectionInfo.cpp
#	IntersectionInfo.h
#	MLHIHapticsDevice.cpp
#	MLHIHapticsDevice.h
#	NiFalconHapticsDevice.cpp
#	NiFalconHapticsDevice.h
#	ParsedFunction.cpp
#	ParsedFunction.h
	PhantomHapticsDevice.cpp
	PhantomHapticsDevice.h
#	PlaneConstraint.cpp
#	PlaneConstraint.h
#	QuanserHapticsDevice.cpp
#	QuanserHapticsDevice.h
#	RuspiniRenderer.cpp
#	RuspiniRenderer.h
#	SimballHapticsDevice.cpp
#	SimballHapticsDevice.h
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