# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rakso/Projects/todd

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rakso/Projects/todd/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/todd.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/todd.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/todd.dir/flags.make

CMakeFiles/todd.dir/src/actions.c.o: CMakeFiles/todd.dir/flags.make
CMakeFiles/todd.dir/src/actions.c.o: ../src/actions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rakso/Projects/todd/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/todd.dir/src/actions.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/todd.dir/src/actions.c.o   -c /Users/rakso/Projects/todd/src/actions.c

CMakeFiles/todd.dir/src/actions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/todd.dir/src/actions.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rakso/Projects/todd/src/actions.c > CMakeFiles/todd.dir/src/actions.c.i

CMakeFiles/todd.dir/src/actions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/todd.dir/src/actions.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rakso/Projects/todd/src/actions.c -o CMakeFiles/todd.dir/src/actions.c.s

CMakeFiles/todd.dir/src/calculator.c.o: CMakeFiles/todd.dir/flags.make
CMakeFiles/todd.dir/src/calculator.c.o: ../src/calculator.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rakso/Projects/todd/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/todd.dir/src/calculator.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/todd.dir/src/calculator.c.o   -c /Users/rakso/Projects/todd/src/calculator.c

CMakeFiles/todd.dir/src/calculator.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/todd.dir/src/calculator.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rakso/Projects/todd/src/calculator.c > CMakeFiles/todd.dir/src/calculator.c.i

CMakeFiles/todd.dir/src/calculator.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/todd.dir/src/calculator.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rakso/Projects/todd/src/calculator.c -o CMakeFiles/todd.dir/src/calculator.c.s

CMakeFiles/todd.dir/src/history.c.o: CMakeFiles/todd.dir/flags.make
CMakeFiles/todd.dir/src/history.c.o: ../src/history.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rakso/Projects/todd/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/todd.dir/src/history.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/todd.dir/src/history.c.o   -c /Users/rakso/Projects/todd/src/history.c

CMakeFiles/todd.dir/src/history.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/todd.dir/src/history.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rakso/Projects/todd/src/history.c > CMakeFiles/todd.dir/src/history.c.i

CMakeFiles/todd.dir/src/history.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/todd.dir/src/history.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rakso/Projects/todd/src/history.c -o CMakeFiles/todd.dir/src/history.c.s

CMakeFiles/todd.dir/src/interpreter.c.o: CMakeFiles/todd.dir/flags.make
CMakeFiles/todd.dir/src/interpreter.c.o: ../src/interpreter.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rakso/Projects/todd/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/todd.dir/src/interpreter.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/todd.dir/src/interpreter.c.o   -c /Users/rakso/Projects/todd/src/interpreter.c

CMakeFiles/todd.dir/src/interpreter.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/todd.dir/src/interpreter.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rakso/Projects/todd/src/interpreter.c > CMakeFiles/todd.dir/src/interpreter.c.i

CMakeFiles/todd.dir/src/interpreter.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/todd.dir/src/interpreter.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rakso/Projects/todd/src/interpreter.c -o CMakeFiles/todd.dir/src/interpreter.c.s

CMakeFiles/todd.dir/src/main.c.o: CMakeFiles/todd.dir/flags.make
CMakeFiles/todd.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rakso/Projects/todd/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/todd.dir/src/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/todd.dir/src/main.c.o   -c /Users/rakso/Projects/todd/src/main.c

CMakeFiles/todd.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/todd.dir/src/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rakso/Projects/todd/src/main.c > CMakeFiles/todd.dir/src/main.c.i

CMakeFiles/todd.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/todd.dir/src/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rakso/Projects/todd/src/main.c -o CMakeFiles/todd.dir/src/main.c.s

CMakeFiles/todd.dir/src/memory.c.o: CMakeFiles/todd.dir/flags.make
CMakeFiles/todd.dir/src/memory.c.o: ../src/memory.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rakso/Projects/todd/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/todd.dir/src/memory.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/todd.dir/src/memory.c.o   -c /Users/rakso/Projects/todd/src/memory.c

