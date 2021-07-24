set(SOURCES "main.cpp" 
            "glFuncs.h" 
            "scene.h"
            "object.cpp" "object.h"
            "window.cpp" "window.h"
            "camera.cpp" "camera.h")
add_subdirectory(loaders)
add_subdirectory(scenes)

# Add executable
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
# Create library (needed to make code accessible to tests)
add_library(${CMAKE_PROJECT_NAME}_lib SHARED STATIC ${SOURCES})
# Link glad and glfw
target_link_libraries(${CMAKE_PROJECT_NAME} glad glfw glm)
target_link_libraries(${CMAKE_PROJECT_NAME}_lib glad glfw glm)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Output glad lib to this dir
set_target_properties(glad PROPERTIES
                        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
