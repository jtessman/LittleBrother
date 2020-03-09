cmake_minimum_required(VERSION 2.8)
link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})
project( LittleBrother )
find_package( OpenCV REQUIRED )

find_package( PkgConfig REQUIRED )
pkg_check_modules(GTKMM REQUIRED gtkmm-2.4)

add_executable(LittleBrother LittleBrother.cpp lbwindow.cpp lbwindow.h)
target_link_libraries(LittleBrother ${OpenCV_LIBS} ${GTKMM_LIBRARIES}  opencv_core opencv_imgproc opencv_highgui opencv_videoio opencv_imgcodecs)
