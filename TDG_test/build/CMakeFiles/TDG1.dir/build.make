# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ronaldvelasco/TDG/TDG_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ronaldvelasco/TDG/TDG_test/build

# Utility rule file for TDG1.

# Include any custom commands dependencies for this target.
include CMakeFiles/TDG1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TDG1.dir/progress.make

CMakeFiles/TDG1: TDG

TDG1: CMakeFiles/TDG1
TDG1: CMakeFiles/TDG1.dir/build.make
.PHONY : TDG1

# Rule to build all files generated by this target.
CMakeFiles/TDG1.dir/build: TDG1
.PHONY : CMakeFiles/TDG1.dir/build

CMakeFiles/TDG1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TDG1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TDG1.dir/clean

CMakeFiles/TDG1.dir/depend:
	cd /home/ronaldvelasco/TDG/TDG_test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ronaldvelasco/TDG/TDG_test /home/ronaldvelasco/TDG/TDG_test /home/ronaldvelasco/TDG/TDG_test/build /home/ronaldvelasco/TDG/TDG_test/build /home/ronaldvelasco/TDG/TDG_test/build/CMakeFiles/TDG1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TDG1.dir/depend

