# CMakeList.txt : projet CMake pour utils, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Activez Rechargement à chaud pour les compilateurs MSVC si cela est pris en charge.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

option(str-utils-static_BUILD_TESTS "Build tests" OFF)
if(str-utils-static_BUILD_TESTS)
	list(APPEND VCPKG_MANIFEST_FEATURES "tests")
	enable_testing()
endif()

project ("str-utils-static")

set(${PROJECT_NAME}_DEPENDENCIES "")

add_subdirectory(src)

if(${PROJECT_NAME}_BUILD_TESTS)
	add_subdirectory(tests)
endif()

#if (CMAKE_VERSION VERSION_GREATER 3.12)
#  set_property(TARGET utils PROPERTY CXX_STANDARD 20)
#endif()
