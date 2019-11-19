cmake_minimum_required(VERSION 2.6)
project(BONES)

include_directories(src)

add_library(Bones
    src/Bones/Bones.h
    src/Bones/Macros.h

    


)

add_library(rend
  src/rend/Exception.cpp
  src/rend/Context.cpp
  src/rend/Texture.cpp
  src/rend/RenderTexture.cpp
  src/rend/Shader.cpp
  src/rend/Buffer.cpp
  src/rend/Mesh.cpp
  src/rend/Util.cpp
)

add_executable(game
    src/game/main.cpp 
)

#target_link_libraries(rend glew32 opengl32)
target_link_libraries(Bones SDL2 rend)
target_link_libraries(game Bones)