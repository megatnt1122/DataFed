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
include common/tests/unit/CMakeFiles/unit_test_MessageFactory.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include common/tests/unit/CMakeFiles/unit_test_MessageFactory.dir/compiler_depend.make

# Include the progress variables for this target.
include common/tests/unit/CMakeFiles/unit_test_MessageFactory.dir/progress.make

# Include the compile flags for this target's objects.
include common/tests/unit/CMakeFiles/unit_test_MessageFactory.dir/flags.make

common/tests/unit/CMakeFiles/unit_test_MessageFactory.dir/test_MessageFactory.cpp.o: common/tests/unit/CMakeFiles/unit_test_MessageFactory.dir/flags.make
common/tests/unit/CMakeFiles/unit_test_MessageFactory.dir/test_MessageFactory.cpp.o: common/tests/unit/test_MessageFactory.cpp
common/tests/unit/CMakeFiles/unit_test_MessageFactory.dir/test_MessageFactory.cpp.o: common/tests/unit/CMakeFiles/unit_test_MessageFactory.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cloud/DataFed/DataFed/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object common/tests/unit/CMakeFiles/unit_test_MessageFactory.dir/test_MessageFactory.cpp.o"
	cd /home/cloud/DataFed/DataFed/common/tests/unit && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT common/tests/unit/CMakeFiles/unit_test_MessageFactory.dir/test_MessageFactory.cpp.o -MF CMakeFiles/unit_test_MessageFactory.dir/test_MessageFactory.cpp.o.d -o CMakeFiles/unit_test_MessageFactory.dir/test_MessageFactory.cpp.o -c /home/cloud/DataFed/DataFed/common/tests/unit/test_MessageFactory.cpp

common/tests/unit/CMakeFiles/unit_test_MessageFactory.dir/test_MessageFactory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_test_MessageFactory.dir/test_MessageFactory.cpp.i"
	cd /home/cloud/DataFed/DataFed/common/tests/unit && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cloud/DataFed/DataFed/common/tests/unit/test_MessageFactory.cpp > CMakeFiles/unit_test_MessageFactory.dir/test_MessageFactory.cpp.i

common/tests/unit/CMakeFiles/unit_test_MessageFactory.dir/test_MessageFactory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_test_MessageFactory.dir/test_MessageFactory.cpp.s"
	cd /home/cloud/DataFed/DataFed/common/tests/unit && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cloud/DataFed/DataFed/common/tests/unit/test_MessageFactory.cpp -o CMakeFiles/unit_test_MessageFactory.dir/test_MessageFactory.cpp.s

# Object files for target unit_test_MessageFactory
unit_test_MessageFactory_OBJECTS = \
"CMakeFiles/unit_test_MessageFactory.dir/test_MessageFactory.cpp.o"

# External object files for target unit_test_MessageFactory
unit_test_MessageFactory_EXTERNAL_OBJECTS =

common/tests/unit/unit_test_MessageFactory: common/tests/unit/CMakeFiles/unit_test_MessageFactory.dir/test_MessageFactory.cpp.o
common/tests/unit/unit_test_MessageFactory: common/tests/unit/CMakeFiles/unit_test_MessageFactory.dir/build.make
common/tests/unit/unit_test_MessageFactory: /usr/lib/x86_64-linux-gnu/libboost_date_time.a
common/tests/unit/unit_test_MessageFactory: /usr/lib/x86_64-linux-gnu/libboost_unit_test_framework.a
common/tests/unit/unit_test_MessageFactory: /usr/lib/x86_64-linux-gnu/libboost_system.a
common/tests/unit/unit_test_MessageFactory: /usr/lib/x86_64-linux-gnu/libboost_filesystem.a
common/tests/unit/unit_test_MessageFactory: /usr/lib/x86_64-linux-gnu/libboost_program_options.a
common/tests/unit/unit_test_MessageFactory: common/libcommon.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libzmq.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libprotobuf.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libsodium.a
common/tests/unit/unit_test_MessageFactory: /usr/lib/x86_64-linux-gnu/libboost_date_time.a
common/tests/unit/unit_test_MessageFactory: common/proto/common/libdatafed-protobuf.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libprotoc.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libprotobuf.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libz.so
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libprotobuf-lite.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_log_internal_check_op.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_leak_check.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_die_if_null.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_log_internal_conditions.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_log_internal_message.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_log_internal_nullguard.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_examine_stack.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_log_internal_format.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_log_internal_proto.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_log_internal_log_sink_set.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_log_sink.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_log_entry.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_flags.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_flags_internal.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_flags_marshalling.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_flags_reflection.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_flags_config.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_flags_program_name.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_flags_private_handle_accessor.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_flags_commandlineflag.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_flags_commandlineflag_internal.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_log_initialize.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_log_globals.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_log_internal_globals.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_raw_hash_set.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_hash.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_city.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_low_level_hash.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_hashtablez_sampler.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_statusor.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_status.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_cord.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_cordz_info.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_cord_internal.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_cordz_functions.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_exponential_biased.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_cordz_handle.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_crc_cord_state.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_crc32c.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_crc_internal.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_crc_cpu_detect.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_bad_optional_access.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_str_format_internal.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_strerror.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_synchronization.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_stacktrace.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_symbolize.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_debugging_internal.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_demangle_internal.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_graphcycles_internal.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_kernel_timeout_internal.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_malloc_internal.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_time.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_civil_time.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_time_zone.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_bad_variant_access.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libutf8_validity.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_strings.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_int128.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_string_view.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_throw_delegate.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_strings_internal.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_base.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_raw_logging_internal.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_log_severity.a
common/tests/unit/unit_test_MessageFactory: /opt/datafed/dependencies/lib/libabsl_spinlock_wait.a
common/tests/unit/unit_test_MessageFactory: common/tests/unit/CMakeFiles/unit_test_MessageFactory.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cloud/DataFed/DataFed/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable unit_test_MessageFactory"
	cd /home/cloud/DataFed/DataFed/common/tests/unit && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unit_test_MessageFactory.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
common/tests/unit/CMakeFiles/unit_test_MessageFactory.dir/build: common/tests/unit/unit_test_MessageFactory
.PHONY : common/tests/unit/CMakeFiles/unit_test_MessageFactory.dir/build

common/tests/unit/CMakeFiles/unit_test_MessageFactory.dir/clean:
	cd /home/cloud/DataFed/DataFed/common/tests/unit && $(CMAKE_COMMAND) -P CMakeFiles/unit_test_MessageFactory.dir/cmake_clean.cmake
.PHONY : common/tests/unit/CMakeFiles/unit_test_MessageFactory.dir/clean

common/tests/unit/CMakeFiles/unit_test_MessageFactory.dir/depend:
	cd /home/cloud/DataFed/DataFed && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cloud/DataFed/DataFed /home/cloud/DataFed/DataFed/common/tests/unit /home/cloud/DataFed/DataFed /home/cloud/DataFed/DataFed/common/tests/unit /home/cloud/DataFed/DataFed/common/tests/unit/CMakeFiles/unit_test_MessageFactory.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : common/tests/unit/CMakeFiles/unit_test_MessageFactory.dir/depend

