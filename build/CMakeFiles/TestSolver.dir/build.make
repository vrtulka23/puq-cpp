# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.25.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.25.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/perseus/Projects/puq-cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/perseus/Projects/puq-cpp/build

# Include any dependencies generated for this target.
include CMakeFiles/TestSolver.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TestSolver.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TestSolver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestSolver.dir/flags.make

CMakeFiles/TestSolver.dir/tests/quantity_test.cpp.o: CMakeFiles/TestSolver.dir/flags.make
CMakeFiles/TestSolver.dir/tests/quantity_test.cpp.o: /Users/perseus/Projects/puq-cpp/tests/quantity_test.cpp
CMakeFiles/TestSolver.dir/tests/quantity_test.cpp.o: CMakeFiles/TestSolver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/perseus/Projects/puq-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestSolver.dir/tests/quantity_test.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestSolver.dir/tests/quantity_test.cpp.o -MF CMakeFiles/TestSolver.dir/tests/quantity_test.cpp.o.d -o CMakeFiles/TestSolver.dir/tests/quantity_test.cpp.o -c /Users/perseus/Projects/puq-cpp/tests/quantity_test.cpp

CMakeFiles/TestSolver.dir/tests/quantity_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestSolver.dir/tests/quantity_test.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/perseus/Projects/puq-cpp/tests/quantity_test.cpp > CMakeFiles/TestSolver.dir/tests/quantity_test.cpp.i

CMakeFiles/TestSolver.dir/tests/quantity_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestSolver.dir/tests/quantity_test.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/perseus/Projects/puq-cpp/tests/quantity_test.cpp -o CMakeFiles/TestSolver.dir/tests/quantity_test.cpp.s

CMakeFiles/TestSolver.dir/tests/unit_solver_test.cpp.o: CMakeFiles/TestSolver.dir/flags.make
CMakeFiles/TestSolver.dir/tests/unit_solver_test.cpp.o: /Users/perseus/Projects/puq-cpp/tests/unit_solver_test.cpp
CMakeFiles/TestSolver.dir/tests/unit_solver_test.cpp.o: CMakeFiles/TestSolver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/perseus/Projects/puq-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TestSolver.dir/tests/unit_solver_test.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestSolver.dir/tests/unit_solver_test.cpp.o -MF CMakeFiles/TestSolver.dir/tests/unit_solver_test.cpp.o.d -o CMakeFiles/TestSolver.dir/tests/unit_solver_test.cpp.o -c /Users/perseus/Projects/puq-cpp/tests/unit_solver_test.cpp

CMakeFiles/TestSolver.dir/tests/unit_solver_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestSolver.dir/tests/unit_solver_test.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/perseus/Projects/puq-cpp/tests/unit_solver_test.cpp > CMakeFiles/TestSolver.dir/tests/unit_solver_test.cpp.i

CMakeFiles/TestSolver.dir/tests/unit_solver_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestSolver.dir/tests/unit_solver_test.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/perseus/Projects/puq-cpp/tests/unit_solver_test.cpp -o CMakeFiles/TestSolver.dir/tests/unit_solver_test.cpp.s

CMakeFiles/TestSolver.dir/src/magnitude.cpp.o: CMakeFiles/TestSolver.dir/flags.make
CMakeFiles/TestSolver.dir/src/magnitude.cpp.o: /Users/perseus/Projects/puq-cpp/src/magnitude.cpp
CMakeFiles/TestSolver.dir/src/magnitude.cpp.o: CMakeFiles/TestSolver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/perseus/Projects/puq-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TestSolver.dir/src/magnitude.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestSolver.dir/src/magnitude.cpp.o -MF CMakeFiles/TestSolver.dir/src/magnitude.cpp.o.d -o CMakeFiles/TestSolver.dir/src/magnitude.cpp.o -c /Users/perseus/Projects/puq-cpp/src/magnitude.cpp

CMakeFiles/TestSolver.dir/src/magnitude.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestSolver.dir/src/magnitude.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/perseus/Projects/puq-cpp/src/magnitude.cpp > CMakeFiles/TestSolver.dir/src/magnitude.cpp.i

CMakeFiles/TestSolver.dir/src/magnitude.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestSolver.dir/src/magnitude.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/perseus/Projects/puq-cpp/src/magnitude.cpp -o CMakeFiles/TestSolver.dir/src/magnitude.cpp.s

CMakeFiles/TestSolver.dir/src/quantity.cpp.o: CMakeFiles/TestSolver.dir/flags.make
CMakeFiles/TestSolver.dir/src/quantity.cpp.o: /Users/perseus/Projects/puq-cpp/src/quantity.cpp
CMakeFiles/TestSolver.dir/src/quantity.cpp.o: CMakeFiles/TestSolver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/perseus/Projects/puq-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TestSolver.dir/src/quantity.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestSolver.dir/src/quantity.cpp.o -MF CMakeFiles/TestSolver.dir/src/quantity.cpp.o.d -o CMakeFiles/TestSolver.dir/src/quantity.cpp.o -c /Users/perseus/Projects/puq-cpp/src/quantity.cpp

