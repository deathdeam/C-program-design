# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\lenovo\Desktop\algorithm\c++\homework\hw10

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\lenovo\Desktop\algorithm\c++\homework\hw10\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/hw10.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/hw10.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hw10.dir/flags.make

CMakeFiles/hw10.dir/main.cpp.obj: CMakeFiles/hw10.dir/flags.make
CMakeFiles/hw10.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\lenovo\Desktop\algorithm\c++\homework\hw10\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hw10.dir/main.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\hw10.dir\main.cpp.obj -c C:\Users\lenovo\Desktop\algorithm\c++\homework\hw10\main.cpp

CMakeFiles/hw10.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw10.dir/main.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lenovo\Desktop\algorithm\c++\homework\hw10\main.cpp > CMakeFiles\hw10.dir\main.cpp.i

CMakeFiles/hw10.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw10.dir/main.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lenovo\Desktop\algorithm\c++\homework\hw10\main.cpp -o CMakeFiles\hw10.dir\main.cpp.s

# Object files for target hw10
hw10_OBJECTS = \
"CMakeFiles/hw10.dir/main.cpp.obj"

# External object files for target hw10
hw10_EXTERNAL_OBJECTS =

hw10.exe: CMakeFiles/hw10.dir/main.cpp.obj
hw10.exe: CMakeFiles/hw10.dir/build.make
hw10.exe: CMakeFiles/hw10.dir/linklibs.rsp
hw10.exe: CMakeFiles/hw10.dir/objects1.rsp
hw10.exe: CMakeFiles/hw10.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\lenovo\Desktop\algorithm\c++\homework\hw10\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hw10.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\hw10.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hw10.dir/build: hw10.exe
.PHONY : CMakeFiles/hw10.dir/build

CMakeFiles/hw10.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\hw10.dir\cmake_clean.cmake
.PHONY : CMakeFiles/hw10.dir/clean

CMakeFiles/hw10.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\lenovo\Desktop\algorithm\c++\homework\hw10 C:\Users\lenovo\Desktop\algorithm\c++\homework\hw10 C:\Users\lenovo\Desktop\algorithm\c++\homework\hw10\cmake-build-debug C:\Users\lenovo\Desktop\algorithm\c++\homework\hw10\cmake-build-debug C:\Users\lenovo\Desktop\algorithm\c++\homework\hw10\cmake-build-debug\CMakeFiles\hw10.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hw10.dir/depend

