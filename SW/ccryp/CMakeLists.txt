cmake_minimum_required(VERSION 3.22.1)
project( ccrypt )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lm")

include_directories( include ${catkin_INCLUDE_DIRS} )

file( GLOB_RECURSE JollietInnovation_C_HEADERS include/*.h )
file( GLOB_RECURSE JollietInnovation_C_SOURCES src/*.c)
file( GLOB_RECURSE JollietInnovation_C_EXAMPLE examples/*.c)

add_library(
    ccrypt SHARED
    src/polybius.c
    src/scytale.c
)

add_executable(caesar_main examples/caesar_main.c)
target_link_libraries( caesar_main ccrypt)
add_dependencies( caesar_main ccrypt)

add_executable(scytale_main examples/scytale_main.c)
target_link_libraries( scytale_main ccrypt)
add_dependencies( scytale_main ccrypt)
