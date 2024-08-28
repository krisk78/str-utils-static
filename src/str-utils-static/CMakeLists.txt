set(${PROJECT_NAME}_LINK_LIBS "")
set(${PROJECT_NAME}_INCLUDE_DIRS "include/${PROJECT_NAME}")

foreach(_DEP_LIB ${${PROJECT_NAME}_DEPENDENCIES})
#	find_package(${_DEP_LIB} REQUIRED HINTS $ENV{MY_CXX_LIBS_BASE_DIR}/${_DEP_LIB}/cmake)
	find_package(${_DEP_LIB} REQUIRED)
    list(APPEND ${PROJECT_NAME}_LINK_LIBS ${_DEP_LIB})
	#string(TOUPPER ${_DEP_LIB} ${PROJECT_NAME}_DEP_LIB_UP)
	#list(APPEND ${PROJECT_NAME}_INCLUDE_DIRS ${${_DEP_LIB}_INCLUDE_DIRS})
endforeach()

add_library(${PROJECT_NAME} STATIC "include/${PROJECT_NAME}/${PROJECT_NAME}.hpp" "${PROJECT_NAME}.cpp")

target_link_libraries(${PROJECT_NAME} PRIVATE ${${PROJECT_NAME}_LINK_LIBS})

target_include_directories(${PROJECT_NAME} PUBLIC ${${PROJECT_NAME}_INCLUDE_DIRS})

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "include/${PROJECT_NAME}/${PROJECT_NAME}.hpp")

install(TARGETS ${PROJECT_NAME} PUBLIC_HEADER DESTINATION ${CMAKE_SOURCE_DIR}/include ARCHIVE DESTINATION ${CMAKE_SOURCE_DIR}/lib/$<CONFIG>)

# Retrieve Windows lib folder location to copy library file after install
if (UNIX AND DEFINED ENV{WSL_COPY_LIB_TO_WIN} AND "$ENV{WSL_COPY_LIB_TO_WIN}" STREQUAL "1")

    # Retrieve the environment variable from Windows
    execute_process(COMMAND /mnt/c/Windows/System32/cmd.exe /c echo %MY_CXX_LIBS_BASE_DIR%
                    OUTPUT_VARIABLE MY_CXX_LIBS_BASE_DIR_WIN
                    OUTPUT_STRIP_TRAILING_WHITESPACE)

    # Extract the drive letter and convert it to lowercase
    string(SUBSTRING ${MY_CXX_LIBS_BASE_DIR_WIN} 0 1 _DRIVE_LETTER)
    string(TOLOWER ${_DRIVE_LETTER} _DRIVE_LETTER_LOWER)

    # Replace the drive letter with the corresponding WSL path
    string(REPLACE "${_DRIVE_LETTER}:" "/mnt/${_DRIVE_LETTER_LOWER}" MY_CXX_LIBS_BASE_DIR_WIN ${MY_CXX_LIBS_BASE_DIR_WIN})
    string(REPLACE "\\" "/" MY_CXX_LIBS_BASE_DIR_WIN ${MY_CXX_LIBS_BASE_DIR_WIN})

    install(TARGETS ${PROJECT_NAME} PUBLIC_HEADER DESTINATION ${CMAKE_SOURCE_DIR}/include ARCHIVE DESTINATION ${MY_CXX_LIBS_BASE_DIR_WIN}/${PROJECT_NAME}/lib/$<CONFIG>)

endif()

#install(EXPORT ${PROJECT_NAME}Config FILE ${PROJECT_NAME}Config.cmake DESTINATION cmake)
