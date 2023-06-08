cmake_minimum_required(VERSION 3.24)
project(Version_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Version_2
        Board.cpp
        Classes.hpp
        ComputerPlayer.cpp
        GameManager.cpp
        Main.cpp
        Player.cpp)
