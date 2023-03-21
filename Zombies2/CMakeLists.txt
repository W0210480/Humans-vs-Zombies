cmake_minimum_required(VERSION 3.23)
project(Zombies2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Zombies2 main.cpp Organism.cpp City.cpp Human.cpp Zombie.cpp)
