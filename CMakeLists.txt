cmake_minimum_required(VERSION 2.6)
project(RAY)


add_library(RayTracer
    src/RayTracer/Macros.h
)


target_link_libraries(RayTracer SDL2 opengl32 glew32)

add_executable(game
    src/game/main.cpp 
)

target_link_libraries(game RayTracer)