cmake_minimum_required (VERSION 2.6)
project (Cpp11Demo)
 
# The version number.
set (CPP11_DEMO_VERSION_MAJOR 1)
set (CPP11_DEMO_VERSION_MINOR 0)

# export compilation database used by YCM
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

# does this system provide the log and exp functions?
include (CheckFunctionExists)

# configure a header file to pass some of the CMake settings
# to the source code
#configure_file (
  #"${PROJECT_SOURCE_DIR}/cpp11_config.h.in"
  #"${PROJECT_BINARY_DIR}/cpp11_config.h"
  #)

# add compiler flags
set (CC_CXX11_FLAGS "--std=c++11")
set ( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${CC_CXX11_FLAGS}")
 
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories ("${PROJECT_BINARY_DIR}")
 
# add the executable
add_executable (array_begin_end_ array_begin_end.cc)
add_executable (auto_ auto.cc)
add_executable (constexpr_ constexpr.cc)
add_executable (constexpr_func_ constexpr_func.cc)
add_executable (decltype_ decltype.cc)
add_executable (inclass_init_ inclass_init.cc)
add_executable (initializer_list_ initializer_list.cc)
add_executable (list_init_ list_init.cc)
add_executable (null_ptr_ null_ptr.cc)
add_executable (range_for_ range_for.cc)
add_executable (sizeof_member_ sizeof_member.cc)
add_executable (trailing_return_type_ trailing_return_type.cc)
add_executable (type_alias_ type_alias.cc)
add_executable (default_constructor_ default_constructor.cc)
add_executable (delegating_constructor_ delegating_constructor.cc)
add_executable (lambda_ lambda.cc)
add_executable (bind_ bind.cc)
add_executable (shared_ptr_ shared_ptr.cc)
add_executable (unique_ptr_ unique_ptr.cc)
add_executable (weak_ptr_ weak_ptr.cc)
add_executable (delete_ctor_ delete_ctor.cc)
add_executable (move_ move.cc)
 
# add the install targets
install (TARGETS array_begin_end_ DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/cpp11_config.h"        
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
