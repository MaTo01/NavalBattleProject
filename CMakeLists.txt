cmake_minimum_required(VERSION 2.9)

project(NavalBattle LANGUAGES CXX)

include_directories(include)

add_executable(battaglia_navale
    src/NavalBattle.cpp
)

add_executable(replay
    src/NavalBattleReplay.cpp
)