# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/tomas/Descargas/CLion/CLion-2018.2.4/clion-2018.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/tomas/Descargas/CLion/CLion-2018.2.4/clion-2018.2.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/tomas/Documentos/6to Semestre/PSS/Tarea3/T3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/tomas/Documentos/6to Semestre/PSS/Tarea3/T3/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/T3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/T3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/T3.dir/flags.make

CMakeFiles/T3.dir/test-reunion.c.o: CMakeFiles/T3.dir/flags.make
CMakeFiles/T3.dir/test-reunion.c.o: ../test-reunion.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tomas/Documentos/6to Semestre/PSS/Tarea3/T3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/T3.dir/test-reunion.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/T3.dir/test-reunion.c.o   -c "/home/tomas/Documentos/6to Semestre/PSS/Tarea3/T3/test-reunion.c"

CMakeFiles/T3.dir/test-reunion.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/T3.dir/test-reunion.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/tomas/Documentos/6to Semestre/PSS/Tarea3/T3/test-reunion.c" > CMakeFiles/T3.dir/test-reunion.c.i

CMakeFiles/T3.dir/test-reunion.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/T3.dir/test-reunion.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/tomas/Documentos/6to Semestre/PSS/Tarea3/T3/test-reunion.c" -o CMakeFiles/T3.dir/test-reunion.c.s

CMakeFiles/T3.dir/reunion.c.o: CMakeFiles/T3.dir/flags.make
CMakeFiles/T3.dir/reunion.c.o: ../reunion.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tomas/Documentos/6to Semestre/PSS/Tarea3/T3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/T3.dir/reunion.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/T3.dir/reunion.c.o   -c "/home/tomas/Documentos/6to Semestre/PSS/Tarea3/T3/reunion.c"

CMakeFiles/T3.dir/reunion.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/T3.dir/reunion.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/tomas/Documentos/6to Semestre/PSS/Tarea3/T3/reunion.c" > CMakeFiles/T3.dir/reunion.c.i

CMakeFiles/T3.dir/reunion.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/T3.dir/reunion.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/tomas/Documentos/6to Semestre/PSS/Tarea3/T3/reunion.c" -o CMakeFiles/T3.dir/reunion.c.s

# Object files for target T3
T3_OBJECTS = \
"CMakeFiles/T3.dir/test-reunion.c.o" \
"CMakeFiles/T3.dir/reunion.c.o"

# External object files for target T3
T3_EXTERNAL_OBJECTS =

T3: CMakeFiles/T3.dir/test-reunion.c.o
T3: CMakeFiles/T3.dir/reunion.c.o
T3: CMakeFiles/T3.dir/build.make
T3: CMakeFiles/T3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/tomas/Documentos/6to Semestre/PSS/Tarea3/T3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable T3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/T3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/T3.dir/build: T3

.PHONY : CMakeFiles/T3.dir/build

CMakeFiles/T3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/T3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/T3.dir/clean

CMakeFiles/T3.dir/depend:
	cd "/home/tomas/Documentos/6to Semestre/PSS/Tarea3/T3/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/tomas/Documentos/6to Semestre/PSS/Tarea3/T3" "/home/tomas/Documentos/6to Semestre/PSS/Tarea3/T3" "/home/tomas/Documentos/6to Semestre/PSS/Tarea3/T3/cmake-build-debug" "/home/tomas/Documentos/6to Semestre/PSS/Tarea3/T3/cmake-build-debug" "/home/tomas/Documentos/6to Semestre/PSS/Tarea3/T3/cmake-build-debug/CMakeFiles/T3.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/T3.dir/depend
