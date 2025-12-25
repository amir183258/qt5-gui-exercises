cmake_minimum_required(VERSION 3.10)

project(MyQmlApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt5 REQUIRED COMPONENTS Quick)

qt5_add_resources(RESOURCE_FILES resources.qrc)

add_executable(MyQmlApp
    main.cpp
    ${RESOURCE_FILES}
)


target_link_libraries(MyQmlApp PRIVATE Qt5::Quick)

set_target_properties(MyQmlApp PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
)
