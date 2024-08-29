set(${PROJECT_NAME}_LINK_LIBS "")
set(${PROJECT_NAME}_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include")

foreach(_DEP_LIB ${${PROJECT_NAME}_DEPENDENCIES})
    find_package(${_DEP_LIB} REQUIRED)
    list(APPEND ${PROJECT_NAME}_LINK_LIBS ${_DEP_LIB})
endforeach()

add_library(${PROJECT_NAME} STATIC "${PROJECT_NAME}.cpp")

target_link_libraries(${PROJECT_NAME} PRIVATE ${${PROJECT_NAME}_LINK_LIBS})

target_include_directories(${PROJECT_NAME} 
    PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "include/${PROJECT_NAME}/${PROJECT_NAME}.hpp")

install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}_targets
    PUBLIC_HEADER DESTINATION include
    ARCHIVE DESTINATION lib/$<CONFIG>)

# Generate and install *-targets.cmake
install(EXPORT ${PROJECT_NAME}_targets FILE ${PROJECT_NAME}-targets.cmake NAMESPACE ${PROJECT_NAME}:: DESTINATION share/${PROJECT_NAME})

# Generate the config file
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake"
    "include(CMakeFindDependencyMacro)\n"
    "find_dependency(${${PROJECT_NAME}_DEPENDENCIES} CONFIG REQUIRED)\n"
    "include(\"\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}-targets.cmake\")\n"
)

# Install the generated config file
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake" DESTINATION share/${PROJECT_NAME})
