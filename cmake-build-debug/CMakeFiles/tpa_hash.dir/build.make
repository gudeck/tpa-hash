# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /snap/clion/82/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/82/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gudeck/CLionProjects/tpa-hash

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gudeck/CLionProjects/tpa-hash/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/tpa_hash.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tpa_hash.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tpa_hash.dir/flags.make

CMakeFiles/tpa_hash.dir/main.c.o: CMakeFiles/tpa_hash.dir/flags.make
CMakeFiles/tpa_hash.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gudeck/CLionProjects/tpa-hash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/tpa_hash.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tpa_hash.dir/main.c.o   -c /home/gudeck/CLionProjects/tpa-hash/main.c

CMakeFiles/tpa_hash.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tpa_hash.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gudeck/CLionProjects/tpa-hash/main.c > CMakeFiles/tpa_hash.dir/main.c.i

CMakeFiles/tpa_hash.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tpa_hash.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gudeck/CLionProjects/tpa-hash/main.c -o CMakeFiles/tpa_hash.dir/main.c.s

CMakeFiles/tpa_hash.dir/Funcoes.c.o: CMakeFiles/tpa_hash.dir/flags.make
CMakeFiles/tpa_hash.dir/Funcoes.c.o: ../Funcoes.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gudeck/CLionProjects/tpa-hash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/tpa_hash.dir/Funcoes.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tpa_hash.dir/Funcoes.c.o   -c /home/gudeck/CLionProjects/tpa-hash/Funcoes.c

CMakeFiles/tpa_hash.dir/Funcoes.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tpa_hash.dir/Funcoes.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gudeck/CLionProjects/tpa-hash/Funcoes.c > CMakeFiles/tpa_hash.dir/Funcoes.c.i

CMakeFiles/tpa_hash.dir/Funcoes.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tpa_hash.dir/Funcoes.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gudeck/CLionProjects/tpa-hash/Funcoes.c -o CMakeFiles/tpa_hash.dir/Funcoes.c.s

CMakeFiles/tpa_hash.dir/ListaClientes.c.o: CMakeFiles/tpa_hash.dir/flags.make
CMakeFiles/tpa_hash.dir/ListaClientes.c.o: ../ListaClientes.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gudeck/CLionProjects/tpa-hash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/tpa_hash.dir/ListaClientes.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tpa_hash.dir/ListaClientes.c.o   -c /home/gudeck/CLionProjects/tpa-hash/ListaClientes.c

CMakeFiles/tpa_hash.dir/ListaClientes.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tpa_hash.dir/ListaClientes.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gudeck/CLionProjects/tpa-hash/ListaClientes.c > CMakeFiles/tpa_hash.dir/ListaClientes.c.i

CMakeFiles/tpa_hash.dir/ListaClientes.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tpa_hash.dir/ListaClientes.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gudeck/CLionProjects/tpa-hash/ListaClientes.c -o CMakeFiles/tpa_hash.dir/ListaClientes.c.s

# Object files for target tpa_hash
tpa_hash_OBJECTS = \
"CMakeFiles/tpa_hash.dir/main.c.o" \
"CMakeFiles/tpa_hash.dir/Funcoes.c.o" \
"CMakeFiles/tpa_hash.dir/ListaClientes.c.o"

# External object files for target tpa_hash
tpa_hash_EXTERNAL_OBJECTS =

tpa_hash: CMakeFiles/tpa_hash.dir/main.c.o
tpa_hash: CMakeFiles/tpa_hash.dir/Funcoes.c.o
tpa_hash: CMakeFiles/tpa_hash.dir/ListaClientes.c.o
tpa_hash: CMakeFiles/tpa_hash.dir/build.make
tpa_hash: CMakeFiles/tpa_hash.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gudeck/CLionProjects/tpa-hash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable tpa_hash"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tpa_hash.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tpa_hash.dir/build: tpa_hash

.PHONY : CMakeFiles/tpa_hash.dir/build

CMakeFiles/tpa_hash.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tpa_hash.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tpa_hash.dir/clean

CMakeFiles/tpa_hash.dir/depend:
	cd /home/gudeck/CLionProjects/tpa-hash/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gudeck/CLionProjects/tpa-hash /home/gudeck/CLionProjects/tpa-hash /home/gudeck/CLionProjects/tpa-hash/cmake-build-debug /home/gudeck/CLionProjects/tpa-hash/cmake-build-debug /home/gudeck/CLionProjects/tpa-hash/cmake-build-debug/CMakeFiles/tpa_hash.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tpa_hash.dir/depend

