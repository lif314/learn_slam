# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/lilinfei/learn-slam/ch2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lilinfei/learn-slam/ch2/build

# Include any dependencies generated for this target.
include CMakeFiles/libHello.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/libHello.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/libHello.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libHello.dir/flags.make

CMakeFiles/libHello.dir/libHello.cpp.o: CMakeFiles/libHello.dir/flags.make
CMakeFiles/libHello.dir/libHello.cpp.o: ../libHello.cpp
CMakeFiles/libHello.dir/libHello.cpp.o: CMakeFiles/libHello.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilinfei/learn-slam/ch2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/libHello.dir/libHello.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libHello.dir/libHello.cpp.o -MF CMakeFiles/libHello.dir/libHello.cpp.o.d -o CMakeFiles/libHello.dir/libHello.cpp.o -c /home/lilinfei/learn-slam/ch2/libHello.cpp

CMakeFiles/libHello.dir/libHello.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libHello.dir/libHello.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lilinfei/learn-slam/ch2/libHello.cpp > CMakeFiles/libHello.dir/libHello.cpp.i

CMakeFiles/libHello.dir/libHello.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libHello.dir/libHello.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lilinfei/learn-slam/ch2/libHello.cpp -o CMakeFiles/libHello.dir/libHello.cpp.s

# Object files for target libHello
libHello_OBJECTS = \
"CMakeFiles/libHello.dir/libHello.cpp.o"

# External object files for target libHello
libHello_EXTERNAL_OBJECTS =

liblibHello.a: CMakeFiles/libHello.dir/libHello.cpp.o
liblibHello.a: CMakeFiles/libHello.dir/build.make
liblibHello.a: CMakeFiles/libHello.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lilinfei/learn-slam/ch2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblibHello.a"
	$(CMAKE_COMMAND) -P CMakeFiles/libHello.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libHello.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libHello.dir/build: liblibHello.a
.PHONY : CMakeFiles/libHello.dir/build

CMakeFiles/libHello.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libHello.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libHello.dir/clean

CMakeFiles/libHello.dir/depend:
	cd /home/lilinfei/learn-slam/ch2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lilinfei/learn-slam/ch2 /home/lilinfei/learn-slam/ch2 /home/lilinfei/learn-slam/ch2/build /home/lilinfei/learn-slam/ch2/build /home/lilinfei/learn-slam/ch2/build/CMakeFiles/libHello.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libHello.dir/depend

