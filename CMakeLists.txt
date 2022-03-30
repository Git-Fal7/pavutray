cmake_minimum_required (VERSION 2.8.12)
project (pavutray)

find_package (Qt5Widgets)

set (trayLib_src ${PROJECT_SOURCE_DIR}/mainwindow.cpp)
set (trayLib_hdr ${PROJECT_SOURCE_DIR}/mainwindow.h)
set (trayBin_src ${PROJECT_SOURCE_DIR}/main.cpp)

qt5_wrap_cpp(trayLib_hdr_moc ${trayLib_hdr})

include_directories (${PROJECT_SOURCE_DIR})
include_directories (${PROJECT_BINARY_DIR})

add_library (trayLib SHARED 
    ${trayLib_src}
    ${trayLib_hdr_moc}
)
target_link_libraries (traysLib Qt5::Widgets)

add_executable(pavutray ${trayBin_src})
target_link_libraries (pavutray trayLib)
