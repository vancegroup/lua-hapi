if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/hapi/build/CMakeLists.txt")
	message(FATAL_ERROR "hapi/h3dutil submodules not found - please run git submodule update --init in your source tree!")
endif()

# Tell HAPI the place where we put H3DUtil
set(H3DUTIL_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/h3dutil/H3DUtil")

# Disable finding DCMTK in H3DUtil
set(DCMTK_config_INCLUDE_DIR "")

# Recurse into the HAPI build
add_subdirectory(hapi/build)

# Clean up its mess
mark_as_advanced(HAPI_EXAMPLE_PROJECTS DCMTK_HAVE_CONFIG_H)

set(HAPI_INCLUDE_DIRS
	"${CMAKE_CURRENT_SOURCE_DIR}/hapi/include"
	"${CMAKE_CURRENT_BINARY_DIR}/hapi/build/include/"
	"${CMAKE_CURRENT_SOURCE_DIR}/h3dutil/H3DUtil/include"
	"${CMAKE_CURRENT_BINARY_DIR}/hapi/build/h3dutil-build/include")

# Propagate include dirs
set(HAPI_INCLUDE_DIRS "${HAPI_INCLUDE_DIRS}" PARENT_SCOPE)
