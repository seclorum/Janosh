# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/elchaschab/devel/Janosh/json-spirit

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/elchaschab/devel/Janosh/json-spirit

# Include any dependencies generated for this target.
include json_map_demo/CMakeFiles/json_map_demo.dir/depend.make

# Include the progress variables for this target.
include json_map_demo/CMakeFiles/json_map_demo.dir/progress.make

# Include the compile flags for this target's objects.
include json_map_demo/CMakeFiles/json_map_demo.dir/flags.make

json_map_demo/CMakeFiles/json_map_demo.dir/json_map_demo.cpp.o: json_map_demo/CMakeFiles/json_map_demo.dir/flags.make
json_map_demo/CMakeFiles/json_map_demo.dir/json_map_demo.cpp.o: json_map_demo/json_map_demo.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/elchaschab/devel/Janosh/json-spirit/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object json_map_demo/CMakeFiles/json_map_demo.dir/json_map_demo.cpp.o"
	cd /home/elchaschab/devel/Janosh/json-spirit/json_map_demo && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/json_map_demo.dir/json_map_demo.cpp.o -c /home/elchaschab/devel/Janosh/json-spirit/json_map_demo/json_map_demo.cpp

json_map_demo/CMakeFiles/json_map_demo.dir/json_map_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/json_map_demo.dir/json_map_demo.cpp.i"
	cd /home/elchaschab/devel/Janosh/json-spirit/json_map_demo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/elchaschab/devel/Janosh/json-spirit/json_map_demo/json_map_demo.cpp > CMakeFiles/json_map_demo.dir/json_map_demo.cpp.i

json_map_demo/CMakeFiles/json_map_demo.dir/json_map_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/json_map_demo.dir/json_map_demo.cpp.s"
	cd /home/elchaschab/devel/Janosh/json-spirit/json_map_demo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/elchaschab/devel/Janosh/json-spirit/json_map_demo/json_map_demo.cpp -o CMakeFiles/json_map_demo.dir/json_map_demo.cpp.s

json_map_demo/CMakeFiles/json_map_demo.dir/json_map_demo.cpp.o.requires:
.PHONY : json_map_demo/CMakeFiles/json_map_demo.dir/json_map_demo.cpp.o.requires

json_map_demo/CMakeFiles/json_map_demo.dir/json_map_demo.cpp.o.provides: json_map_demo/CMakeFiles/json_map_demo.dir/json_map_demo.cpp.o.requires
	$(MAKE) -f json_map_demo/CMakeFiles/json_map_demo.dir/build.make json_map_demo/CMakeFiles/json_map_demo.dir/json_map_demo.cpp.o.provides.build
.PHONY : json_map_demo/CMakeFiles/json_map_demo.dir/json_map_demo.cpp.o.provides

json_map_demo/CMakeFiles/json_map_demo.dir/json_map_demo.cpp.o.provides.build: json_map_demo/CMakeFiles/json_map_demo.dir/json_map_demo.cpp.o

# Object files for target json_map_demo
json_map_demo_OBJECTS = \
"CMakeFiles/json_map_demo.dir/json_map_demo.cpp.o"

# External object files for target json_map_demo
json_map_demo_EXTERNAL_OBJECTS =

json_map_demo/json_map_demo: json_map_demo/CMakeFiles/json_map_demo.dir/json_map_demo.cpp.o
json_map_demo/json_map_demo: json_map_demo/CMakeFiles/json_map_demo.dir/build.make
json_map_demo/json_map_demo: json_spirit/libjson_spirit.a
json_map_demo/json_map_demo: json_map_demo/CMakeFiles/json_map_demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable json_map_demo"
	cd /home/elchaschab/devel/Janosh/json-spirit/json_map_demo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/json_map_demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
json_map_demo/CMakeFiles/json_map_demo.dir/build: json_map_demo/json_map_demo
.PHONY : json_map_demo/CMakeFiles/json_map_demo.dir/build

json_map_demo/CMakeFiles/json_map_demo.dir/requires: json_map_demo/CMakeFiles/json_map_demo.dir/json_map_demo.cpp.o.requires
.PHONY : json_map_demo/CMakeFiles/json_map_demo.dir/requires

json_map_demo/CMakeFiles/json_map_demo.dir/clean:
	cd /home/elchaschab/devel/Janosh/json-spirit/json_map_demo && $(CMAKE_COMMAND) -P CMakeFiles/json_map_demo.dir/cmake_clean.cmake
.PHONY : json_map_demo/CMakeFiles/json_map_demo.dir/clean

json_map_demo/CMakeFiles/json_map_demo.dir/depend:
	cd /home/elchaschab/devel/Janosh/json-spirit && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/elchaschab/devel/Janosh/json-spirit /home/elchaschab/devel/Janosh/json-spirit/json_map_demo /home/elchaschab/devel/Janosh/json-spirit /home/elchaschab/devel/Janosh/json-spirit/json_map_demo /home/elchaschab/devel/Janosh/json-spirit/json_map_demo/CMakeFiles/json_map_demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : json_map_demo/CMakeFiles/json_map_demo.dir/depend
