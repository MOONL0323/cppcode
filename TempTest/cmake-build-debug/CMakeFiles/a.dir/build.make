# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\opensources\CLion 2022.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\opensources\CLion 2022.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\cppcode\TempTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\cppcode\TempTest\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/a.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/a.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/a.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/a.dir/flags.make

CMakeFiles/a.dir/practice2.cpp.obj: CMakeFiles/a.dir/flags.make
CMakeFiles/a.dir/practice2.cpp.obj: ../practice2.cpp
CMakeFiles/a.dir/practice2.cpp.obj: CMakeFiles/a.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\cppcode\TempTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/a.dir/practice2.cpp.obj"
	"D:\opensources\CLion 2022.2\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/a.dir/practice2.cpp.obj -MF CMakeFiles\a.dir\practice2.cpp.obj.d -o CMakeFiles\a.dir\practice2.cpp.obj -c D:\cppcode\TempTest\practice2.cpp

CMakeFiles/a.dir/practice2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.dir/practice2.cpp.i"
	"D:\opensources\CLion 2022.2\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\cppcode\TempTest\practice2.cpp > CMakeFiles\a.dir\practice2.cpp.i

CMakeFiles/a.dir/practice2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.dir/practice2.cpp.s"
	"D:\opensources\CLion 2022.2\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\cppcode\TempTest\practice2.cpp -o CMakeFiles\a.dir\practice2.cpp.s

# Object files for target a
a_OBJECTS = \
"CMakeFiles/a.dir/practice2.cpp.obj"

# External object files for target a
a_EXTERNAL_OBJECTS =

a.exe: CMakeFiles/a.dir/practice2.cpp.obj
a.exe: CMakeFiles/a.dir/build.make
a.exe: CMakeFiles/a.dir/linklibs.rsp
a.exe: CMakeFiles/a.dir/objects1.rsp
a.exe: CMakeFiles/a.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\cppcode\TempTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable a.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\a.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/a.dir/build: a.exe
.PHONY : CMakeFiles/a.dir/build

CMakeFiles/a.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\a.dir\cmake_clean.cmake
.PHONY : CMakeFiles/a.dir/clean

CMakeFiles/a.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\cppcode\TempTest D:\cppcode\TempTest D:\cppcode\TempTest\cmake-build-debug D:\cppcode\TempTest\cmake-build-debug D:\cppcode\TempTest\cmake-build-debug\CMakeFiles\a.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/a.dir/depend
