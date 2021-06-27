file(GLOB SOURCES CONFIGURE_DEPENDS "*.h" "*.cpp" 
                                    "datastructures/*.h" "datastructures/*.cpp" 
                                    "loaders/*.h" "loaders/*.cpp")

# Add executable
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
# Create library (needed to make code accessible to tests)
add_library(${CMAKE_PROJECT_NAME}_lib SHARED STATIC ${SOURCES})
# Link glad and glfw
target_link_libraries(${CMAKE_PROJECT_NAME} glad glfw)
target_link_libraries(${CMAKE_PROJECT_NAME}_lib glad glfw)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Output glad DLL to this dir
if(WIN32) #or CYGWIN) 
    set_target_properties(glad PROPERTIES
                          RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    )
endif()