cmake_minimum_required(VERSION 2.8)
link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})
project( LittleBrother )
find_package( OpenCV REQUIRED )

find_package( PkgConfig REQUIRED )
pkg_check_modules(GTKMM REQUIRED gtkmm-2.4)

set(THREADS_PREFER_PTHREAD_FLAG_ON)
find_package(Threads REQUIRED)

add_executable(LittleBrother main.cpp lbwindow.cpp lbwindow.h feed.cpp feed.h)
target_link_libraries(LittleBrother ${OpenCV_LIBS} ${GTKMM_LIBRARIES} Threads::Threads opencv_core opencv_imgproc opencv_highgui opencv_videoio opencv_imgcodecs)
