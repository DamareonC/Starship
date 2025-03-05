cmake_minimum_required(VERSION 3.27.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Starship LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(${PROJECT_NAME}
    ${CMAKE_SOURCE_DIR}/src/Asteroid.cpp
    ${CMAKE_SOURCE_DIR}/src/Bullet.cpp
    ${CMAKE_SOURCE_DIR}/src/Game.cpp
    ${CMAKE_SOURCE_DIR}/src/GameOver.cpp
    ${CMAKE_SOURCE_DIR}/src/Main.cpp
    ${CMAKE_SOURCE_DIR}/src/Missle.cpp
    ${CMAKE_SOURCE_DIR}/src/Ship.cpp
    ${CMAKE_SOURCE_DIR}/src/StartMenu.cpp
    ${CMAKE_SOURCE_DIR}/src/Spawner.cpp
)

set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_link_libraries(${PROJECT_NAME} PRIVATE SFML::System SFML::Window SFML::Graphics SFML::Audio SFML::Main)
else()
    target_link_libraries(${PROJECT_NAME} PRIVATE SFML::System SFML::Window SFML::Graphics SFML::Audio)
endif()
