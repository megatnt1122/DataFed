# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cloud/DataFed/DataFed

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cloud/DataFed/DataFed

# Include any dependencies generated for this target.
include core/server/CMakeFiles/datafed-core-lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include core/server/CMakeFiles/datafed-core-lib.dir/compiler_depend.make

# Include the progress variables for this target.
include core/server/CMakeFiles/datafed-core-lib.dir/progress.make

# Include the compile flags for this target's objects.
include core/server/CMakeFiles/datafed-core-lib.dir/flags.make

core/server/CMakeFiles/datafed-core-lib.dir/AuthMap.cpp.o: core/server/CMakeFiles/datafed-core-lib.dir/flags.make
core/server/CMakeFiles/datafed-core-lib.dir/AuthMap.cpp.o: core/server/AuthMap.cpp
core/server/CMakeFiles/datafed-core-lib.dir/AuthMap.cpp.o: core/server/CMakeFiles/datafed-core-lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cloud/DataFed/DataFed/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object core/server/CMakeFiles/datafed-core-lib.dir/AuthMap.cpp.o"
	cd /home/cloud/DataFed/DataFed/core/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT core/server/CMakeFiles/datafed-core-lib.dir/AuthMap.cpp.o -MF CMakeFiles/datafed-core-lib.dir/AuthMap.cpp.o.d -o CMakeFiles/datafed-core-lib.dir/AuthMap.cpp.o -c /home/cloud/DataFed/DataFed/core/server/AuthMap.cpp

core/server/CMakeFiles/datafed-core-lib.dir/AuthMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/datafed-core-lib.dir/AuthMap.cpp.i"
	cd /home/cloud/DataFed/DataFed/core/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cloud/DataFed/DataFed/core/server/AuthMap.cpp > CMakeFiles/datafed-core-lib.dir/AuthMap.cpp.i

core/server/CMakeFiles/datafed-core-lib.dir/AuthMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/datafed-core-lib.dir/AuthMap.cpp.s"
	cd /home/cloud/DataFed/DataFed/core/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cloud/DataFed/DataFed/core/server/AuthMap.cpp -o CMakeFiles/datafed-core-lib.dir/AuthMap.cpp.s

core/server/CMakeFiles/datafed-core-lib.dir/AuthenticationManager.cpp.o: core/server/CMakeFiles/datafed-core-lib.dir/flags.make
core/server/CMakeFiles/datafed-core-lib.dir/AuthenticationManager.cpp.o: core/server/AuthenticationManager.cpp
core/server/CMakeFiles/datafed-core-lib.dir/AuthenticationManager.cpp.o: core/server/CMakeFiles/datafed-core-lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cloud/DataFed/DataFed/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object core/server/CMakeFiles/datafed-core-lib.dir/AuthenticationManager.cpp.o"
	cd /home/cloud/DataFed/DataFed/core/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT core/server/CMakeFiles/datafed-core-lib.dir/AuthenticationManager.cpp.o -MF CMakeFiles/datafed-core-lib.dir/AuthenticationManager.cpp.o.d -o CMakeFiles/datafed-core-lib.dir/AuthenticationManager.cpp.o -c /home/cloud/DataFed/DataFed/core/server/AuthenticationManager.cpp

core/server/CMakeFiles/datafed-core-lib.dir/AuthenticationManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/datafed-core-lib.dir/AuthenticationManager.cpp.i"
	cd /home/cloud/DataFed/DataFed/core/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cloud/DataFed/DataFed/core/server/AuthenticationManager.cpp > CMakeFiles/datafed-core-lib.dir/AuthenticationManager.cpp.i

core/server/CMakeFiles/datafed-core-lib.dir/AuthenticationManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/datafed-core-lib.dir/AuthenticationManager.cpp.s"
	cd /home/cloud/DataFed/DataFed/core/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cloud/DataFed/DataFed/core/server/AuthenticationManager.cpp -o CMakeFiles/datafed-core-lib.dir/AuthenticationManager.cpp.s

