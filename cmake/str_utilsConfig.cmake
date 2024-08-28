# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.8)
   message(FATAL_ERROR "CMake >= 2.8.0 required")
endif()
if(CMAKE_VERSION VERSION_LESS "2.8.3")
   message(FATAL_ERROR "CMake >= 2.8.3 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.8.3...3.26)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_cmake_targets_defined "")
set(_cmake_targets_not_defined "")
set(_cmake_expected_targets "")
foreach(_cmake_expected_target IN ITEMS str_utils)
  list(APPEND _cmake_expected_targets "${_cmake_expected_target}")
  if(TARGET "${_cmake_expected_target}")
    list(APPEND _cmake_targets_defined "${_cmake_expected_target}")
  else()
    list(APPEND _cmake_targets_not_defined "${_cmake_expected_target}")
  endif()
endforeach()
unset(_cmake_expected_target)
if(_cmake_targets_defined STREQUAL _cmake_expected_targets)
  unset(_cmake_targets_defined)
  unset(_cmake_targets_not_defined)
  unset(_cmake_expected_targets)
  unset(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT _cmake_targets_defined STREQUAL "")
  string(REPLACE ";" ", " _cmake_targets_defined_text "${_cmake_targets_defined}")
  string(REPLACE ";" ", " _cmake_targets_not_defined_text "${_cmake_targets_not_defined}")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_cmake_targets_defined_text}\nTargets not yet defined: ${_cmake_targets_not_defined_text}\n")
endif()
unset(_cmake_targets_defined)
unset(_cmake_targets_not_defined)
unset(_cmake_expected_targets)


# Create imported target str_utils
add_library(str_utils STATIC IMPORTED)

if(WIN32)
    set(LIB_BASE_DIR E:/Users/ccoua/OneDrive/Devs/Projects/lib/str_utils)
    set(LIB_NAME str_utils.lib)
elseif(UNIX)
    set(LIB_BASE_DIR /home/ccoua/.vs/str_utils)
    set(LIB_NAME libstr_utils.a)
endif()

set(STR_UTILS_INCLUDE_DIRS "${LIB_BASE_DIR}/include")
set_target_properties(str_utils PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${LIB_BASE_DIR}/include"
)

# Import target "str_utils" for proper configuration
set_property(TARGET str_utils APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG RELEASE)
set_target_properties(str_utils PROPERTIES
IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
IMPORTED_LOCATION_DEBUG "${LIB_BASE_DIR}/lib/debug/${LIB_NAME}"
IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
IMPORTED_LOCATION_RELEASE "${LIB_BASE_DIR}/lib/release/${LIB_NAME}"
)

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
