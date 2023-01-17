cmake_minimum_required(VERSION 2.9)

project(NavalBattle LANGUAGES CXX)

include_directories(include)

add_executable(battaglia_navale
    src/NavalBattle.cpp
)

add_executable(replay
    src/NavalBattleReplay.cpp
)

set_source_files_properties(
    src/NavalBattle.cpp
    src/NavalBattleReplay.cpp
    PROPERTIES
        COMPILE_OPTIONS "-O2"
)