core/server/CMakeFiles/datafed-core-lib.dir/ClientWorker.cpp.o: core/server/CMakeFiles/datafed-core-lib.dir/flags.make
core/server/CMakeFiles/datafed-core-lib.dir/ClientWorker.cpp.o: core/server/ClientWorker.cpp
core/server/CMakeFiles/datafed-core-lib.dir/ClientWorker.cpp.o: core/server/CMakeFiles/datafed-core-lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cloud/DataFed/DataFed/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object core/server/CMakeFiles/datafed-core-lib.dir/ClientWorker.cpp.o"
	cd /home/cloud/DataFed/DataFed/core/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT core/server/CMakeFiles/datafed-core-lib.dir/ClientWorker.cpp.o -MF CMakeFiles/datafed-core-lib.dir/ClientWorker.cpp.o.d -o CMakeFiles/datafed-core-lib.dir/ClientWorker.cpp.o -c /home/cloud/DataFed/DataFed/core/server/ClientWorker.cpp

core/server/CMakeFiles/datafed-core-lib.dir/ClientWorker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/datafed-core-lib.dir/ClientWorker.cpp.i"
	cd /home/cloud/DataFed/DataFed/core/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cloud/DataFed/DataFed/core/server/ClientWorker.cpp > CMakeFiles/datafed-core-lib.dir/ClientWorker.cpp.i

core/server/CMakeFiles/datafed-core-lib.dir/ClientWorker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/datafed-core-lib.dir/ClientWorker.cpp.s"
	cd /home/cloud/DataFed/DataFed/core/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cloud/DataFed/DataFed/core/server/ClientWorker.cpp -o CMakeFiles/datafed-core-lib.dir/ClientWorker.cpp.s

core/server/CMakeFiles/datafed-core-lib.dir/Condition.cpp.o: core/server/CMakeFiles/datafed-core-lib.dir/flags.make
core/server/CMakeFiles/datafed-core-lib.dir/Condition.cpp.o: core/server/Condition.cpp
core/server/CMakeFiles/datafed-core-lib.dir/Condition.cpp.o: core/server/CMakeFiles/datafed-core-lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cloud/DataFed/DataFed/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object core/server/CMakeFiles/datafed-core-lib.dir/Condition.cpp.o"
	cd /home/cloud/DataFed/DataFed/core/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT core/server/CMakeFiles/datafed-core-lib.dir/Condition.cpp.o -MF CMakeFiles/datafed-core-lib.dir/Condition.cpp.o.d -o CMakeFiles/datafed-core-lib.dir/Condition.cpp.o -c /home/cloud/DataFed/DataFed/core/server/Condition.cpp

core/server/CMakeFiles/datafed-core-lib.dir/Condition.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/datafed-core-lib.dir/Condition.cpp.i"
	cd /home/cloud/DataFed/DataFed/core/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cloud/DataFed/DataFed/core/server/Condition.cpp > CMakeFiles/datafed-core-lib.dir/Condition.cpp.i

core/server/CMakeFiles/datafed-core-lib.dir/Condition.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/datafed-core-lib.dir/Condition.cpp.s"
	cd /home/cloud/DataFed/DataFed/core/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cloud/DataFed/DataFed/core/server/Condition.cpp -o CMakeFiles/datafed-core-lib.dir/Condition.cpp.s

core/server/CMakeFiles/datafed-core-lib.dir/Config.cpp.o: core/server/CMakeFiles/datafed-core-lib.dir/flags.make
core/server/CMakeFiles/datafed-core-lib.dir/Config.cpp.o: core/server/Config.cpp
core/server/CMakeFiles/datafed-core-lib.dir/Config.cpp.o: core/server/CMakeFiles/datafed-core-lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cloud/DataFed/DataFed/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object core/server/CMakeFiles/datafed-core-lib.dir/Config.cpp.o"
	cd /home/cloud/DataFed/DataFed/core/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT core/server/CMakeFiles/datafed-core-lib.dir/Config.cpp.o -MF CMakeFiles/datafed-core-lib.dir/Config.cpp.o.d -o CMakeFiles/datafed-core-lib.dir/Config.cpp.o -c /home/cloud/DataFed/DataFed/core/server/Config.cpp

core/server/CMakeFiles/datafed-core-lib.dir/Config.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/datafed-core-lib.dir/Config.cpp.i"
	cd /home/cloud/DataFed/DataFed/core/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cloud/DataFed/DataFed/core/server/Config.cpp > CMakeFiles/datafed-core-lib.dir/Config.cpp.i

