# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/alegruz/workspace/Game-AI-Library

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alegruz/workspace/Game-AI-Library/build

# Include any dependencies generated for this target.
include CMakeFiles/Game-AI-Library.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Game-AI-Library.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Game-AI-Library.dir/flags.make

CMakeFiles/Game-AI-Library.dir/main.cpp.o: CMakeFiles/Game-AI-Library.dir/flags.make
CMakeFiles/Game-AI-Library.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alegruz/workspace/Game-AI-Library/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Game-AI-Library.dir/main.cpp.o"
	/usr/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game-AI-Library.dir/main.cpp.o -c /home/alegruz/workspace/Game-AI-Library/main.cpp

CMakeFiles/Game-AI-Library.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game-AI-Library.dir/main.cpp.i"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alegruz/workspace/Game-AI-Library/main.cpp > CMakeFiles/Game-AI-Library.dir/main.cpp.i

CMakeFiles/Game-AI-Library.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game-AI-Library.dir/main.cpp.s"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alegruz/workspace/Game-AI-Library/main.cpp -o CMakeFiles/Game-AI-Library.dir/main.cpp.s

# Object files for target Game-AI-Library
Game__AI__Library_OBJECTS = \
"CMakeFiles/Game-AI-Library.dir/main.cpp.o"

# External object files for target Game-AI-Library
Game__AI__Library_EXTERNAL_OBJECTS =

Game-AI-Library: CMakeFiles/Game-AI-Library.dir/main.cpp.o
Game-AI-Library: CMakeFiles/Game-AI-Library.dir/build.make
Game-AI-Library: game_ai_library/machine_learning/cnn/libCNN.so
Game-AI-Library: CMakeFiles/Game-AI-Library.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alegruz/workspace/Game-AI-Library/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Game-AI-Library"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Game-AI-Library.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Game-AI-Library.dir/build: Game-AI-Library

.PHONY : CMakeFiles/Game-AI-Library.dir/build

CMakeFiles/Game-AI-Library.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Game-AI-Library.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Game-AI-Library.dir/clean

CMakeFiles/Game-AI-Library.dir/depend:
	cd /home/alegruz/workspace/Game-AI-Library/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alegruz/workspace/Game-AI-Library /home/alegruz/workspace/Game-AI-Library /home/alegruz/workspace/Game-AI-Library/build /home/alegruz/workspace/Game-AI-Library/build /home/alegruz/workspace/Game-AI-Library/build/CMakeFiles/Game-AI-Library.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Game-AI-Library.dir/depend

