cmake_minimum_required(VERSION 3.26)
project(FiveStar)

set(CMAKE_CXX_STANDARD 14)

add_executable(FiveStar main.cpp
        TitleInfo.cpp
        TitleInfo.h
        BookData.cpp
        BookData.h
        Sale.cpp
        Sale.h
        Report.cpp
        Report.h
        Management.cpp
        Management.h
        globals.h
        menu.cpp
)
