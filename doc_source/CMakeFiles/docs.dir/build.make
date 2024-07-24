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

# Utility rule file for docs.

# Include any custom commands dependencies for this target.
include doc_source/CMakeFiles/docs.dir/compiler_depend.make

# Include the progress variables for this target.
include doc_source/CMakeFiles/docs.dir/progress.make

docs: doc_source/CMakeFiles/docs.dir/build.make
	cd /home/cloud/DataFed/DataFed/doc_source && echo Preparing\ docs\ build\ directories
	cd /home/cloud/DataFed/DataFed/doc_source && rm -rf /home/cloud/DataFed/DataFed/docs
	cd /home/cloud/DataFed/DataFed/doc_source && mkdir /home/cloud/DataFed/DataFed/docs
	cd /home/cloud/DataFed/DataFed/doc_source && mkdir -p /home/cloud/DataFed/DataFed/doc_source/source/_generated
	cd /home/cloud/DataFed/DataFed/doc_source && echo Generating\ API\ docs
	cd /home/cloud/DataFed/DataFed/doc_source && /usr/bin/cmake -E env PYTHONPATH=/home/cloud/DataFed/DataFed/python/datafed_pkg/ /home/cloud/DataFed/DataFed/python/datafed_pkg/scripts/datafed gendoc > /home/cloud/DataFed/DataFed/doc_source/source/_generated/cli_python_cmd_ref.rst
	cd /home/cloud/DataFed/DataFed/doc_source && echo Generating\ docs\ HTML
	cd /home/cloud/DataFed/DataFed/doc_source && sphinx-build -b html /home/cloud/DataFed/DataFed/doc_source/source /home/cloud/DataFed/DataFed/docs
	cd /home/cloud/DataFed/DataFed/doc_source && touch /home/cloud/DataFed/DataFed/docs/.nojekyll
.PHONY : docs

# Rule to build all files generated by this target.
doc_source/CMakeFiles/docs.dir/build: docs
.PHONY : doc_source/CMakeFiles/docs.dir/build

doc_source/CMakeFiles/docs.dir/clean:
	cd /home/cloud/DataFed/DataFed/doc_source && $(CMAKE_COMMAND) -P CMakeFiles/docs.dir/cmake_clean.cmake
.PHONY : doc_source/CMakeFiles/docs.dir/clean

doc_source/CMakeFiles/docs.dir/depend:
	cd /home/cloud/DataFed/DataFed && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cloud/DataFed/DataFed /home/cloud/DataFed/DataFed/doc_source /home/cloud/DataFed/DataFed /home/cloud/DataFed/DataFed/doc_source /home/cloud/DataFed/DataFed/doc_source/CMakeFiles/docs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : doc_source/CMakeFiles/docs.dir/depend

