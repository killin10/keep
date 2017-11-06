cmake_minimum_required (VERSION 2.6)
project (BoostDemo)
 
# The version number.
set (BOOST_DEMO_VERSION_MAJOR 1)
set (BOOST_DEMO_VERSION_MINOR 0)

# export compilation database used by YCM
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

# does this system provide the log and exp functions?
include (CheckFunctionExists)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/boost_config.h.in"
  "${PROJECT_BINARY_DIR}/boost_config.h"
  )

# add compiler flags
set (CC_CXX11_FLAGS "--std=c++11")
set ( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${CC_CXX11_FLAGS}")
 
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories ("${PROJECT_BINARY_DIR}")
 
# add the executable
add_executable (first_boost_ first_boost.cc)
add_executable (link_demo_ link_demo.cc)
target_link_libraries (link_demo_ boost_regex)
add_executable (boost_assert_ boost_assert.cc)
add_executable (boost_static_assert_ boost_static_assert.cc)
 
# add the install targets
install (TARGETS first_boost_ DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/boost_config.h"        
         DESTINATION include)
 
# build a CPack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE
     "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${BOOST_DEMO_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${BOOST_DEMO_VERSION_MINOR}")

set(CPACK_SOURCE_IGNORE_FILES "/build/")

include (CPack)

# distclean
add_custom_target(distclean
   COMMAND ${CMAKE_BUILD_TOOL} clean
   COMMAND rm -rf "${PROJECT_SOURCE_DIR}/build/*"
   COMMAND rm -rf "${PROJECT_BINARY_DIR}/CMakeFiles"
   COMMAND rm -rf "${PROJECT_BINARY_DIR}/CMakeCache.txt"
   COMMAND rm -rf "${PROJECT_BINARY_DIR}/Makefile"
   COMMAND rm -rf "${PROJECT_BINARY_DIR}/*.cmake"
   COMMAND rm -f "${PROJECT_SOURCE_DIR}/compile_commands.json"
)

# add compilation database
add_custom_target(cdb
    COMMAND ln -sf "${PROJECT_BINARY_DIR}/compile_commands.json" ${PROJECT_SOURCE_DIR}
)
