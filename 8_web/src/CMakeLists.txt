cmake_minimum_required(VERSION 3.10)
project(QtUIResourceExample)

set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 17)


find_package(Qt5 COMPONENTS Widgets Sql Core Gui Charts WebEngine WebEngineWidgets REQUIRED)

set(UI_FILES
    mainwindow.ui
)

qt5_wrap_ui(UI_HEADERS ${UI_FILES})


set(RESOURCE_FILES
    resources.qrc
)

qt5_add_resources(RESOURCE_SOURCES ${RESOURCE_FILES})

set(SOURCES
    main.cpp
    mainwindow.cpp
    ${UI_HEADERS}
    ${RESOURCE_SOURCES}
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Sql Qt5::Core Qt5::Gui Qt5::Charts Qt5::WebEngine Qt5::WebEngineWidgets)
