cmake_minimum_required(VERSION 2.6)

project(game)

file(GLOB SRCS *.cpp)
file(GLOB HDRS *.h)

include_directories ("/usr/include/ImageMagick/")

#add_subdirectory("src")

add_executable(app ${SRCS})

TARGET_LINK_LIBRARIES(app -lX11 -lXi -lglut -lGL -lGLU -lm -lGLEW -lMagick++)

