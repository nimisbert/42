cmake_minimum_required(VERSION 3.22.1)

# TODO :
# Chapitre 5 main_cll a debug

project( algorithm_in_C )

include_directories( include ${catkin_INCLUDE_DIRS} )

file( GLOB_RECURSE algorithm_in_C_HEADERS include/*.h )
file( GLOB_RECURSE algorithm_in_C_SOURCES src/*.c )

add_library(
    calgo SHARED
    src/sll.c
    src/dll.c
    src/cll.c
)

#Chapitre 2 : Manipulation de pointeur
add_executable(main_ptr src/main_ptr.c)

#Chapitre 3 : Recursions
add_executable(main_rec src/main_rec.c)

#Chapitre 5 :
## Listes simplements chainees 
add_executable(main_sll src/main_sll.c)
target_link_libraries(main_sll calgo)
add_dependencies(main_sll calgo)
## Listes circulaires simplement chainees
add_executable(main_cll src/main_cll.c)
target_link_libraries(main_cll calgo)
add_dependencies(main_cll calgo)