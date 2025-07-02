cmake_minimum_required(VERSION 3.31)
project(opr_klausuren)

set(CMAKE_CXX_STANDARD 20)

add_executable(ws11_12-2 ws11_12/aufgabe2/main.cpp)


add_executable(ss13-3_2 ss13/aufgabe3_2/main.cpp)
add_executable(ss13-3_3 ss13/aufgabe3_3/main.cpp)
add_executable(ss13-3_4 ss13/aufgabe3_4/main.cpp)

#add_executable(ss14-2 ss14/aufgabe2/main.cpp)

add_executable(ss16-2_2 ss16/aufgabe2_2/main.cpp ss18/aufgabe3_1/Komplex.h
        ss16/aufgabe2_2/Float.cpp
        ss16/aufgabe2_2/Float.h
        ss16/aufgabe2_2/Logger.h
        ss16/aufgabe2_2/LoggerImpl.h)

add_executable(ss17-3 ss17/aufgabe3/A.h
        ss17/aufgabe3/B.h
        ss17/aufgabe3/main.cpp)

add_executable(ss17-4_2 ss17/aufgabe4_2/Koerper.h
        ss17/aufgabe4_2/Koerper2D.h
        ss17/aufgabe4_2/Koerper3D.h
        ss17/aufgabe4_2/Rechteck.h
        ss17/aufgabe4_2/Wuerfel.h
        ss17/aufgabe4_2/main.cpp
)
add_executable(ss18-2_3 ss18/aufgabe2_3/main.cpp)
add_executable(ss18-3_1 ss18/aufgabe3_1/main.cpp
        ss18/aufgabe3_1/Komplex.h)
add_executable(ss18-3_2 ss18/aufgabe3_2/main.cpp)
add_executable(ss18-3_3 ss18/aufgabe3_3/main.cpp)

add_executable(ss19-2_1 ss19/aufgabe2_1/main.cpp)
add_executable(ss19-2_2 ss19/aufgabe2_2/main.cpp)
add_executable(ss19-2_3 ss19/aufgabe2_3/main.cpp)
add_executable(ss19-2_4 ss19/aufgabe2_4/main.cpp)
add_executable(ss19-3_1 ss19/aufgabe3_1/main.cpp)
add_executable(ss19-3_2 ss19/aufgabe3_2/main.cpp)


add_executable(ss22-2_1 ss22/aufgabe2_1/main.cpp)
add_executable(ss22-2_2 ss22/aufgabe2_2/main.cpp)
add_executable(ss22-2_3 ss22/aufgabe2_3/main.cpp)
add_executable(ss22-2_4 ss22/aufgabe2_4/main.cpp)
add_executable(ss22-3_1 ss22/aufgabe3_1/main.cpp)
add_executable(ss22-3_2 ss22/aufgabe3_2/main.cpp)

add_executable(sandbox sandbox/main.cpp)
