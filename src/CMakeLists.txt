include_directories(${LUABIND_INCLUDE_DIRS} ${HAPI_INCLUDE_DIRS})
add_definitions(-DLUAHAPI_BUILDING)

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
#	DeviceLog.cpp
#	DeviceLog.h
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
#	GodObjectRenderer.cpp
#	GodObjectRenderer.h
#	HAPIForceEffect.cpp
#	HAPIForceEffect.h
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
#	HaptionHapticsDevice.cpp
#	HaptionHapticsDevice.h
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
#	PhantomHapticsDevice.cpp
#	PhantomHapticsDevice.h
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

add_subdirectory(test)
