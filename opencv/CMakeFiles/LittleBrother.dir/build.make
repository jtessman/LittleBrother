# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kobi/Desktop/LittleBrother/opencv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kobi/Desktop/LittleBrother/opencv

# Include any dependencies generated for this target.
include CMakeFiles/LittleBrother.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LittleBrother.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LittleBrother.dir/flags.make

CMakeFiles/LittleBrother.dir/main.cpp.o: CMakeFiles/LittleBrother.dir/flags.make
CMakeFiles/LittleBrother.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kobi/Desktop/LittleBrother/opencv/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LittleBrother.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LittleBrother.dir/main.cpp.o -c /home/kobi/Desktop/LittleBrother/opencv/main.cpp

CMakeFiles/LittleBrother.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LittleBrother.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kobi/Desktop/LittleBrother/opencv/main.cpp > CMakeFiles/LittleBrother.dir/main.cpp.i

CMakeFiles/LittleBrother.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LittleBrother.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kobi/Desktop/LittleBrother/opencv/main.cpp -o CMakeFiles/LittleBrother.dir/main.cpp.s

CMakeFiles/LittleBrother.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/LittleBrother.dir/main.cpp.o.requires

CMakeFiles/LittleBrother.dir/main.cpp.o.provides: CMakeFiles/LittleBrother.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/LittleBrother.dir/build.make CMakeFiles/LittleBrother.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/LittleBrother.dir/main.cpp.o.provides

CMakeFiles/LittleBrother.dir/main.cpp.o.provides.build: CMakeFiles/LittleBrother.dir/main.cpp.o


CMakeFiles/LittleBrother.dir/lbwindow.cpp.o: CMakeFiles/LittleBrother.dir/flags.make
CMakeFiles/LittleBrother.dir/lbwindow.cpp.o: lbwindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kobi/Desktop/LittleBrother/opencv/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/LittleBrother.dir/lbwindow.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LittleBrother.dir/lbwindow.cpp.o -c /home/kobi/Desktop/LittleBrother/opencv/lbwindow.cpp

CMakeFiles/LittleBrother.dir/lbwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LittleBrother.dir/lbwindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kobi/Desktop/LittleBrother/opencv/lbwindow.cpp > CMakeFiles/LittleBrother.dir/lbwindow.cpp.i

CMakeFiles/LittleBrother.dir/lbwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LittleBrother.dir/lbwindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kobi/Desktop/LittleBrother/opencv/lbwindow.cpp -o CMakeFiles/LittleBrother.dir/lbwindow.cpp.s

CMakeFiles/LittleBrother.dir/lbwindow.cpp.o.requires:

.PHONY : CMakeFiles/LittleBrother.dir/lbwindow.cpp.o.requires

CMakeFiles/LittleBrother.dir/lbwindow.cpp.o.provides: CMakeFiles/LittleBrother.dir/lbwindow.cpp.o.requires
	$(MAKE) -f CMakeFiles/LittleBrother.dir/build.make CMakeFiles/LittleBrother.dir/lbwindow.cpp.o.provides.build
.PHONY : CMakeFiles/LittleBrother.dir/lbwindow.cpp.o.provides

CMakeFiles/LittleBrother.dir/lbwindow.cpp.o.provides.build: CMakeFiles/LittleBrother.dir/lbwindow.cpp.o


CMakeFiles/LittleBrother.dir/feed.cpp.o: CMakeFiles/LittleBrother.dir/flags.make
CMakeFiles/LittleBrother.dir/feed.cpp.o: feed.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kobi/Desktop/LittleBrother/opencv/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/LittleBrother.dir/feed.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LittleBrother.dir/feed.cpp.o -c /home/kobi/Desktop/LittleBrother/opencv/feed.cpp

CMakeFiles/LittleBrother.dir/feed.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LittleBrother.dir/feed.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kobi/Desktop/LittleBrother/opencv/feed.cpp > CMakeFiles/LittleBrother.dir/feed.cpp.i

CMakeFiles/LittleBrother.dir/feed.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LittleBrother.dir/feed.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kobi/Desktop/LittleBrother/opencv/feed.cpp -o CMakeFiles/LittleBrother.dir/feed.cpp.s

CMakeFiles/LittleBrother.dir/feed.cpp.o.requires:

.PHONY : CMakeFiles/LittleBrother.dir/feed.cpp.o.requires

