cmake_minimum_required(VERSION 3.26)
project(Asteroid)

set(CMAKE_CXX_STANDARD 17)

add_executable(Asteroid main.cpp
        Game.cpp
        Game.h
        Vector.cpp
        Vector.h
        GameObject.cpp
        GameObject.h
        TextureManager.cpp
        TextureManager.h
)

find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE
        $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>)
