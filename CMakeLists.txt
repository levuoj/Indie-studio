cmake_minimum_required(VERSION 3.5.1)
project(cpp_indie_studio)

include_directories(includes)

#Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)

set(CMAKE_CXX_FLAGS "-W -Wall -Werror -Wextra -g3")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ..)

# Sources directory:
set(CMAKE_SOURCES_DIRECTORY sources)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES ${CMAKE_SOURCES_DIRECTORY}/*.cpp)


add_executable(hyper-sprint ${SOURCES} sources/Game/Car.cpp includes/Car.hpp includes/PowerUp.hpp includes/Shoot.hpp includes/Banana.hpp includes/BoostSpeed.hpp)


