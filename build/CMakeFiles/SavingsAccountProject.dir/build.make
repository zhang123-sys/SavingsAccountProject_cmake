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
CMAKE_SOURCE_DIR = /root/cpp_project/SavingsAccountProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/cpp_project/SavingsAccountProject/build

# Include any dependencies generated for this target.
include CMakeFiles/SavingsAccountProject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SavingsAccountProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SavingsAccountProject.dir/flags.make

CMakeFiles/SavingsAccountProject.dir/src/account.cpp.o: CMakeFiles/SavingsAccountProject.dir/flags.make
CMakeFiles/SavingsAccountProject.dir/src/account.cpp.o: ../src/account.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/cpp_project/SavingsAccountProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SavingsAccountProject.dir/src/account.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SavingsAccountProject.dir/src/account.cpp.o -c /root/cpp_project/SavingsAccountProject/src/account.cpp

CMakeFiles/SavingsAccountProject.dir/src/account.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SavingsAccountProject.dir/src/account.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/cpp_project/SavingsAccountProject/src/account.cpp > CMakeFiles/SavingsAccountProject.dir/src/account.cpp.i

CMakeFiles/SavingsAccountProject.dir/src/account.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SavingsAccountProject.dir/src/account.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/cpp_project/SavingsAccountProject/src/account.cpp -o CMakeFiles/SavingsAccountProject.dir/src/account.cpp.s

CMakeFiles/SavingsAccountProject.dir/src/account.cpp.o.requires:

.PHONY : CMakeFiles/SavingsAccountProject.dir/src/account.cpp.o.requires

CMakeFiles/SavingsAccountProject.dir/src/account.cpp.o.provides: CMakeFiles/SavingsAccountProject.dir/src/account.cpp.o.requires
	$(MAKE) -f CMakeFiles/SavingsAccountProject.dir/build.make CMakeFiles/SavingsAccountProject.dir/src/account.cpp.o.provides.build
.PHONY : CMakeFiles/SavingsAccountProject.dir/src/account.cpp.o.provides

CMakeFiles/SavingsAccountProject.dir/src/account.cpp.o.provides.build: CMakeFiles/SavingsAccountProject.dir/src/account.cpp.o


CMakeFiles/SavingsAccountProject.dir/src/date.cpp.o: CMakeFiles/SavingsAccountProject.dir/flags.make
CMakeFiles/SavingsAccountProject.dir/src/date.cpp.o: ../src/date.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/cpp_project/SavingsAccountProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SavingsAccountProject.dir/src/date.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SavingsAccountProject.dir/src/date.cpp.o -c /root/cpp_project/SavingsAccountProject/src/date.cpp

CMakeFiles/SavingsAccountProject.dir/src/date.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SavingsAccountProject.dir/src/date.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/cpp_project/SavingsAccountProject/src/date.cpp > CMakeFiles/SavingsAccountProject.dir/src/date.cpp.i

CMakeFiles/SavingsAccountProject.dir/src/date.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SavingsAccountProject.dir/src/date.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/cpp_project/SavingsAccountProject/src/date.cpp -o CMakeFiles/SavingsAccountProject.dir/src/date.cpp.s

CMakeFiles/SavingsAccountProject.dir/src/date.cpp.o.requires:

.PHONY : CMakeFiles/SavingsAccountProject.dir/src/date.cpp.o.requires

CMakeFiles/SavingsAccountProject.dir/src/date.cpp.o.provides: CMakeFiles/SavingsAccountProject.dir/src/date.cpp.o.requires
	$(MAKE) -f CMakeFiles/SavingsAccountProject.dir/build.make CMakeFiles/SavingsAccountProject.dir/src/date.cpp.o.provides.build
.PHONY : CMakeFiles/SavingsAccountProject.dir/src/date.cpp.o.provides

CMakeFiles/SavingsAccountProject.dir/src/date.cpp.o.provides.build: CMakeFiles/SavingsAccountProject.dir/src/date.cpp.o


CMakeFiles/SavingsAccountProject.dir/src/main.cpp.o: CMakeFiles/SavingsAccountProject.dir/flags.make
CMakeFiles/SavingsAccountProject.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/cpp_project/SavingsAccountProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SavingsAccountProject.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SavingsAccountProject.dir/src/main.cpp.o -c /root/cpp_project/SavingsAccountProject/src/main.cpp

CMakeFiles/SavingsAccountProject.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SavingsAccountProject.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/cpp_project/SavingsAccountProject/src/main.cpp > CMakeFiles/SavingsAccountProject.dir/src/main.cpp.i

CMakeFiles/SavingsAccountProject.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SavingsAccountProject.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/cpp_project/SavingsAccountProject/src/main.cpp -o CMakeFiles/SavingsAccountProject.dir/src/main.cpp.s

CMakeFiles/SavingsAccountProject.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/SavingsAccountProject.dir/src/main.cpp.o.requires

CMakeFiles/SavingsAccountProject.dir/src/main.cpp.o.provides: CMakeFiles/SavingsAccountProject.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/SavingsAccountProject.dir/build.make CMakeFiles/SavingsAccountProject.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/SavingsAccountProject.dir/src/main.cpp.o.provides

CMakeFiles/SavingsAccountProject.dir/src/main.cpp.o.provides.build: CMakeFiles/SavingsAccountProject.dir/src/main.cpp.o


# Object files for target SavingsAccountProject
SavingsAccountProject_OBJECTS = \
"CMakeFiles/SavingsAccountProject.dir/src/account.cpp.o" \
"CMakeFiles/SavingsAccountProject.dir/src/date.cpp.o" \
"CMakeFiles/SavingsAccountProject.dir/src/main.cpp.o"

# External object files for target SavingsAccountProject
SavingsAccountProject_EXTERNAL_OBJECTS =

SavingsAccountProject: CMakeFiles/SavingsAccountProject.dir/src/account.cpp.o
SavingsAccountProject: CMakeFiles/SavingsAccountProject.dir/src/date.cpp.o
SavingsAccountProject: CMakeFiles/SavingsAccountProject.dir/src/main.cpp.o
SavingsAccountProject: CMakeFiles/SavingsAccountProject.dir/build.make
SavingsAccountProject: CMakeFiles/SavingsAccountProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/cpp_project/SavingsAccountProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable SavingsAccountProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SavingsAccountProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SavingsAccountProject.dir/build: SavingsAccountProject

.PHONY : CMakeFiles/SavingsAccountProject.dir/build

CMakeFiles/SavingsAccountProject.dir/requires: CMakeFiles/SavingsAccountProject.dir/src/account.cpp.o.requires
CMakeFiles/SavingsAccountProject.dir/requires: CMakeFiles/SavingsAccountProject.dir/src/date.cpp.o.requires
CMakeFiles/SavingsAccountProject.dir/requires: CMakeFiles/SavingsAccountProject.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/SavingsAccountProject.dir/requires

CMakeFiles/SavingsAccountProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SavingsAccountProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SavingsAccountProject.dir/clean

CMakeFiles/SavingsAccountProject.dir/depend:
	cd /root/cpp_project/SavingsAccountProject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/cpp_project/SavingsAccountProject /root/cpp_project/SavingsAccountProject /root/cpp_project/SavingsAccountProject/build /root/cpp_project/SavingsAccountProject/build /root/cpp_project/SavingsAccountProject/build/CMakeFiles/SavingsAccountProject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SavingsAccountProject.dir/depend

