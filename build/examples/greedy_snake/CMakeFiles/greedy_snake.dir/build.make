# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /data/data/com.termux/files/usr/bin/sh

# The CMake executable.
CMAKE_COMMAND = /data/data/com.termux/files/usr/bin/cmake

# The command to remove a file.
RM = /data/data/com.termux/files/usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /data/data/com.termux/files/home/Clementine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /data/data/com.termux/files/home/Clementine/build

# Include any dependencies generated for this target.
include examples/greedy_snake/CMakeFiles/greedy_snake.dir/depend.make

# Include the progress variables for this target.
include examples/greedy_snake/CMakeFiles/greedy_snake.dir/progress.make

# Include the compile flags for this target's objects.
include examples/greedy_snake/CMakeFiles/greedy_snake.dir/flags.make

examples/greedy_snake/CMakeFiles/greedy_snake.dir/main.cpp.o: examples/greedy_snake/CMakeFiles/greedy_snake.dir/flags.make
examples/greedy_snake/CMakeFiles/greedy_snake.dir/main.cpp.o: ../examples/greedy_snake/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/data/com.termux/files/home/Clementine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/greedy_snake/CMakeFiles/greedy_snake.dir/main.cpp.o"
	cd /data/data/com.termux/files/home/Clementine/build/examples/greedy_snake && /data/data/com.termux/files/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/greedy_snake.dir/main.cpp.o -c /data/data/com.termux/files/home/Clementine/examples/greedy_snake/main.cpp

examples/greedy_snake/CMakeFiles/greedy_snake.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/greedy_snake.dir/main.cpp.i"
	cd /data/data/com.termux/files/home/Clementine/build/examples/greedy_snake && /data/data/com.termux/files/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/data/com.termux/files/home/Clementine/examples/greedy_snake/main.cpp > CMakeFiles/greedy_snake.dir/main.cpp.i

examples/greedy_snake/CMakeFiles/greedy_snake.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/greedy_snake.dir/main.cpp.s"
	cd /data/data/com.termux/files/home/Clementine/build/examples/greedy_snake && /data/data/com.termux/files/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/data/com.termux/files/home/Clementine/examples/greedy_snake/main.cpp -o CMakeFiles/greedy_snake.dir/main.cpp.s

# Object files for target greedy_snake
greedy_snake_OBJECTS = \
"CMakeFiles/greedy_snake.dir/main.cpp.o"

# External object files for target greedy_snake
greedy_snake_EXTERNAL_OBJECTS =

examples/greedy_snake/greedy_snake: examples/greedy_snake/CMakeFiles/greedy_snake.dir/main.cpp.o
examples/greedy_snake/greedy_snake: examples/greedy_snake/CMakeFiles/greedy_snake.dir/build.make
examples/greedy_snake/greedy_snake: ../lib/libclementine.a
examples/greedy_snake/greedy_snake: examples/greedy_snake/CMakeFiles/greedy_snake.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/data/data/com.termux/files/home/Clementine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable greedy_snake"
	cd /data/data/com.termux/files/home/Clementine/build/examples/greedy_snake && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/greedy_snake.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/greedy_snake/CMakeFiles/greedy_snake.dir/build: examples/greedy_snake/greedy_snake

.PHONY : examples/greedy_snake/CMakeFiles/greedy_snake.dir/build

examples/greedy_snake/CMakeFiles/greedy_snake.dir/clean:
	cd /data/data/com.termux/files/home/Clementine/build/examples/greedy_snake && $(CMAKE_COMMAND) -P CMakeFiles/greedy_snake.dir/cmake_clean.cmake
.PHONY : examples/greedy_snake/CMakeFiles/greedy_snake.dir/clean

examples/greedy_snake/CMakeFiles/greedy_snake.dir/depend:
	cd /data/data/com.termux/files/home/Clementine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data/data/com.termux/files/home/Clementine /data/data/com.termux/files/home/Clementine/examples/greedy_snake /data/data/com.termux/files/home/Clementine/build /data/data/com.termux/files/home/Clementine/build/examples/greedy_snake /data/data/com.termux/files/home/Clementine/build/examples/greedy_snake/CMakeFiles/greedy_snake.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/greedy_snake/CMakeFiles/greedy_snake.dir/depend

