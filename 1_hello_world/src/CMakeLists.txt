cmake_minimum_required(VERSION 3.5)
project(MyApp)

set(CMAKE_CXX_STANDARD 11)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(SOURCES main.cpp)
set(HEADERS ui_main_window.h)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

