# add the executable
file(GLOB SOURCES CONFIGURE_DEPENDS "*.h" "*.cpp")
file(GLOB DATA_FILES CONFIGURE_DEPENDS "*.txt" "*.csv")
file(COPY ${DATA_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(GLOB IMAGES CONFIGURE_DEPENDS "img/*.bmp")
file(COPY ${IMAGES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/img)

# Add executable
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
# Create library (needed to make code accessible to tests)
add_library(${CMAKE_PROJECT_NAME}_lib SHARED STATIC ${SOURCES})
# Link SDL
target_link_libraries(${CMAKE_PROJECT_NAME} glad glfw)
target_link_libraries(${CMAKE_PROJECT_NAME}_lib glad glfw)

# Output glad DLL to this dir
if(WIN32) #or CYGWIN) 
    set_target_properties(glad PROPERTIES
                          RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )
endif()