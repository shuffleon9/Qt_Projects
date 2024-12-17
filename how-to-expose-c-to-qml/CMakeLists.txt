cmake_minimum_required(VERSION 3.16)

project(qml-cpp-example VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(appqml-cpp-example
    main.cpp
)

qt_add_qml_module(appqml-cpp-example
    URI QmlCppExample
    VERSION 1.0
    QML_FILES main.qml 
    RESOURCES assets/circular-saw.gif assets/built-with-qt-badge.png
)

set_target_properties(appqml-cpp-example PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appqml-cpp-example
    PRIVATE Qt6::Quick)

install(TARGETS appqml-cpp-example
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
