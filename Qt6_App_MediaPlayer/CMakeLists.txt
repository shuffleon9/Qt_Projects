cmake_minimum_required(VERSION 3.16)

project(Qt6_App_MediaPlayer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Multimedia)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appQt6_App_MediaPlayer
    main.cpp
    PlayerController.h PlayerController.cpp
)

qt_add_qml_module(appQt6_App_MediaPlayer
    URI Qt6_App_MediaPlayer
    VERSION 1.0
    QML_FILES Main.qml AudioInfoBox.qml ImageButton.qml

    SOURCES
    AudioInfo.cpp AudioInfo.h

    RESOURCES
        assets/images/song_1.jpg
        assets/images/song_2.jpg
        assets/images/song_3.jpg

        assets/icons/app_icon.ico
        assets/icons/next_icon.png
        assets/icons/previous_icon.png
        assets/icons/play_icon.png
        assets/icons/pause_icon.png

        assets/videos/video_1.avi

        assets/audio/AnothersArmsRingtone.m4a
        assets/audio/AuRevoirRingtone.m4a
        assets/audio/BurningBridgesRingtone.m4a
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appQt6_App_MediaPlayer PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appQt6_App_MediaPlayer
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appQt6_App_MediaPlayer
    PRIVATE Qt6::Quick Qt6::Multimedia
)

include(GNUInstallDirs)
install(TARGETS appQt6_App_MediaPlayer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
