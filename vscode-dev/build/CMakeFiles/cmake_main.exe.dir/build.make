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
CMAKE_SOURCE_DIR = /home/lilinfei/learn-slam/vscode-dev

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lilinfei/learn-slam/vscode-dev/build

# Include any dependencies generated for this target.
include CMakeFiles/cmake_main.exe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cmake_main.exe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cmake_main.exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cmake_main.exe.dir/flags.make

CMakeFiles/cmake_main.exe.dir/main.cpp.o: CMakeFiles/cmake_main.exe.dir/flags.make
CMakeFiles/cmake_main.exe.dir/main.cpp.o: ../main.cpp
CMakeFiles/cmake_main.exe.dir/main.cpp.o: CMakeFiles/cmake_main.exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilinfei/learn-slam/vscode-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cmake_main.exe.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cmake_main.exe.dir/main.cpp.o -MF CMakeFiles/cmake_main.exe.dir/main.cpp.o.d -o CMakeFiles/cmake_main.exe.dir/main.cpp.o -c /home/lilinfei/learn-slam/vscode-dev/main.cpp

CMakeFiles/cmake_main.exe.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cmake_main.exe.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lilinfei/learn-slam/vscode-dev/main.cpp > CMakeFiles/cmake_main.exe.dir/main.cpp.i

CMakeFiles/cmake_main.exe.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cmake_main.exe.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lilinfei/learn-slam/vscode-dev/main.cpp -o CMakeFiles/cmake_main.exe.dir/main.cpp.s

CMakeFiles/cmake_main.exe.dir/src/Gun.cpp.o: CMakeFiles/cmake_main.exe.dir/flags.make
CMakeFiles/cmake_main.exe.dir/src/Gun.cpp.o: ../src/Gun.cpp
CMakeFiles/cmake_main.exe.dir/src/Gun.cpp.o: CMakeFiles/cmake_main.exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilinfei/learn-slam/vscode-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cmake_main.exe.dir/src/Gun.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cmake_main.exe.dir/src/Gun.cpp.o -MF CMakeFiles/cmake_main.exe.dir/src/Gun.cpp.o.d -o CMakeFiles/cmake_main.exe.dir/src/Gun.cpp.o -c /home/lilinfei/learn-slam/vscode-dev/src/Gun.cpp

CMakeFiles/cmake_main.exe.dir/src/Gun.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cmake_main.exe.dir/src/Gun.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lilinfei/learn-slam/vscode-dev/src/Gun.cpp > CMakeFiles/cmake_main.exe.dir/src/Gun.cpp.i

CMakeFiles/cmake_main.exe.dir/src/Gun.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cmake_main.exe.dir/src/Gun.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lilinfei/learn-slam/vscode-dev/src/Gun.cpp -o CMakeFiles/cmake_main.exe.dir/src/Gun.cpp.s

CMakeFiles/cmake_main.exe.dir/src/Soldier.cpp.o: CMakeFiles/cmake_main.exe.dir/flags.make
CMakeFiles/cmake_main.exe.dir/src/Soldier.cpp.o: ../src/Soldier.cpp
CMakeFiles/cmake_main.exe.dir/src/Soldier.cpp.o: CMakeFiles/cmake_main.exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilinfei/learn-slam/vscode-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/cmake_main.exe.dir/src/Soldier.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cmake_main.exe.dir/src/Soldier.cpp.o -MF CMakeFiles/cmake_main.exe.dir/src/Soldier.cpp.o.d -o CMakeFiles/cmake_main.exe.dir/src/Soldier.cpp.o -c /home/lilinfei/learn-slam/vscode-dev/src/Soldier.cpp

CMakeFiles/cmake_main.exe.dir/src/Soldier.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cmake_main.exe.dir/src/Soldier.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lilinfei/learn-slam/vscode-dev/src/Soldier.cpp > CMakeFiles/cmake_main.exe.dir/src/Soldier.cpp.i

CMakeFiles/cmake_main.exe.dir/src/Soldier.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cmake_main.exe.dir/src/Soldier.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lilinfei/learn-slam/vscode-dev/src/Soldier.cpp -o CMakeFiles/cmake_main.exe.dir/src/Soldier.cpp.s

# Object files for target cmake_main.exe
cmake_main_exe_OBJECTS = \
"CMakeFiles/cmake_main.exe.dir/main.cpp.o" \
"CMakeFiles/cmake_main.exe.dir/src/Gun.cpp.o" \
"CMakeFiles/cmake_main.exe.dir/src/Soldier.cpp.o"

# External object files for target cmake_main.exe
cmake_main_exe_EXTERNAL_OBJECTS =

cmake_main.exe: CMakeFiles/cmake_main.exe.dir/main.cpp.o
cmake_main.exe: CMakeFiles/cmake_main.exe.dir/src/Gun.cpp.o
cmake_main.exe: CMakeFiles/cmake_main.exe.dir/src/Soldier.cpp.o
cmake_main.exe: CMakeFiles/cmake_main.exe.dir/build.make
cmake_main.exe: CMakeFiles/cmake_main.exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lilinfei/learn-slam/vscode-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable cmake_main.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cmake_main.exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cmake_main.exe.dir/build: cmake_main.exe
.PHONY : CMakeFiles/cmake_main.exe.dir/build

CMakeFiles/cmake_main.exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cmake_main.exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cmake_main.exe.dir/clean

CMakeFiles/cmake_main.exe.dir/depend:
	cd /home/lilinfei/learn-slam/vscode-dev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lilinfei/learn-slam/vscode-dev /home/lilinfei/learn-slam/vscode-dev /home/lilinfei/learn-slam/vscode-dev/build /home/lilinfei/learn-slam/vscode-dev/build /home/lilinfei/learn-slam/vscode-dev/build/CMakeFiles/cmake_main.exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cmake_main.exe.dir/depend

