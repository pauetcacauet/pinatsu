# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Projects\pinatsu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Projects\pinatsu\makebin

# Include any dependencies generated for this target.
include CMakeFiles\sandbox.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\sandbox.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\sandbox.dir\flags.make

CMakeFiles\sandbox.dir\sandbox\src\entry.cpp.obj: CMakeFiles\sandbox.dir\flags.make
CMakeFiles\sandbox.dir\sandbox\src\entry.cpp.obj: ..\sandbox\src\entry.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\pinatsu\makebin\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sandbox.dir/sandbox/src/entry.cpp.obj"
	D:\TOOLS\VS\VC\Tools\MSVC\14.31.31103\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\sandbox.dir\sandbox\src\entry.cpp.obj /FdCMakeFiles\sandbox.dir\ /FS -c D:\Projects\pinatsu\sandbox\src\entry.cpp
<<

CMakeFiles\sandbox.dir\sandbox\src\entry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sandbox.dir/sandbox/src/entry.cpp.i"
	D:\TOOLS\VS\VC\Tools\MSVC\14.31.31103\bin\Hostx64\x64\cl.exe > CMakeFiles\sandbox.dir\sandbox\src\entry.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\pinatsu\sandbox\src\entry.cpp
<<

CMakeFiles\sandbox.dir\sandbox\src\entry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sandbox.dir/sandbox/src/entry.cpp.s"
	D:\TOOLS\VS\VC\Tools\MSVC\14.31.31103\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\sandbox.dir\sandbox\src\entry.cpp.s /c D:\Projects\pinatsu\sandbox\src\entry.cpp
<<

CMakeFiles\sandbox.dir\sandbox\src\sandbox.cpp.obj: CMakeFiles\sandbox.dir\flags.make
CMakeFiles\sandbox.dir\sandbox\src\sandbox.cpp.obj: ..\sandbox\src\sandbox.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\pinatsu\makebin\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sandbox.dir/sandbox/src/sandbox.cpp.obj"
	D:\TOOLS\VS\VC\Tools\MSVC\14.31.31103\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\sandbox.dir\sandbox\src\sandbox.cpp.obj /FdCMakeFiles\sandbox.dir\ /FS -c D:\Projects\pinatsu\sandbox\src\sandbox.cpp
<<

CMakeFiles\sandbox.dir\sandbox\src\sandbox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sandbox.dir/sandbox/src/sandbox.cpp.i"
	D:\TOOLS\VS\VC\Tools\MSVC\14.31.31103\bin\Hostx64\x64\cl.exe > CMakeFiles\sandbox.dir\sandbox\src\sandbox.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\pinatsu\sandbox\src\sandbox.cpp
<<

CMakeFiles\sandbox.dir\sandbox\src\sandbox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sandbox.dir/sandbox/src/sandbox.cpp.s"
	D:\TOOLS\VS\VC\Tools\MSVC\14.31.31103\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\sandbox.dir\sandbox\src\sandbox.cpp.s /c D:\Projects\pinatsu\sandbox\src\sandbox.cpp
<<

# Object files for target sandbox
sandbox_OBJECTS = \
"CMakeFiles\sandbox.dir\sandbox\src\entry.cpp.obj" \
"CMakeFiles\sandbox.dir\sandbox\src\sandbox.cpp.obj"

# External object files for target sandbox
sandbox_EXTERNAL_OBJECTS =

sandbox.exe: CMakeFiles\sandbox.dir\sandbox\src\entry.cpp.obj
sandbox.exe: CMakeFiles\sandbox.dir\sandbox\src\sandbox.cpp.obj
sandbox.exe: CMakeFiles\sandbox.dir\build.make
sandbox.exe: engine.lib
sandbox.exe: D:\TOOLS\Vulkan\1.2.198.1\Lib\vulkan-1.lib
sandbox.exe: CMakeFiles\sandbox.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Projects\pinatsu\makebin\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable sandbox.exe"
	"C:\Program Files\CMake\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\sandbox.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x64\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x64\mt.exe --manifests  -- D:\TOOLS\VS\VC\Tools\MSVC\14.31.31103\bin\Hostx64\x64\link.exe /nologo @CMakeFiles\sandbox.dir\objects1.rsp @<<
 /out:sandbox.exe /implib:sandbox.lib /pdb:D:\Projects\pinatsu\makebin\sandbox.pdb /version:0.0  /machine:x64 /debug /INCREMENTAL /subsystem:console  engine.lib user32.lib D:\TOOLS\Vulkan\1.2.198.1\Lib\vulkan-1.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\sandbox.dir\build: sandbox.exe

.PHONY : CMakeFiles\sandbox.dir\build

CMakeFiles\sandbox.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\sandbox.dir\cmake_clean.cmake
.PHONY : CMakeFiles\sandbox.dir\clean

CMakeFiles\sandbox.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\Projects\pinatsu D:\Projects\pinatsu D:\Projects\pinatsu\makebin D:\Projects\pinatsu\makebin D:\Projects\pinatsu\makebin\CMakeFiles\sandbox.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\sandbox.dir\depend

