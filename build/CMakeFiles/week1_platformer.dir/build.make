# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/zi/gamedev/TicTacToe

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zi/gamedev/TicTacToe/build

# Include any dependencies generated for this target.
include CMakeFiles/week1_platformer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/week1_platformer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/week1_platformer.dir/flags.make

CMakeFiles/week1_platformer.dir/src/main.cpp.o: CMakeFiles/week1_platformer.dir/flags.make
CMakeFiles/week1_platformer.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zi/gamedev/TicTacToe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/week1_platformer.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/week1_platformer.dir/src/main.cpp.o -c /home/zi/gamedev/TicTacToe/src/main.cpp

CMakeFiles/week1_platformer.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/week1_platformer.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zi/gamedev/TicTacToe/src/main.cpp > CMakeFiles/week1_platformer.dir/src/main.cpp.i

CMakeFiles/week1_platformer.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/week1_platformer.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zi/gamedev/TicTacToe/src/main.cpp -o CMakeFiles/week1_platformer.dir/src/main.cpp.s

CMakeFiles/week1_platformer.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/week1_platformer.dir/src/main.cpp.o.requires

CMakeFiles/week1_platformer.dir/src/main.cpp.o.provides: CMakeFiles/week1_platformer.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/week1_platformer.dir/build.make CMakeFiles/week1_platformer.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/week1_platformer.dir/src/main.cpp.o.provides

CMakeFiles/week1_platformer.dir/src/main.cpp.o.provides.build: CMakeFiles/week1_platformer.dir/src/main.cpp.o


# Object files for target week1_platformer
week1_platformer_OBJECTS = \
"CMakeFiles/week1_platformer.dir/src/main.cpp.o"

# External object files for target week1_platformer
week1_platformer_EXTERNAL_OBJECTS =

week1_platformer: CMakeFiles/week1_platformer.dir/src/main.cpp.o
week1_platformer: CMakeFiles/week1_platformer.dir/build.make
week1_platformer: /usr/lib64/libsfml-graphics.so
week1_platformer: /usr/lib64/libsfml-window.so
week1_platformer: /usr/lib64/libsfml-system.so
week1_platformer: CMakeFiles/week1_platformer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zi/gamedev/TicTacToe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable week1_platformer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/week1_platformer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/week1_platformer.dir/build: week1_platformer

.PHONY : CMakeFiles/week1_platformer.dir/build

CMakeFiles/week1_platformer.dir/requires: CMakeFiles/week1_platformer.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/week1_platformer.dir/requires

CMakeFiles/week1_platformer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/week1_platformer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/week1_platformer.dir/clean

CMakeFiles/week1_platformer.dir/depend:
	cd /home/zi/gamedev/TicTacToe/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zi/gamedev/TicTacToe /home/zi/gamedev/TicTacToe /home/zi/gamedev/TicTacToe/build /home/zi/gamedev/TicTacToe/build /home/zi/gamedev/TicTacToe/build/CMakeFiles/week1_platformer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/week1_platformer.dir/depend