CMakeFiles/TestSolver.dir/src/quantity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestSolver.dir/src/quantity.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/perseus/Projects/puq-cpp/src/quantity.cpp > CMakeFiles/TestSolver.dir/src/quantity.cpp.i

CMakeFiles/TestSolver.dir/src/quantity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestSolver.dir/src/quantity.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/perseus/Projects/puq-cpp/src/quantity.cpp -o CMakeFiles/TestSolver.dir/src/quantity.cpp.s

CMakeFiles/TestSolver.dir/src/unit_solver/atom.cpp.o: CMakeFiles/TestSolver.dir/flags.make
CMakeFiles/TestSolver.dir/src/unit_solver/atom.cpp.o: /Users/perseus/Projects/puq-cpp/src/unit_solver/atom.cpp
CMakeFiles/TestSolver.dir/src/unit_solver/atom.cpp.o: CMakeFiles/TestSolver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/perseus/Projects/puq-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/TestSolver.dir/src/unit_solver/atom.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestSolver.dir/src/unit_solver/atom.cpp.o -MF CMakeFiles/TestSolver.dir/src/unit_solver/atom.cpp.o.d -o CMakeFiles/TestSolver.dir/src/unit_solver/atom.cpp.o -c /Users/perseus/Projects/puq-cpp/src/unit_solver/atom.cpp

CMakeFiles/TestSolver.dir/src/unit_solver/atom.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestSolver.dir/src/unit_solver/atom.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/perseus/Projects/puq-cpp/src/unit_solver/atom.cpp > CMakeFiles/TestSolver.dir/src/unit_solver/atom.cpp.i

CMakeFiles/TestSolver.dir/src/unit_solver/atom.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestSolver.dir/src/unit_solver/atom.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/perseus/Projects/puq-cpp/src/unit_solver/atom.cpp -o CMakeFiles/TestSolver.dir/src/unit_solver/atom.cpp.s

CMakeFiles/TestSolver.dir/src/unit_solver/settings.cpp.o: CMakeFiles/TestSolver.dir/flags.make
CMakeFiles/TestSolver.dir/src/unit_solver/settings.cpp.o: /Users/perseus/Projects/puq-cpp/src/unit_solver/settings.cpp
CMakeFiles/TestSolver.dir/src/unit_solver/settings.cpp.o: CMakeFiles/TestSolver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/perseus/Projects/puq-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/TestSolver.dir/src/unit_solver/settings.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestSolver.dir/src/unit_solver/settings.cpp.o -MF CMakeFiles/TestSolver.dir/src/unit_solver/settings.cpp.o.d -o CMakeFiles/TestSolver.dir/src/unit_solver/settings.cpp.o -c /Users/perseus/Projects/puq-cpp/src/unit_solver/settings.cpp

CMakeFiles/TestSolver.dir/src/unit_solver/settings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestSolver.dir/src/unit_solver/settings.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/perseus/Projects/puq-cpp/src/unit_solver/settings.cpp > CMakeFiles/TestSolver.dir/src/unit_solver/settings.cpp.i

CMakeFiles/TestSolver.dir/src/unit_solver/settings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestSolver.dir/src/unit_solver/settings.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/perseus/Projects/puq-cpp/src/unit_solver/settings.cpp -o CMakeFiles/TestSolver.dir/src/unit_solver/settings.cpp.s

CMakeFiles/TestSolver.dir/src/unit_solver/solver.cpp.o: CMakeFiles/TestSolver.dir/flags.make
CMakeFiles/TestSolver.dir/src/unit_solver/solver.cpp.o: /Users/perseus/Projects/puq-cpp/src/unit_solver/solver.cpp
CMakeFiles/TestSolver.dir/src/unit_solver/solver.cpp.o: CMakeFiles/TestSolver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/perseus/Projects/puq-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/TestSolver.dir/src/unit_solver/solver.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestSolver.dir/src/unit_solver/solver.cpp.o -MF CMakeFiles/TestSolver.dir/src/unit_solver/solver.cpp.o.d -o CMakeFiles/TestSolver.dir/src/unit_solver/solver.cpp.o -c /Users/perseus/Projects/puq-cpp/src/unit_solver/solver.cpp

CMakeFiles/TestSolver.dir/src/unit_solver/solver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestSolver.dir/src/unit_solver/solver.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/perseus/Projects/puq-cpp/src/unit_solver/solver.cpp > CMakeFiles/TestSolver.dir/src/unit_solver/solver.cpp.i

