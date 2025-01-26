cmake_minimum_required(VERSION 3.31.0)

project(Starship)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/Main.cpp ${CMAKE_SOURCE_DIR}/src/Game.cpp)
add_subdirectory(${CMAKE_SOURCE_DIR}/external/sfml)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/external/sfml/include)
target_link_directories(${PROJECT_NAME} PRIVATE /external/sfm/lib)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-network sfml-graphics sfml-audio sfml-main)
else()
    target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-network sfml-graphics sfml-audio)
endif()
