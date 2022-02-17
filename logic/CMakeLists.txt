cmake_minimum_required(VERSION 3.5)

project(logic VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES_LOGIC_LIB
    api/daydata.h
    src/daydata.cpp
    api/timeregister.h
    src/timeregister.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_library(logic STATIC
      ${PROJECT_SOURCES_LOGIC_LIB}
    )
else()
    add_library(logic STATIC
          ${PROJECT_SOURCES_LOGIC_LIB}
        )
endif()

target_link_libraries(logic PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_include_directories(logic PUBLIC api)
