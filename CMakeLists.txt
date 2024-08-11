cmake_minimum_required(VERSION 3.28)
project(Machine_Room_Reservation_System)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS -static)
add_executable(Machine_Room_Reservation_System main.cpp manager.cpp student.cpp teacher.cpp
        orderFile.cpp)