CMakeFiles/todd.dir/src/memory.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/todd.dir/src/memory.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rakso/Projects/todd/src/memory.c > CMakeFiles/todd.dir/src/memory.c.i

CMakeFiles/todd.dir/src/memory.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/todd.dir/src/memory.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rakso/Projects/todd/src/memory.c -o CMakeFiles/todd.dir/src/memory.c.s

CMakeFiles/todd.dir/src/split_line.c.o: CMakeFiles/todd.dir/flags.make
CMakeFiles/todd.dir/src/split_line.c.o: ../src/split_line.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rakso/Projects/todd/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/todd.dir/src/split_line.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/todd.dir/src/split_line.c.o   -c /Users/rakso/Projects/todd/src/split_line.c

CMakeFiles/todd.dir/src/split_line.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/todd.dir/src/split_line.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rakso/Projects/todd/src/split_line.c > CMakeFiles/todd.dir/src/split_line.c.i

CMakeFiles/todd.dir/src/split_line.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/todd.dir/src/split_line.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rakso/Projects/todd/src/split_line.c -o CMakeFiles/todd.dir/src/split_line.c.s

CMakeFiles/todd.dir/src/utils.c.o: CMakeFiles/todd.dir/flags.make
CMakeFiles/todd.dir/src/utils.c.o: ../src/utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rakso/Projects/todd/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/todd.dir/src/utils.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/todd.dir/src/utils.c.o   -c /Users/rakso/Projects/todd/src/utils.c

CMakeFiles/todd.dir/src/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/todd.dir/src/utils.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rakso/Projects/todd/src/utils.c > CMakeFiles/todd.dir/src/utils.c.i

CMakeFiles/todd.dir/src/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/todd.dir/src/utils.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rakso/Projects/todd/src/utils.c -o CMakeFiles/todd.dir/src/utils.c.s

# Object files for target todd
todd_OBJECTS = \
"CMakeFiles/todd.dir/src/actions.c.o" \
"CMakeFiles/todd.dir/src/calculator.c.o" \
"CMakeFiles/todd.dir/src/history.c.o" \
"CMakeFiles/todd.dir/src/interpreter.c.o" \
"CMakeFiles/todd.dir/src/main.c.o" \
"CMakeFiles/todd.dir/src/memory.c.o" \
"CMakeFiles/todd.dir/src/split_line.c.o" \
"CMakeFiles/todd.dir/src/utils.c.o"

# External object files for target todd
todd_EXTERNAL_OBJECTS =

todd: CMakeFiles/todd.dir/src/actions.c.o
todd: CMakeFiles/todd.dir/src/calculator.c.o
todd: CMakeFiles/todd.dir/src/history.c.o
todd: CMakeFiles/todd.dir/src/interpreter.c.o
todd: CMakeFiles/todd.dir/src/main.c.o
todd: CMakeFiles/todd.dir/src/memory.c.o
todd: CMakeFiles/todd.dir/src/split_line.c.o
todd: CMakeFiles/todd.dir/src/utils.c.o
todd: CMakeFiles/todd.dir/build.make
todd: /usr/lib/libcurses.dylib
todd: /usr/lib/libform.dylib
todd: CMakeFiles/todd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rakso/Projects/todd/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking C executable todd"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/todd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/todd.dir/build: todd

.PHONY : CMakeFiles/todd.dir/build

CMakeFiles/todd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/todd.dir/cmake_clean.cmake
.PHONY : CMakeFiles/todd.dir/clean

CMakeFiles/todd.dir/depend:
	cd /Users/rakso/Projects/todd/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rakso/Projects/todd /Users/rakso/Projects/todd /Users/rakso/Projects/todd/cmake-build-debug /Users/rakso/Projects/todd/cmake-build-debug /Users/rakso/Projects/todd/cmake-build-debug/CMakeFiles/todd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/todd.dir/depend

