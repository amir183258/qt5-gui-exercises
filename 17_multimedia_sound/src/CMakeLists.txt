cmake_minimum_required(VERSION 3.10)
project(QtUIResourceExample)

set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_DEBUG "-g")

find_package(Qt5 COMPONENTS Core Gui Widgets Multimedia MultimediaWidgets REQUIRED)

set(UI_FILES
    mainwindow.ui
)

qt5_wrap_ui(UI_HEADERS ${UI_FILES})


#set(RESOURCE_FILES
#    resources.qrc
#)

#qt5_add_resources(RESOURCE_SOURCES ${RESOURCE_FILES})

set(SOURCES
    main.cpp
    mainwindow.cpp
    ${UI_HEADERS}
    ${RESOURCE_SOURCES}
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Multimedia Qt5::MultimediaWidgets)
