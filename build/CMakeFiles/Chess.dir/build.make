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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.11.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.11.0/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/Michel/Documents/TUHH/Prozedurale Programmierung/Project/Schach"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/Michel/Documents/TUHH/Prozedurale Programmierung/Project/Schach/build"

# Include any dependencies generated for this target.
include CMakeFiles/Chess.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Chess.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Chess.dir/flags.make

CMakeFiles/Chess.dir/source/Main.c.o: CMakeFiles/Chess.dir/flags.make
CMakeFiles/Chess.dir/source/Main.c.o: ../source/Main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Michel/Documents/TUHH/Prozedurale Programmierung/Project/Schach/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Chess.dir/source/Main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Chess.dir/source/Main.c.o   -c "/Users/Michel/Documents/TUHH/Prozedurale Programmierung/Project/Schach/source/Main.c"

CMakeFiles/Chess.dir/source/Main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Chess.dir/source/Main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/Michel/Documents/TUHH/Prozedurale Programmierung/Project/Schach/source/Main.c" > CMakeFiles/Chess.dir/source/Main.c.i

CMakeFiles/Chess.dir/source/Main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Chess.dir/source/Main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/Michel/Documents/TUHH/Prozedurale Programmierung/Project/Schach/source/Main.c" -o CMakeFiles/Chess.dir/source/Main.c.s

# Object files for target Chess
Chess_OBJECTS = \
"CMakeFiles/Chess.dir/source/Main.c.o"

# External object files for target Chess
Chess_EXTERNAL_OBJECTS =

Chess: CMakeFiles/Chess.dir/source/Main.c.o
Chess: CMakeFiles/Chess.dir/build.make
Chess: CMakeFiles/Chess.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/Michel/Documents/TUHH/Prozedurale Programmierung/Project/Schach/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Chess"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Chess.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Chess.dir/build: Chess

.PHONY : CMakeFiles/Chess.dir/build

CMakeFiles/Chess.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Chess.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Chess.dir/clean

CMakeFiles/Chess.dir/depend:
	cd "/Users/Michel/Documents/TUHH/Prozedurale Programmierung/Project/Schach/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/Michel/Documents/TUHH/Prozedurale Programmierung/Project/Schach" "/Users/Michel/Documents/TUHH/Prozedurale Programmierung/Project/Schach" "/Users/Michel/Documents/TUHH/Prozedurale Programmierung/Project/Schach/build" "/Users/Michel/Documents/TUHH/Prozedurale Programmierung/Project/Schach/build" "/Users/Michel/Documents/TUHH/Prozedurale Programmierung/Project/Schach/build/CMakeFiles/Chess.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Chess.dir/depend

