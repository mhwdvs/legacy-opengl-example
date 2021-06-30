cmake_minimum_required(VERSION 3.17)
# set the project name
set(PROJECT_NAME Main)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
project(${PROJECT_NAME} VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 11)

include(CTest)

# Build libs
add_subdirectory(lib)

# add associated directory for main executable
add_subdirectory(src)
# add associated directory for tests executable
add_subdirectory(test)

# add resources directory to copy files to binary dir
add_subdirectory(res)

# Set compile options
target_compile_options(${PROJECT_NAME} PRIVATE 
    # Clang and AppleClang
    $<$<AND:$<CXX_COMPILER_ID:Clang>,$<CONFIG:Debug>>: -v -Wall -Wextra -fsanitize=address,undefined,leak>
    $<$<AND:$<CXX_COMPILER_ID:Clang>,$<CONFIG:Release>>: -v -Wall -Wextra>

    # GNU GCC/G++
    $<$<AND:$<CXX_COMPILER_ID:GNU>,$<CONFIG:Debug>>: -Wall -Wextra -pedantic -fsanitize=address,leak>
    $<$<AND:$<CXX_COMPILER_ID:GNU>,$<CONFIG:Release>>: -Wall -Wextra -pedantic>

    # MSVC
    $<$<AND:$<CXX_COMPILER_ID:MSVC>,$<CONFIG:Debug>>: /W4 /fsanitize=address>
    $<$<AND:$<CXX_COMPILER_ID:MSVC>,$<CONFIG:Release>>: /W4>
)

target_link_options(${PROJECT_NAME} PRIVATE
    # Clang and AppleClang
    $<$<AND:$<CXX_COMPILER_ID:Clang>,$<CONFIG:Debug>>: -fsanitize=address,undefined,leak>

    # GNU GCC/G++
    $<$<AND:$<CXX_COMPILER_ID:GNU>,$<CONFIG:Debug>>: -fsanitize=address,leak>

    # GNU GCC/G++
    $<$<AND:$<CXX_COMPILER_ID:MSVC>,$<CONFIG:Debug>>: /INFERASANLIBS>
)
