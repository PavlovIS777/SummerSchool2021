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
CMAKE_COMMAND = "/cygdrive/c/Users/Vanushka Ogli Pushka/AppData/Local/JetBrains/CLion2021.2/cygwin_cmake/bin/cmake.exe"

# The command to remove a file.
RM = "/cygdrive/c/Users/Vanushka Ogli Pushka/AppData/Local/JetBrains/CLion2021.2/cygwin_cmake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/d/CLion 2021.2/SqrEquation"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/d/CLion 2021.2/SqrEquation/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/SqrEquation.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/SqrEquation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SqrEquation.dir/flags.make

CMakeFiles/SqrEquation.dir/main.c.o: CMakeFiles/SqrEquation.dir/flags.make
CMakeFiles/SqrEquation.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/d/CLion 2021.2/SqrEquation/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SqrEquation.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SqrEquation.dir/main.c.o -c "/cygdrive/d/CLion 2021.2/SqrEquation/main.c"

CMakeFiles/SqrEquation.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SqrEquation.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/cygdrive/d/CLion 2021.2/SqrEquation/main.c" > CMakeFiles/SqrEquation.dir/main.c.i

CMakeFiles/SqrEquation.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SqrEquation.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/cygdrive/d/CLion 2021.2/SqrEquation/main.c" -o CMakeFiles/SqrEquation.dir/main.c.s

# Object files for target SqrEquation
SqrEquation_OBJECTS = \
"CMakeFiles/SqrEquation.dir/main.c.o"

# External object files for target SqrEquation
SqrEquation_EXTERNAL_OBJECTS =

SqrEquation.exe: CMakeFiles/SqrEquation.dir/main.c.o
SqrEquation.exe: CMakeFiles/SqrEquation.dir/build.make
SqrEquation.exe: CMakeFiles/SqrEquation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/d/CLion 2021.2/SqrEquation/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable SqrEquation.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SqrEquation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SqrEquation.dir/build: SqrEquation.exe
.PHONY : CMakeFiles/SqrEquation.dir/build

CMakeFiles/SqrEquation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SqrEquation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SqrEquation.dir/clean

CMakeFiles/SqrEquation.dir/depend:
	cd "/cygdrive/d/CLion 2021.2/SqrEquation/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/d/CLion 2021.2/SqrEquation" "/cygdrive/d/CLion 2021.2/SqrEquation" "/cygdrive/d/CLion 2021.2/SqrEquation/cmake-build-debug" "/cygdrive/d/CLion 2021.2/SqrEquation/cmake-build-debug" "/cygdrive/d/CLion 2021.2/SqrEquation/cmake-build-debug/CMakeFiles/SqrEquation.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/SqrEquation.dir/depend

