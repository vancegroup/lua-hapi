
cmake_minimum_required(VERSION 2.8.0)

# Set package properties
project(luahapi)

set(CPACK_PACKAGE_VENDOR "Iowa State University - Vance Research Group")
set(CPACK_PACKAGE_CONTACT "Ryan Pavlik <rpavlik@iastate.edu>")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
find_package(Luabind REQUIRED)

add_subdirectory(submodules)
add_subdirectory(src)