CMakeFiles/TestSolver.dir/src/unit_solver/solver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestSolver.dir/src/unit_solver/solver.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/perseus/Projects/puq-cpp/src/unit_solver/solver.cpp -o CMakeFiles/TestSolver.dir/src/unit_solver/solver.cpp.s

CMakeFiles/TestSolver.dir/src/unit_solver/unit_lists.cpp.o: CMakeFiles/TestSolver.dir/flags.make
CMakeFiles/TestSolver.dir/src/unit_solver/unit_lists.cpp.o: /Users/perseus/Projects/puq-cpp/src/unit_solver/unit_lists.cpp
CMakeFiles/TestSolver.dir/src/unit_solver/unit_lists.cpp.o: CMakeFiles/TestSolver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/perseus/Projects/puq-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/TestSolver.dir/src/unit_solver/unit_lists.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestSolver.dir/src/unit_solver/unit_lists.cpp.o -MF CMakeFiles/TestSolver.dir/src/unit_solver/unit_lists.cpp.o.d -o CMakeFiles/TestSolver.dir/src/unit_solver/unit_lists.cpp.o -c /Users/perseus/Projects/puq-cpp/src/unit_solver/unit_lists.cpp

CMakeFiles/TestSolver.dir/src/unit_solver/unit_lists.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestSolver.dir/src/unit_solver/unit_lists.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/perseus/Projects/puq-cpp/src/unit_solver/unit_lists.cpp > CMakeFiles/TestSolver.dir/src/unit_solver/unit_lists.cpp.i

CMakeFiles/TestSolver.dir/src/unit_solver/unit_lists.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestSolver.dir/src/unit_solver/unit_lists.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/perseus/Projects/puq-cpp/src/unit_solver/unit_lists.cpp -o CMakeFiles/TestSolver.dir/src/unit_solver/unit_lists.cpp.s

# Object files for target TestSolver
TestSolver_OBJECTS = \
"CMakeFiles/TestSolver.dir/tests/quantity_test.cpp.o" \
"CMakeFiles/TestSolver.dir/tests/unit_solver_test.cpp.o" \
"CMakeFiles/TestSolver.dir/src/magnitude.cpp.o" \
"CMakeFiles/TestSolver.dir/src/quantity.cpp.o" \
"CMakeFiles/TestSolver.dir/src/unit_solver/atom.cpp.o" \
"CMakeFiles/TestSolver.dir/src/unit_solver/settings.cpp.o" \
"CMakeFiles/TestSolver.dir/src/unit_solver/solver.cpp.o" \
"CMakeFiles/TestSolver.dir/src/unit_solver/unit_lists.cpp.o"

# External object files for target TestSolver
TestSolver_EXTERNAL_OBJECTS =

TestSolver: CMakeFiles/TestSolver.dir/tests/quantity_test.cpp.o
TestSolver: CMakeFiles/TestSolver.dir/tests/unit_solver_test.cpp.o
TestSolver: CMakeFiles/TestSolver.dir/src/magnitude.cpp.o
TestSolver: CMakeFiles/TestSolver.dir/src/quantity.cpp.o
TestSolver: CMakeFiles/TestSolver.dir/src/unit_solver/atom.cpp.o
TestSolver: CMakeFiles/TestSolver.dir/src/unit_solver/settings.cpp.o
TestSolver: CMakeFiles/TestSolver.dir/src/unit_solver/solver.cpp.o
TestSolver: CMakeFiles/TestSolver.dir/src/unit_solver/unit_lists.cpp.o
TestSolver: CMakeFiles/TestSolver.dir/build.make
TestSolver: /opt/homebrew/lib/libgtest_main.a
TestSolver: /opt/homebrew/lib/libgtest.a
TestSolver: CMakeFiles/TestSolver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/perseus/Projects/puq-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable TestSolver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestSolver.dir/link.txt --verbose=$(VERBOSE)
	/opt/homebrew/Cellar/cmake/3.25.1/bin/cmake -D TEST_TARGET=TestSolver -D TEST_EXECUTABLE=/Users/perseus/Projects/puq-cpp/build/TestSolver -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/Users/perseus/Projects/puq-cpp/build -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=TestSolver_TESTS -D CTEST_FILE=/Users/perseus/Projects/puq-cpp/build/TestSolver[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /opt/homebrew/Cellar/cmake/3.25.1/share/cmake/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
CMakeFiles/TestSolver.dir/build: TestSolver
.PHONY : CMakeFiles/TestSolver.dir/build

CMakeFiles/TestSolver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestSolver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestSolver.dir/clean

CMakeFiles/TestSolver.dir/depend:
	cd /Users/perseus/Projects/puq-cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/perseus/Projects/puq-cpp /Users/perseus/Projects/puq-cpp /Users/perseus/Projects/puq-cpp/build /Users/perseus/Projects/puq-cpp/build /Users/perseus/Projects/puq-cpp/build/CMakeFiles/TestSolver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TestSolver.dir/depend

