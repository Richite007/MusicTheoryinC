cmake_minimum_required(VERSION 4.0)
project(MusicTheoryinC C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(MusicTheoryinC
        main.c
        src/chords.h
        src/chords.c)
