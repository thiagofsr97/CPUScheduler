# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/thiagofsr/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.4343.16/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/thiagofsr/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.4343.16/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/thiagofsr/CLionProjects/CPUScheduler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/thiagofsr/CLionProjects/CPUScheduler/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CPUScheduler.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CPUScheduler.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CPUScheduler.dir/flags.make

CMakeFiles/CPUScheduler.dir/main.cpp.o: CMakeFiles/CPUScheduler.dir/flags.make
CMakeFiles/CPUScheduler.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thiagofsr/CLionProjects/CPUScheduler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CPUScheduler.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPUScheduler.dir/main.cpp.o -c /home/thiagofsr/CLionProjects/CPUScheduler/main.cpp

CMakeFiles/CPUScheduler.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPUScheduler.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thiagofsr/CLionProjects/CPUScheduler/main.cpp > CMakeFiles/CPUScheduler.dir/main.cpp.i

CMakeFiles/CPUScheduler.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPUScheduler.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thiagofsr/CLionProjects/CPUScheduler/main.cpp -o CMakeFiles/CPUScheduler.dir/main.cpp.s

CMakeFiles/CPUScheduler.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/CPUScheduler.dir/main.cpp.o.requires

CMakeFiles/CPUScheduler.dir/main.cpp.o.provides: CMakeFiles/CPUScheduler.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/CPUScheduler.dir/build.make CMakeFiles/CPUScheduler.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/CPUScheduler.dir/main.cpp.o.provides

CMakeFiles/CPUScheduler.dir/main.cpp.o.provides.build: CMakeFiles/CPUScheduler.dir/main.cpp.o


CMakeFiles/CPUScheduler.dir/Process.cpp.o: CMakeFiles/CPUScheduler.dir/flags.make
CMakeFiles/CPUScheduler.dir/Process.cpp.o: ../Process.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thiagofsr/CLionProjects/CPUScheduler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CPUScheduler.dir/Process.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPUScheduler.dir/Process.cpp.o -c /home/thiagofsr/CLionProjects/CPUScheduler/Process.cpp

CMakeFiles/CPUScheduler.dir/Process.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPUScheduler.dir/Process.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thiagofsr/CLionProjects/CPUScheduler/Process.cpp > CMakeFiles/CPUScheduler.dir/Process.cpp.i

CMakeFiles/CPUScheduler.dir/Process.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPUScheduler.dir/Process.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thiagofsr/CLionProjects/CPUScheduler/Process.cpp -o CMakeFiles/CPUScheduler.dir/Process.cpp.s

CMakeFiles/CPUScheduler.dir/Process.cpp.o.requires:

.PHONY : CMakeFiles/CPUScheduler.dir/Process.cpp.o.requires

CMakeFiles/CPUScheduler.dir/Process.cpp.o.provides: CMakeFiles/CPUScheduler.dir/Process.cpp.o.requires
	$(MAKE) -f CMakeFiles/CPUScheduler.dir/build.make CMakeFiles/CPUScheduler.dir/Process.cpp.o.provides.build
.PHONY : CMakeFiles/CPUScheduler.dir/Process.cpp.o.provides

CMakeFiles/CPUScheduler.dir/Process.cpp.o.provides.build: CMakeFiles/CPUScheduler.dir/Process.cpp.o


CMakeFiles/CPUScheduler.dir/Scheduler.cpp.o: CMakeFiles/CPUScheduler.dir/flags.make
CMakeFiles/CPUScheduler.dir/Scheduler.cpp.o: ../Scheduler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thiagofsr/CLionProjects/CPUScheduler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CPUScheduler.dir/Scheduler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPUScheduler.dir/Scheduler.cpp.o -c /home/thiagofsr/CLionProjects/CPUScheduler/Scheduler.cpp

CMakeFiles/CPUScheduler.dir/Scheduler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPUScheduler.dir/Scheduler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thiagofsr/CLionProjects/CPUScheduler/Scheduler.cpp > CMakeFiles/CPUScheduler.dir/Scheduler.cpp.i

CMakeFiles/CPUScheduler.dir/Scheduler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPUScheduler.dir/Scheduler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thiagofsr/CLionProjects/CPUScheduler/Scheduler.cpp -o CMakeFiles/CPUScheduler.dir/Scheduler.cpp.s

CMakeFiles/CPUScheduler.dir/Scheduler.cpp.o.requires:

.PHONY : CMakeFiles/CPUScheduler.dir/Scheduler.cpp.o.requires

CMakeFiles/CPUScheduler.dir/Scheduler.cpp.o.provides: CMakeFiles/CPUScheduler.dir/Scheduler.cpp.o.requires
	$(MAKE) -f CMakeFiles/CPUScheduler.dir/build.make CMakeFiles/CPUScheduler.dir/Scheduler.cpp.o.provides.build
