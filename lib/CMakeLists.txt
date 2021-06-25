# Build glad2
add_subdirectory(glad/cmake)
glad_add_library(glad SHARED API gl:core=4.5 LOCATION ${CMAKE_BINARY_DIR}/src)
execute_process(COMMAND  "pip install .") # install python requirements

# Build glfw
include_directories(${PROJECT_SOURCE_DIR}/glfw)
add_subdirectory(glfw)