core/server/CMakeFiles/datafed-core-lib.dir/Config.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/datafed-core-lib.dir/Config.cpp.s"
	cd /home/cloud/DataFed/DataFed/core/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cloud/DataFed/DataFed/core/server/Config.cpp -o CMakeFiles/datafed-core-lib.dir/Config.cpp.s

core/server/CMakeFiles/datafed-core-lib.dir/CoreServer.cpp.o: core/server/CMakeFiles/datafed-core-lib.dir/flags.make
core/server/CMakeFiles/datafed-core-lib.dir/CoreServer.cpp.o: core/server/CoreServer.cpp
core/server/CMakeFiles/datafed-core-lib.dir/CoreServer.cpp.o: core/server/CMakeFiles/datafed-core-lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cloud/DataFed/DataFed/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object core/server/CMakeFiles/datafed-core-lib.dir/CoreServer.cpp.o"
	cd /home/cloud/DataFed/DataFed/core/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT core/server/CMakeFiles/datafed-core-lib.dir/CoreServer.cpp.o -MF CMakeFiles/datafed-core-lib.dir/CoreServer.cpp.o.d -o CMakeFiles/datafed-core-lib.dir/CoreServer.cpp.o -c /home/cloud/DataFed/DataFed/core/server/CoreServer.cpp

core/server/CMakeFiles/datafed-core-lib.dir/CoreServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/datafed-core-lib.dir/CoreServer.cpp.i"
	cd /home/cloud/DataFed/DataFed/core/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cloud/DataFed/DataFed/core/server/CoreServer.cpp > CMakeFiles/datafed-core-lib.dir/CoreServer.cpp.i

core/server/CMakeFiles/datafed-core-lib.dir/CoreServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/datafed-core-lib.dir/CoreServer.cpp.s"
	cd /home/cloud/DataFed/DataFed/core/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cloud/DataFed/DataFed/core/server/CoreServer.cpp -o CMakeFiles/datafed-core-lib.dir/CoreServer.cpp.s

core/server/CMakeFiles/datafed-core-lib.dir/DatabaseAPI.cpp.o: core/server/CMakeFiles/datafed-core-lib.dir/flags.make
core/server/CMakeFiles/datafed-core-lib.dir/DatabaseAPI.cpp.o: core/server/DatabaseAPI.cpp
core/server/CMakeFiles/datafed-core-lib.dir/DatabaseAPI.cpp.o: core/server/CMakeFiles/datafed-core-lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cloud/DataFed/DataFed/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object core/server/CMakeFiles/datafed-core-lib.dir/DatabaseAPI.cpp.o"
	cd /home/cloud/DataFed/DataFed/core/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT core/server/CMakeFiles/datafed-core-lib.dir/DatabaseAPI.cpp.o -MF CMakeFiles/datafed-core-lib.dir/DatabaseAPI.cpp.o.d -o CMakeFiles/datafed-core-lib.dir/DatabaseAPI.cpp.o -c /home/cloud/DataFed/DataFed/core/server/DatabaseAPI.cpp

core/server/CMakeFiles/datafed-core-lib.dir/DatabaseAPI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/datafed-core-lib.dir/DatabaseAPI.cpp.i"
	cd /home/cloud/DataFed/DataFed/core/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cloud/DataFed/DataFed/core/server/DatabaseAPI.cpp > CMakeFiles/datafed-core-lib.dir/DatabaseAPI.cpp.i

core/server/CMakeFiles/datafed-core-lib.dir/DatabaseAPI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/datafed-core-lib.dir/DatabaseAPI.cpp.s"
	cd /home/cloud/DataFed/DataFed/core/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cloud/DataFed/DataFed/core/server/DatabaseAPI.cpp -o CMakeFiles/datafed-core-lib.dir/DatabaseAPI.cpp.s

core/server/CMakeFiles/datafed-core-lib.dir/GlobusAPI.cpp.o: core/server/CMakeFiles/datafed-core-lib.dir/flags.make
core/server/CMakeFiles/datafed-core-lib.dir/GlobusAPI.cpp.o: core/server/GlobusAPI.cpp
core/server/CMakeFiles/datafed-core-lib.dir/GlobusAPI.cpp.o: core/server/CMakeFiles/datafed-core-lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cloud/DataFed/DataFed/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object core/server/CMakeFiles/datafed-core-lib.dir/GlobusAPI.cpp.o"
	cd /home/cloud/DataFed/DataFed/core/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT core/server/CMakeFiles/datafed-core-lib.dir/GlobusAPI.cpp.o -MF CMakeFiles/datafed-core-lib.dir/GlobusAPI.cpp.o.d -o CMakeFiles/datafed-core-lib.dir/GlobusAPI.cpp.o -c /home/cloud/DataFed/DataFed/core/server/GlobusAPI.cpp

