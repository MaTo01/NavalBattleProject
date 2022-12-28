cmake_minimum_required(VERSION 2.9)

project(NavalBattle LANGUAGES CXX)

include_directories(include)

add_library(${PROJECT_NAME}
    src/AttackGrid.cpp
    src/Battleship.cpp
    src/DefenseGrid.cpp
    src/Submarine.cpp
    src/SupportShip.cpp
)

add_executable(main
    src/main.cpp
)

target_link_libraries(main ${PROJECT_NAME})