cmake_minimum_required(VERSION 2.8.9)
PROJECT(testing)


include_directories(../src/DB)

#Packages
find_package(PkgConfig)
find_package (Threads)
pkg_check_modules(LIBBSONXX REQUIRED libbsoncxx)
pkg_check_modules(LIBMONGOCXX REQUIRED libmongocxx)
pkg_check_modules(LIBMONGOC REQUIRED libmongoc-1.0)

include_directories(${LIBMONGOCXX_INCLUDE_DIRS} ${LIBBSONCXX_INCLUDE_DIRS} ${LIBMONGOC_INCLUDE_DIRS})
link_directories(${LIBMONGOCXX_LIBRARY_DIRS} ${LIBBSONCXX_LIBRARY_DIRS} ${LIBMONGOC_LIBRARY_DIRS}) 

file(GLOB SOURCES ../src/DB/*.cpp test.cpp )


SET(CMAKE_CXX_FLAGS "-g -std=c++11 -O0 -Wall -fprofile-arcs -ftest-coverage --coverage")
SET(CMAKE_C_FLAGS "-g -O0 -Wall -W -fprofile-arcs -ftest-coverage --coverage")
SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage --coverage")

# Generar el ejecutable
add_executable (${PROJECT_NAME} ${SOURCES})


# Linkear contra bibliotecas
target_link_libraries (${PROJECT_NAME} gtest_main)
target_link_libraries (${PROJECT_NAME} gtest)

target_link_libraries(${PROJECT_NAME} ${LIBMONGOCXX_LIBRARIES} ${LIBBSONCXX_LIBRARIES} ${LIBMONGOC_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} ${CMAKE_DL_LIBS})