core/server/CMakeFiles/datafed-core-lib.dir/GlobusAPI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/datafed-core-lib.dir/GlobusAPI.cpp.i"
	cd /home/cloud/DataFed/DataFed/core/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cloud/DataFed/DataFed/core/server/GlobusAPI.cpp > CMakeFiles/datafed-core-lib.dir/GlobusAPI.cpp.i

core/server/CMakeFiles/datafed-core-lib.dir/GlobusAPI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/datafed-core-lib.dir/GlobusAPI.cpp.s"
	cd /home/cloud/DataFed/DataFed/core/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cloud/DataFed/DataFed/core/server/GlobusAPI.cpp -o CMakeFiles/datafed-core-lib.dir/GlobusAPI.cpp.s

core/server/CMakeFiles/datafed-core-lib.dir/TaskMgr.cpp.o: core/server/CMakeFiles/datafed-core-lib.dir/flags.make
core/server/CMakeFiles/datafed-core-lib.dir/TaskMgr.cpp.o: core/server/TaskMgr.cpp
core/server/CMakeFiles/datafed-core-lib.dir/TaskMgr.cpp.o: core/server/CMakeFiles/datafed-core-lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cloud/DataFed/DataFed/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object core/server/CMakeFiles/datafed-core-lib.dir/TaskMgr.cpp.o"
	cd /home/cloud/DataFed/DataFed/core/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT core/server/CMakeFiles/datafed-core-lib.dir/TaskMgr.cpp.o -MF CMakeFiles/datafed-core-lib.dir/TaskMgr.cpp.o.d -o CMakeFiles/datafed-core-lib.dir/TaskMgr.cpp.o -c /home/cloud/DataFed/DataFed/core/server/TaskMgr.cpp

core/server/CMakeFiles/datafed-core-lib.dir/TaskMgr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/datafed-core-lib.dir/TaskMgr.cpp.i"
	cd /home/cloud/DataFed/DataFed/core/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cloud/DataFed/DataFed/core/server/TaskMgr.cpp > CMakeFiles/datafed-core-lib.dir/TaskMgr.cpp.i

core/server/CMakeFiles/datafed-core-lib.dir/TaskMgr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/datafed-core-lib.dir/TaskMgr.cpp.s"
	cd /home/cloud/DataFed/DataFed/core/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cloud/DataFed/DataFed/core/server/TaskMgr.cpp -o CMakeFiles/datafed-core-lib.dir/TaskMgr.cpp.s

core/server/CMakeFiles/datafed-core-lib.dir/TaskWorker.cpp.o: core/server/CMakeFiles/datafed-core-lib.dir/flags.make
core/server/CMakeFiles/datafed-core-lib.dir/TaskWorker.cpp.o: core/server/TaskWorker.cpp
core/server/CMakeFiles/datafed-core-lib.dir/TaskWorker.cpp.o: core/server/CMakeFiles/datafed-core-lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cloud/DataFed/DataFed/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object core/server/CMakeFiles/datafed-core-lib.dir/TaskWorker.cpp.o"
	cd /home/cloud/DataFed/DataFed/core/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT core/server/CMakeFiles/datafed-core-lib.dir/TaskWorker.cpp.o -MF CMakeFiles/datafed-core-lib.dir/TaskWorker.cpp.o.d -o CMakeFiles/datafed-core-lib.dir/TaskWorker.cpp.o -c /home/cloud/DataFed/DataFed/core/server/TaskWorker.cpp

core/server/CMakeFiles/datafed-core-lib.dir/TaskWorker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/datafed-core-lib.dir/TaskWorker.cpp.i"
	cd /home/cloud/DataFed/DataFed/core/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cloud/DataFed/DataFed/core/server/TaskWorker.cpp > CMakeFiles/datafed-core-lib.dir/TaskWorker.cpp.i

