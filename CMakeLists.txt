cmake_minimum_required(VERSION 3.31)
project(opr_klausuren)

set(CMAKE_CXX_STANDARD 20)

add_executable(ss13-3_2 ss13/aufgabe3_2/main.cpp)
add_executable(ss13-3_3 ss13/aufgabe3_3/main.cpp)
add_executable(ss13-3_4 ss13/aufgabe3_4/main.cpp)

add_executable(ss16-2_2 ss16/aufgabe2_2/main.cpp ss18/aufgabe3_1/Komplex.h
        ss16/aufgabe2_2/Float.cpp
        ss16/aufgabe2_2/Float.h
        ss16/aufgabe2_2/Logger.h
        ss16/aufgabe2_2/LoggerImpl.h)

add_executable(ss18-3_1 ss18/aufgabe3_1/main.cpp
        ss18/aufgabe3_1/Komplex.h)
add_executable(ss18-3_2 ss18/aufgabe3_2/main.cpp)

add_executable(ss22-2_2 ss22/aufgabe2_2/main.cpp)
add_executable(ss22-3_1 ss22/aufgabe3_1/main.cpp)
add_executable(ss22-3_2 ss22/aufgabe3_2/main.cpp)