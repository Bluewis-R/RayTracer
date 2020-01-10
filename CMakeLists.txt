cmake_minimum_required(VERSION 2.6)
project(RAYTRACER)

include_directories(src)

add_library(RayTracer
    src/RayTracer/RayTracer.h
    src/RayTracer/Macros.h

    src/Raytracer/MCG_GFX_Lib.h
    src/Raytracer/MCG_GFX_Lib.cpp

    src/Raytracer/Camera.h
    src/Raytracer/Ray.h
    src/Raytracer/Tracer.h
    src/Raytracer/Object.h    
    src/Raytracer/Sphere.h
    src/Raytracer/Light.h  
    src/Raytracer/LewisMaths.h
    src/Raytracer/Multithreading.h  

    src/Raytracer/Camera.cpp
    src/Raytracer/Ray.cpp
    src/Raytracer/Tracer.cpp
    src/Raytracer/Object.cpp    
    src/Raytracer/Sphere.cpp
    src/Raytracer/Light.cpp  
    src/Raytracer/LewisMaths.cpp
    src/Raytracer/Multithreading.cpp
)
add_executable(game
    src/game/main.cpp 
)

#target_link_libraries(rend glew32 opengl32)
target_link_libraries(RayTracer SDL2 glew32 opengl32)
target_link_libraries(game RayTracer)