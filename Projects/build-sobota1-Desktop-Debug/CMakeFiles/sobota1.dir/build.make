# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_SOURCE_DIR = /home/moto/Projects/sobota1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/moto/Projects/build-sobota1-Desktop-Debug

# Include any dependencies generated for this target.
include CMakeFiles/sobota1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sobota1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sobota1.dir/flags.make

CMakeFiles/sobota1.dir/main.cpp.o: CMakeFiles/sobota1.dir/flags.make
CMakeFiles/sobota1.dir/main.cpp.o: /home/moto/Projects/sobota1/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/moto/Projects/build-sobota1-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sobota1.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sobota1.dir/main.cpp.o -c /home/moto/Projects/sobota1/main.cpp

CMakeFiles/sobota1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sobota1.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/moto/Projects/sobota1/main.cpp > CMakeFiles/sobota1.dir/main.cpp.i

CMakeFiles/sobota1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sobota1.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/moto/Projects/sobota1/main.cpp -o CMakeFiles/sobota1.dir/main.cpp.s

CMakeFiles/sobota1.dir/helper.cpp.o: CMakeFiles/sobota1.dir/flags.make
CMakeFiles/sobota1.dir/helper.cpp.o: /home/moto/Projects/sobota1/helper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/moto/Projects/build-sobota1-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sobota1.dir/helper.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sobota1.dir/helper.cpp.o -c /home/moto/Projects/sobota1/helper.cpp

CMakeFiles/sobota1.dir/helper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sobota1.dir/helper.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/moto/Projects/sobota1/helper.cpp > CMakeFiles/sobota1.dir/helper.cpp.i

CMakeFiles/sobota1.dir/helper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sobota1.dir/helper.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/moto/Projects/sobota1/helper.cpp -o CMakeFiles/sobota1.dir/helper.cpp.s

# Object files for target sobota1
sobota1_OBJECTS = \
"CMakeFiles/sobota1.dir/main.cpp.o" \
"CMakeFiles/sobota1.dir/helper.cpp.o"

# External object files for target sobota1
sobota1_EXTERNAL_OBJECTS =

sobota1: CMakeFiles/sobota1.dir/main.cpp.o
sobota1: CMakeFiles/sobota1.dir/helper.cpp.o
sobota1: CMakeFiles/sobota1.dir/build.make
sobota1: CMakeFiles/sobota1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/moto/Projects/build-sobota1-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable sobota1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sobota1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sobota1.dir/build: sobota1

.PHONY : CMakeFiles/sobota1.dir/build

CMakeFiles/sobota1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sobota1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sobota1.dir/clean

CMakeFiles/sobota1.dir/depend:
	cd /home/moto/Projects/build-sobota1-Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/moto/Projects/sobota1 /home/moto/Projects/sobota1 /home/moto/Projects/build-sobota1-Desktop-Debug /home/moto/Projects/build-sobota1-Desktop-Debug /home/moto/Projects/build-sobota1-Desktop-Debug/CMakeFiles/sobota1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sobota1.dir/depend
