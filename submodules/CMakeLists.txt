if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/hapi/build/CMakeLists.txt")
	message(FATAL_ERROR "hapi/h3dutil submodules not found - please run git submodule update --init in your source tree!")
endif()

set(H3DUTIL_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/h3dutil/H3DUtil")

add_subdirectory(hapi/build)
mark_as_advanced(HAPI_EXAMPLE_PROJECTS DCMTK_HAVE_CONFIG_H)