core/server/CMakeFiles/datafed-core-lib.dir/TaskWorker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/datafed-core-lib.dir/TaskWorker.cpp.s"
	cd /home/cloud/DataFed/DataFed/core/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cloud/DataFed/DataFed/core/server/TaskWorker.cpp -o CMakeFiles/datafed-core-lib.dir/TaskWorker.cpp.s

# Object files for target datafed-core-lib
datafed__core__lib_OBJECTS = \
"CMakeFiles/datafed-core-lib.dir/AuthMap.cpp.o" \
"CMakeFiles/datafed-core-lib.dir/AuthenticationManager.cpp.o" \
"CMakeFiles/datafed-core-lib.dir/ClientWorker.cpp.o" \
"CMakeFiles/datafed-core-lib.dir/Condition.cpp.o" \
"CMakeFiles/datafed-core-lib.dir/Config.cpp.o" \
"CMakeFiles/datafed-core-lib.dir/CoreServer.cpp.o" \
"CMakeFiles/datafed-core-lib.dir/DatabaseAPI.cpp.o" \
"CMakeFiles/datafed-core-lib.dir/GlobusAPI.cpp.o" \
"CMakeFiles/datafed-core-lib.dir/TaskMgr.cpp.o" \
"CMakeFiles/datafed-core-lib.dir/TaskWorker.cpp.o"

# External object files for target datafed-core-lib
datafed__core__lib_EXTERNAL_OBJECTS =

core/server/libdatafed-core-lib.a: core/server/CMakeFiles/datafed-core-lib.dir/AuthMap.cpp.o
core/server/libdatafed-core-lib.a: core/server/CMakeFiles/datafed-core-lib.dir/AuthenticationManager.cpp.o
core/server/libdatafed-core-lib.a: core/server/CMakeFiles/datafed-core-lib.dir/ClientWorker.cpp.o
core/server/libdatafed-core-lib.a: core/server/CMakeFiles/datafed-core-lib.dir/Condition.cpp.o
core/server/libdatafed-core-lib.a: core/server/CMakeFiles/datafed-core-lib.dir/Config.cpp.o
core/server/libdatafed-core-lib.a: core/server/CMakeFiles/datafed-core-lib.dir/CoreServer.cpp.o
core/server/libdatafed-core-lib.a: core/server/CMakeFiles/datafed-core-lib.dir/DatabaseAPI.cpp.o
core/server/libdatafed-core-lib.a: core/server/CMakeFiles/datafed-core-lib.dir/GlobusAPI.cpp.o
core/server/libdatafed-core-lib.a: core/server/CMakeFiles/datafed-core-lib.dir/TaskMgr.cpp.o
core/server/libdatafed-core-lib.a: core/server/CMakeFiles/datafed-core-lib.dir/TaskWorker.cpp.o
core/server/libdatafed-core-lib.a: core/server/CMakeFiles/datafed-core-lib.dir/build.make
core/server/libdatafed-core-lib.a: core/server/CMakeFiles/datafed-core-lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cloud/DataFed/DataFed/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX static library libdatafed-core-lib.a"
	cd /home/cloud/DataFed/DataFed/core/server && $(CMAKE_COMMAND) -P CMakeFiles/datafed-core-lib.dir/cmake_clean_target.cmake
	cd /home/cloud/DataFed/DataFed/core/server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/datafed-core-lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
core/server/CMakeFiles/datafed-core-lib.dir/build: core/server/libdatafed-core-lib.a
.PHONY : core/server/CMakeFiles/datafed-core-lib.dir/build

core/server/CMakeFiles/datafed-core-lib.dir/clean:
	cd /home/cloud/DataFed/DataFed/core/server && $(CMAKE_COMMAND) -P CMakeFiles/datafed-core-lib.dir/cmake_clean.cmake
.PHONY : core/server/CMakeFiles/datafed-core-lib.dir/clean

core/server/CMakeFiles/datafed-core-lib.dir/depend:
	cd /home/cloud/DataFed/DataFed && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cloud/DataFed/DataFed /home/cloud/DataFed/DataFed/core/server /home/cloud/DataFed/DataFed /home/cloud/DataFed/DataFed/core/server /home/cloud/DataFed/DataFed/core/server/CMakeFiles/datafed-core-lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : core/server/CMakeFiles/datafed-core-lib.dir/depend

