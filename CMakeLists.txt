cmake_minimum_required(VERSION 3.5)
project(dbus-spotify-example)

find_package(Qt5 CONFIG REQUIRED
    Core
    DBus
    Quick
)

set(CMAKE_AUTOMOC ON)

qt5_add_dbus_interface(interface_FILES
    "MediaPlayer2.xml"
    mediaplayer2_interface
)

qt5_add_resources(QT_RESOURCES resources.qrc)

add_executable(dbus-spotify-example
    ${interface_FILES}
    main.cpp
    mediaplayer.cpp
    mediaplayer.h
    resources.qrc
    ${QT_RESOURCES}
)

target_include_directories(dbus-spotify-example
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(dbus-spotify-example
    Qt5::DBus
    Qt5::Qml
    Qt5::Quick
)
