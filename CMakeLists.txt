cmake_minimum_required(VERSION 2.9)

project(NavalBattle LANGUAGES CXX)

include_directories(include)

add_executable(NavalBattle
    src/NavalBattle.cpp
)

add_executable(NavalBattleReplay
    src/NavalBattleReplay.cpp
)