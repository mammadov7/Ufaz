cmake_minimum_required(VERSION 3.5)

project(pw1 LANGUAGES C)
 
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wextra -g ")

# bring the headers into project
include_directories("include")

# add source files with wildcard
add_executable(main "")
target_sources(main PUBLIC src/main.c src/header.c )

#adding -lm 
target_link_libraries(main PUBLIC m cunit)

add_executable(testing "")
target_sources(testing PUBLIC src/testmain.c src/header.c )
target_compile_options(testing PUBLIC)
enable_testing()
add_test(Test1 testing)


#adding -lm 
#target_link_libraries(test PUBLIC m cunit)

