# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\clion\151

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\clion\151\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/151.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/151.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/151.dir/flags.make

CMakeFiles/151.dir/main.cpp.obj: CMakeFiles/151.dir/flags.make
CMakeFiles/151.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\clion\151\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/151.dir/main.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\151.dir\main.cpp.obj -c E:\clion\151\main.cpp

CMakeFiles/151.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/151.dir/main.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\clion\151\main.cpp > CMakeFiles\151.dir\main.cpp.i

CMakeFiles/151.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/151.dir/main.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\clion\151\main.cpp -o CMakeFiles\151.dir\main.cpp.s

# Object files for target 151
151_OBJECTS = \
"CMakeFiles/151.dir/main.cpp.obj"

# External object files for target 151
151_EXTERNAL_OBJECTS =

151.exe: CMakeFiles/151.dir/main.cpp.obj
151.exe: CMakeFiles/151.dir/build.make
151.exe: CMakeFiles/151.dir/linklibs.rsp
151.exe: CMakeFiles/151.dir/objects1.rsp
151.exe: CMakeFiles/151.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\clion\151\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 151.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\151.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/151.dir/build: 151.exe

.PHONY : CMakeFiles/151.dir/build

CMakeFiles/151.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\151.dir\cmake_clean.cmake
.PHONY : CMakeFiles/151.dir/clean

CMakeFiles/151.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\clion\151 E:\clion\151 E:\clion\151\cmake-build-debug E:\clion\151\cmake-build-debug E:\clion\151\cmake-build-debug\CMakeFiles\151.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/151.dir/depend