.PHONY : CMakeFiles/CPUScheduler.dir/Scheduler.cpp.o.provides

CMakeFiles/CPUScheduler.dir/Scheduler.cpp.o.provides.build: CMakeFiles/CPUScheduler.dir/Scheduler.cpp.o


CMakeFiles/CPUScheduler.dir/FileUtils.cpp.o: CMakeFiles/CPUScheduler.dir/flags.make
CMakeFiles/CPUScheduler.dir/FileUtils.cpp.o: ../FileUtils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thiagofsr/CLionProjects/CPUScheduler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CPUScheduler.dir/FileUtils.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPUScheduler.dir/FileUtils.cpp.o -c /home/thiagofsr/CLionProjects/CPUScheduler/FileUtils.cpp

CMakeFiles/CPUScheduler.dir/FileUtils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPUScheduler.dir/FileUtils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thiagofsr/CLionProjects/CPUScheduler/FileUtils.cpp > CMakeFiles/CPUScheduler.dir/FileUtils.cpp.i

CMakeFiles/CPUScheduler.dir/FileUtils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPUScheduler.dir/FileUtils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thiagofsr/CLionProjects/CPUScheduler/FileUtils.cpp -o CMakeFiles/CPUScheduler.dir/FileUtils.cpp.s

CMakeFiles/CPUScheduler.dir/FileUtils.cpp.o.requires:

.PHONY : CMakeFiles/CPUScheduler.dir/FileUtils.cpp.o.requires

CMakeFiles/CPUScheduler.dir/FileUtils.cpp.o.provides: CMakeFiles/CPUScheduler.dir/FileUtils.cpp.o.requires
	$(MAKE) -f CMakeFiles/CPUScheduler.dir/build.make CMakeFiles/CPUScheduler.dir/FileUtils.cpp.o.provides.build
.PHONY : CMakeFiles/CPUScheduler.dir/FileUtils.cpp.o.provides

CMakeFiles/CPUScheduler.dir/FileUtils.cpp.o.provides.build: CMakeFiles/CPUScheduler.dir/FileUtils.cpp.o


# Object files for target CPUScheduler
CPUScheduler_OBJECTS = \
"CMakeFiles/CPUScheduler.dir/main.cpp.o" \
"CMakeFiles/CPUScheduler.dir/Process.cpp.o" \
"CMakeFiles/CPUScheduler.dir/Scheduler.cpp.o" \
"CMakeFiles/CPUScheduler.dir/FileUtils.cpp.o"

# External object files for target CPUScheduler
CPUScheduler_EXTERNAL_OBJECTS =

CPUScheduler: CMakeFiles/CPUScheduler.dir/main.cpp.o
CPUScheduler: CMakeFiles/CPUScheduler.dir/Process.cpp.o
CPUScheduler: CMakeFiles/CPUScheduler.dir/Scheduler.cpp.o
CPUScheduler: CMakeFiles/CPUScheduler.dir/FileUtils.cpp.o
CPUScheduler: CMakeFiles/CPUScheduler.dir/build.make
CPUScheduler: CMakeFiles/CPUScheduler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/thiagofsr/CLionProjects/CPUScheduler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable CPUScheduler"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CPUScheduler.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CPUScheduler.dir/build: CPUScheduler

.PHONY : CMakeFiles/CPUScheduler.dir/build

CMakeFiles/CPUScheduler.dir/requires: CMakeFiles/CPUScheduler.dir/main.cpp.o.requires
CMakeFiles/CPUScheduler.dir/requires: CMakeFiles/CPUScheduler.dir/Process.cpp.o.requires
CMakeFiles/CPUScheduler.dir/requires: CMakeFiles/CPUScheduler.dir/Scheduler.cpp.o.requires
CMakeFiles/CPUScheduler.dir/requires: CMakeFiles/CPUScheduler.dir/FileUtils.cpp.o.requires

.PHONY : CMakeFiles/CPUScheduler.dir/requires

CMakeFiles/CPUScheduler.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CPUScheduler.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CPUScheduler.dir/clean

CMakeFiles/CPUScheduler.dir/depend:
	cd /home/thiagofsr/CLionProjects/CPUScheduler/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/thiagofsr/CLionProjects/CPUScheduler /home/thiagofsr/CLionProjects/CPUScheduler /home/thiagofsr/CLionProjects/CPUScheduler/cmake-build-debug /home/thiagofsr/CLionProjects/CPUScheduler/cmake-build-debug /home/thiagofsr/CLionProjects/CPUScheduler/cmake-build-debug/CMakeFiles/CPUScheduler.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CPUScheduler.dir/depend

