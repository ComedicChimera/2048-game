cmake_minimum_required(
    VERSION 3.20.0
)

project(2048)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SRC/")
set(SRCS "main.cpp" "renderer.cpp" "draw.cpp" "logic.cpp" "animate.cpp" "input.cpp")
list(TRANSFORM SRCS PREPEND ${SRC_DIR})

add_executable(${PROJECT_NAME} ${SRCS})

target_include_directories(${PROJECT_NAME} PRIVATE "D:/DevTools/sdl2-2.26.4/include")
target_link_directories(${PROJECT_NAME} PRIVATE "D:/DevTools/sdl2-2.26.4/lib/x64")
target_link_libraries(${PROJECT_NAME} PRIVATE "SDL2.lib" "SDL2main.lib")

target_include_directories(${PROJECT_NAME} PRIVATE "D:/DevTools/sdl2_ttf-2.20.2/include")
target_link_directories(${PROJECT_NAME} PRIVATE "D:/DevTools/sdl2_ttf-2.20.2/lib/x64")
target_link_libraries(${PROJECT_NAME} PRIVATE "SDL2_ttf.lib")