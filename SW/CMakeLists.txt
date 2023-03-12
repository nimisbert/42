cmake_minimum_required(VERSION 3.22.1)

# TODO :
# Chapitre 5 main_cll a debug

project( algorithm_in_C )

include_directories( include ${catkin_INCLUDE_DIRS} )

file( GLOB_RECURSE algorithm_in_C_HEADERS include/*.h )
file( GLOB_RECURSE algorithm_in_C_SOURCES src/*.c )
file( GLOB_RECURSE algorithm_in_C_EXAMPLE examples/*.c)

add_library(
    calgo SHARED
    src/sll.c
    src/dll.c
    src/cll.c
    src/stack.c
)

#Chapitre 2 : Manipulation de pointeur
add_executable(main_ptr examples/main_ptr.c)

#Chapitre 3 : Recursions
add_executable(main_rec examples/main_rec.c)

#Chapitre 5 :
## Listes simplements chainees 
add_executable(main_sll examples/main_sll.c)
target_link_libraries(main_sll calgo)
add_dependencies(main_sll calgo)
## Listes circulaires simplement chainees
add_executable(main_cll examples/main_cll.c)
target_link_libraries(main_cll calgo)
add_dependencies(main_cll calgo)

#Chapitre 6 : 
## Piles (LIFO)
add_executable(main_stack examples/main_stack.c)
target_link_libraries(main_stack calgo)
add_dependencies(main_stack calgo)
## Files (FIFO)