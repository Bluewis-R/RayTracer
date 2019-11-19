cmake_minimum_required(VERSION 2.6)
project(RAYTRACER)

include_directories(src)

add_library(RayTracer
    src/RayTracer/Bones.h
    src/RayTracer/Macros.h

    src/Raytracer/MCG_GFX_Lib.h
    src/Raytracer/MCG_GFX_Lib.cpp

    


)
add_executable(game
    src/game/main.cpp 
)

#target_link_libraries(rend glew32 opengl32)
target_link_libraries(RayTracer SDL2 glew32 opengl32)
target_link_libraries(game RayTracer)