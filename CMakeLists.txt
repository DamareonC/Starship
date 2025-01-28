cmake_minimum_required(VERSION 3.31.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Starship)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(${PROJECT_NAME}
    ${CMAKE_SOURCE_DIR}/src/Bullet.cpp
    ${CMAKE_SOURCE_DIR}/src/Game.cpp
    ${CMAKE_SOURCE_DIR}/src/Main.cpp
    ${CMAKE_SOURCE_DIR}/src/Ship.cpp
)

add_subdirectory(${CMAKE_SOURCE_DIR}/external/SFML)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/external/SFML/include)
target_link_directories(${PROJECT_NAME} PRIVATE /external/SFML/lib)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_link_libraries(${PROJECT_NAME} SFML::System SFML::Window SFML::Graphics SFML::Audio SFML::Main)
else()
    target_link_libraries(${PROJECT_NAME} SFML::System SFML::Window SFML::Graphics SFML::Audio)
endif()
