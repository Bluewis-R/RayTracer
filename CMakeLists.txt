cmake_minimum_required(VERSION 2.6)
project(RayTracer)

include_directories(src)

add_library(RayTracer
    src/RayTracer/Macros.h
)

add_executable(game
    src/game/main.cpp 
)

#target_link_libraries(rend glew32 opengl32)
target_link_libraries(RayTracer SDL2 glew32 opengl32)
target_link_libraries(game RayTracer)