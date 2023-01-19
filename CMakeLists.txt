cmake_minimum_required(VERSION 2.9)
project(NavalBattle LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

# Add include directory to the build
include_directories(include)

# Add executable targets to the project
add_executable(battaglia_navale src/NavalBattle.cpp)
add_executable(replay src/NavalBattleReplay.cpp)

# Set compile options for all source files
set_source_files_properties(
    src/NavalBattle.cpp
    src/NavalBattleReplay.cpp
    PROPERTIES
        COMPILE_OPTIONS "-O2"
)