CMakeFiles/LittleBrother.dir/feed.cpp.o.provides: CMakeFiles/LittleBrother.dir/feed.cpp.o.requires
	$(MAKE) -f CMakeFiles/LittleBrother.dir/build.make CMakeFiles/LittleBrother.dir/feed.cpp.o.provides.build
.PHONY : CMakeFiles/LittleBrother.dir/feed.cpp.o.provides

CMakeFiles/LittleBrother.dir/feed.cpp.o.provides.build: CMakeFiles/LittleBrother.dir/feed.cpp.o


# Object files for target LittleBrother
LittleBrother_OBJECTS = \
"CMakeFiles/LittleBrother.dir/main.cpp.o" \
"CMakeFiles/LittleBrother.dir/lbwindow.cpp.o" \
"CMakeFiles/LittleBrother.dir/feed.cpp.o"

# External object files for target LittleBrother
LittleBrother_EXTERNAL_OBJECTS =

LittleBrother: CMakeFiles/LittleBrother.dir/main.cpp.o
LittleBrother: CMakeFiles/LittleBrother.dir/lbwindow.cpp.o
LittleBrother: CMakeFiles/LittleBrother.dir/feed.cpp.o
LittleBrother: CMakeFiles/LittleBrother.dir/build.make
LittleBrother: /home/kobi/Desktop/opencv-4.3.0/build/lib/libopencv_dnn.so.4.3.0
LittleBrother: /home/kobi/Desktop/opencv-4.3.0/build/lib/libopencv_gapi.so.4.3.0
LittleBrother: /home/kobi/Desktop/opencv-4.3.0/build/lib/libopencv_ml.so.4.3.0
LittleBrother: /home/kobi/Desktop/opencv-4.3.0/build/lib/libopencv_objdetect.so.4.3.0
LittleBrother: /home/kobi/Desktop/opencv-4.3.0/build/lib/libopencv_photo.so.4.3.0
LittleBrother: /home/kobi/Desktop/opencv-4.3.0/build/lib/libopencv_stitching.so.4.3.0
LittleBrother: /home/kobi/Desktop/opencv-4.3.0/build/lib/libopencv_video.so.4.3.0
LittleBrother: /home/kobi/Desktop/opencv-4.3.0/build/lib/libopencv_highgui.so.4.3.0
LittleBrother: /home/kobi/Desktop/opencv-4.3.0/build/lib/libopencv_videoio.so.4.3.0
LittleBrother: /home/kobi/Desktop/opencv-4.3.0/build/lib/libopencv_imgcodecs.so.4.3.0
LittleBrother: /home/kobi/Desktop/opencv-4.3.0/build/lib/libopencv_calib3d.so.4.3.0
LittleBrother: /home/kobi/Desktop/opencv-4.3.0/build/lib/libopencv_features2d.so.4.3.0
LittleBrother: /home/kobi/Desktop/opencv-4.3.0/build/lib/libopencv_flann.so.4.3.0
LittleBrother: /home/kobi/Desktop/opencv-4.3.0/build/lib/libopencv_imgproc.so.4.3.0
LittleBrother: /home/kobi/Desktop/opencv-4.3.0/build/lib/libopencv_core.so.4.3.0
LittleBrother: CMakeFiles/LittleBrother.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kobi/Desktop/LittleBrother/opencv/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable LittleBrother"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LittleBrother.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LittleBrother.dir/build: LittleBrother

.PHONY : CMakeFiles/LittleBrother.dir/build

CMakeFiles/LittleBrother.dir/requires: CMakeFiles/LittleBrother.dir/main.cpp.o.requires
CMakeFiles/LittleBrother.dir/requires: CMakeFiles/LittleBrother.dir/lbwindow.cpp.o.requires
CMakeFiles/LittleBrother.dir/requires: CMakeFiles/LittleBrother.dir/feed.cpp.o.requires

.PHONY : CMakeFiles/LittleBrother.dir/requires

CMakeFiles/LittleBrother.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LittleBrother.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LittleBrother.dir/clean

CMakeFiles/LittleBrother.dir/depend:
	cd /home/kobi/Desktop/LittleBrother/opencv && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kobi/Desktop/LittleBrother/opencv /home/kobi/Desktop/LittleBrother/opencv /home/kobi/Desktop/LittleBrother/opencv /home/kobi/Desktop/LittleBrother/opencv /home/kobi/Desktop/LittleBrother/opencv/CMakeFiles/LittleBrother.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LittleBrother.dir/depend

