# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.27.6/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.27.6/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/n/Projects/labs_03sem_OOP/lab-2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/n/Projects/labs_03sem_OOP/lab-2/build

# Include any dependencies generated for this target.
include CMakeFiles/tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tests.dir/flags.make

CMakeFiles/tests.dir/eleven.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/eleven.cpp.o: /Users/n/Projects/labs_03sem_OOP/lab-2/eleven.cpp
CMakeFiles/tests.dir/eleven.cpp.o: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/n/Projects/labs_03sem_OOP/lab-2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tests.dir/eleven.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/eleven.cpp.o -MF CMakeFiles/tests.dir/eleven.cpp.o.d -o CMakeFiles/tests.dir/eleven.cpp.o -c /Users/n/Projects/labs_03sem_OOP/lab-2/eleven.cpp

CMakeFiles/tests.dir/eleven.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tests.dir/eleven.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/n/Projects/labs_03sem_OOP/lab-2/eleven.cpp > CMakeFiles/tests.dir/eleven.cpp.i

CMakeFiles/tests.dir/eleven.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tests.dir/eleven.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/n/Projects/labs_03sem_OOP/lab-2/eleven.cpp -o CMakeFiles/tests.dir/eleven.cpp.s

CMakeFiles/tests.dir/tests.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/tests.cpp.o: /Users/n/Projects/labs_03sem_OOP/lab-2/tests.cpp
CMakeFiles/tests.dir/tests.cpp.o: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/n/Projects/labs_03sem_OOP/lab-2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tests.dir/tests.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/tests.cpp.o -MF CMakeFiles/tests.dir/tests.cpp.o.d -o CMakeFiles/tests.dir/tests.cpp.o -c /Users/n/Projects/labs_03sem_OOP/lab-2/tests.cpp

CMakeFiles/tests.dir/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tests.dir/tests.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/n/Projects/labs_03sem_OOP/lab-2/tests.cpp > CMakeFiles/tests.dir/tests.cpp.i

CMakeFiles/tests.dir/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tests.dir/tests.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/n/Projects/labs_03sem_OOP/lab-2/tests.cpp -o CMakeFiles/tests.dir/tests.cpp.s

# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/eleven.cpp.o" \
"CMakeFiles/tests.dir/tests.cpp.o"

# External object files for target tests
tests_EXTERNAL_OBJECTS =

tests: CMakeFiles/tests.dir/eleven.cpp.o
tests: CMakeFiles/tests.dir/tests.cpp.o
tests: CMakeFiles/tests.dir/build.make
tests: /usr/local/lib/libgtest.a
tests: CMakeFiles/tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/n/Projects/labs_03sem_OOP/lab-2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tests.dir/build: tests
.PHONY : CMakeFiles/tests.dir/build

CMakeFiles/tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tests.dir/clean

CMakeFiles/tests.dir/depend:
	cd /Users/n/Projects/labs_03sem_OOP/lab-2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/n/Projects/labs_03sem_OOP/lab-2 /Users/n/Projects/labs_03sem_OOP/lab-2 /Users/n/Projects/labs_03sem_OOP/lab-2/build /Users/n/Projects/labs_03sem_OOP/lab-2/build /Users/n/Projects/labs_03sem_OOP/lab-2/build/CMakeFiles/tests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/tests.dir/depend

