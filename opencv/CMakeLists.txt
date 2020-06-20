cmake_minimum_required(VERSION 3.1.0)
link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})
project( LittleBrother )
find_package( OpenCV 4 REQUIRED )

find_package( PkgConfig REQUIRED )
pkg_check_modules(GTKMM REQUIRED gtkmm-2.4)


add_executable(LittleBrother
    main.cpp
    lbwindow.cpp
    lbwindow.h
    feed.cpp
    feed.h)
target_link_libraries(LittleBrother ${OpenCV_LIBS} ${GTKMM_LIBRARIES} opencv_core opencv_imgproc opencv_highgui opencv_videoio opencv_imgcodecs)
