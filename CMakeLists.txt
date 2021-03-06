cmake_minimum_required(VERSION 2.8.9)
project (music.io)

#Set standard
set(CMAKE_CXX_STANDARD 11)

#Bring the headers into the project
include_directories(src src/plog src/DB src/restserver src/utils)

#Packages
find_package(PkgConfig)
find_package (Threads)
pkg_check_modules(LIBBSONXX REQUIRED libbsoncxx)
pkg_check_modules(LIBMONGOCXX REQUIRED libmongocxx)
pkg_check_modules(LIBMONGOC REQUIRED libmongoc-1.0)

include_directories(${LIBMONGOCXX_INCLUDE_DIRS} ${LIBBSONCXX_INCLUDE_DIRS} ${LIBMONGOC_INCLUDE_DIRS})
link_directories(${LIBMONGOCXX_LIBRARY_DIRS} ${LIBBSONCXX_LIBRARY_DIRS} ${LIBMONGOC_LIBRARY_DIRS}) 

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp" src/DB/*.cpp src/restserver/*.c src/restserver/*.cpp src/utils/*.cpp)

add_executable(serverapp ${SOURCES})

target_link_libraries(serverapp ${LIBMONGOCXX_LIBRARIES} ${LIBBSONCXX_LIBRARIES} ${LIBMONGOC_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} ${CMAKE_DL_LIBS})
