# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/tsukimori/bplustree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tsukimori/bplustree/build

# Include any dependencies generated for this target.
include lib/CMakeFiles/bplustree_static.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/bplustree_static.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/bplustree_static.dir/flags.make

lib/CMakeFiles/bplustree_static.dir/bplustree.c.o: lib/CMakeFiles/bplustree_static.dir/flags.make
lib/CMakeFiles/bplustree_static.dir/bplustree.c.o: ../lib/bplustree.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tsukimori/bplustree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/CMakeFiles/bplustree_static.dir/bplustree.c.o"
	cd /home/tsukimori/bplustree/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bplustree_static.dir/bplustree.c.o   -c /home/tsukimori/bplustree/lib/bplustree.c

lib/CMakeFiles/bplustree_static.dir/bplustree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bplustree_static.dir/bplustree.c.i"
	cd /home/tsukimori/bplustree/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tsukimori/bplustree/lib/bplustree.c > CMakeFiles/bplustree_static.dir/bplustree.c.i

lib/CMakeFiles/bplustree_static.dir/bplustree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bplustree_static.dir/bplustree.c.s"
	cd /home/tsukimori/bplustree/build/lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tsukimori/bplustree/lib/bplustree.c -o CMakeFiles/bplustree_static.dir/bplustree.c.s

lib/CMakeFiles/bplustree_static.dir/bplustree.c.o.requires:

.PHONY : lib/CMakeFiles/bplustree_static.dir/bplustree.c.o.requires

lib/CMakeFiles/bplustree_static.dir/bplustree.c.o.provides: lib/CMakeFiles/bplustree_static.dir/bplustree.c.o.requires
	$(MAKE) -f lib/CMakeFiles/bplustree_static.dir/build.make lib/CMakeFiles/bplustree_static.dir/bplustree.c.o.provides.build
.PHONY : lib/CMakeFiles/bplustree_static.dir/bplustree.c.o.provides

lib/CMakeFiles/bplustree_static.dir/bplustree.c.o.provides.build: lib/CMakeFiles/bplustree_static.dir/bplustree.c.o


# Object files for target bplustree_static
bplustree_static_OBJECTS = \
"CMakeFiles/bplustree_static.dir/bplustree.c.o"

# External object files for target bplustree_static
bplustree_static_EXTERNAL_OBJECTS =

lib/libbplustree.a: lib/CMakeFiles/bplustree_static.dir/bplustree.c.o
lib/libbplustree.a: lib/CMakeFiles/bplustree_static.dir/build.make
lib/libbplustree.a: lib/CMakeFiles/bplustree_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tsukimori/bplustree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libbplustree.a"
	cd /home/tsukimori/bplustree/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/bplustree_static.dir/cmake_clean_target.cmake
	cd /home/tsukimori/bplustree/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bplustree_static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/bplustree_static.dir/build: lib/libbplustree.a

.PHONY : lib/CMakeFiles/bplustree_static.dir/build

lib/CMakeFiles/bplustree_static.dir/requires: lib/CMakeFiles/bplustree_static.dir/bplustree.c.o.requires

.PHONY : lib/CMakeFiles/bplustree_static.dir/requires

lib/CMakeFiles/bplustree_static.dir/clean:
	cd /home/tsukimori/bplustree/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/bplustree_static.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/bplustree_static.dir/clean

lib/CMakeFiles/bplustree_static.dir/depend:
	cd /home/tsukimori/bplustree/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tsukimori/bplustree /home/tsukimori/bplustree/lib /home/tsukimori/bplustree/build /home/tsukimori/bplustree/build/lib /home/tsukimori/bplustree/build/lib/CMakeFiles/bplustree_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/bplustree_static.dir/depend

