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
CMAKE_SOURCE_DIR = /home/formation/Documents/chess_opengl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/formation/Documents/chess_opengl/build

# Include any dependencies generated for this target.
include CMakeFiles/ChessGame.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ChessGame.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ChessGame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ChessGame.dir/flags.make

CMakeFiles/ChessGame.dir/main.cpp.o: CMakeFiles/ChessGame.dir/flags.make
CMakeFiles/ChessGame.dir/main.cpp.o: ../main.cpp
CMakeFiles/ChessGame.dir/main.cpp.o: CMakeFiles/ChessGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/formation/Documents/chess_opengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ChessGame.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ChessGame.dir/main.cpp.o -MF CMakeFiles/ChessGame.dir/main.cpp.o.d -o CMakeFiles/ChessGame.dir/main.cpp.o -c /home/formation/Documents/chess_opengl/main.cpp

CMakeFiles/ChessGame.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChessGame.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/formation/Documents/chess_opengl/main.cpp > CMakeFiles/ChessGame.dir/main.cpp.i

CMakeFiles/ChessGame.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChessGame.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/formation/Documents/chess_opengl/main.cpp -o CMakeFiles/ChessGame.dir/main.cpp.s

CMakeFiles/ChessGame.dir/object.cpp.o: CMakeFiles/ChessGame.dir/flags.make
CMakeFiles/ChessGame.dir/object.cpp.o: ../object.cpp
CMakeFiles/ChessGame.dir/object.cpp.o: CMakeFiles/ChessGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/formation/Documents/chess_opengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ChessGame.dir/object.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ChessGame.dir/object.cpp.o -MF CMakeFiles/ChessGame.dir/object.cpp.o.d -o CMakeFiles/ChessGame.dir/object.cpp.o -c /home/formation/Documents/chess_opengl/object.cpp

CMakeFiles/ChessGame.dir/object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChessGame.dir/object.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/formation/Documents/chess_opengl/object.cpp > CMakeFiles/ChessGame.dir/object.cpp.i

CMakeFiles/ChessGame.dir/object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChessGame.dir/object.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/formation/Documents/chess_opengl/object.cpp -o CMakeFiles/ChessGame.dir/object.cpp.s

CMakeFiles/ChessGame.dir/renderer.cpp.o: CMakeFiles/ChessGame.dir/flags.make
CMakeFiles/ChessGame.dir/renderer.cpp.o: ../renderer.cpp
CMakeFiles/ChessGame.dir/renderer.cpp.o: CMakeFiles/ChessGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/formation/Documents/chess_opengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ChessGame.dir/renderer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ChessGame.dir/renderer.cpp.o -MF CMakeFiles/ChessGame.dir/renderer.cpp.o.d -o CMakeFiles/ChessGame.dir/renderer.cpp.o -c /home/formation/Documents/chess_opengl/renderer.cpp

CMakeFiles/ChessGame.dir/renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChessGame.dir/renderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/formation/Documents/chess_opengl/renderer.cpp > CMakeFiles/ChessGame.dir/renderer.cpp.i

CMakeFiles/ChessGame.dir/renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChessGame.dir/renderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/formation/Documents/chess_opengl/renderer.cpp -o CMakeFiles/ChessGame.dir/renderer.cpp.s

CMakeFiles/ChessGame.dir/shader.cpp.o: CMakeFiles/ChessGame.dir/flags.make
CMakeFiles/ChessGame.dir/shader.cpp.o: ../shader.cpp
CMakeFiles/ChessGame.dir/shader.cpp.o: CMakeFiles/ChessGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/formation/Documents/chess_opengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ChessGame.dir/shader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ChessGame.dir/shader.cpp.o -MF CMakeFiles/ChessGame.dir/shader.cpp.o.d -o CMakeFiles/ChessGame.dir/shader.cpp.o -c /home/formation/Documents/chess_opengl/shader.cpp

CMakeFiles/ChessGame.dir/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChessGame.dir/shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/formation/Documents/chess_opengl/shader.cpp > CMakeFiles/ChessGame.dir/shader.cpp.i

CMakeFiles/ChessGame.dir/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChessGame.dir/shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/formation/Documents/chess_opengl/shader.cpp -o CMakeFiles/ChessGame.dir/shader.cpp.s

CMakeFiles/ChessGame.dir/texture.cpp.o: CMakeFiles/ChessGame.dir/flags.make
CMakeFiles/ChessGame.dir/texture.cpp.o: ../texture.cpp
CMakeFiles/ChessGame.dir/texture.cpp.o: CMakeFiles/ChessGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/formation/Documents/chess_opengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ChessGame.dir/texture.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ChessGame.dir/texture.cpp.o -MF CMakeFiles/ChessGame.dir/texture.cpp.o.d -o CMakeFiles/ChessGame.dir/texture.cpp.o -c /home/formation/Documents/chess_opengl/texture.cpp

CMakeFiles/ChessGame.dir/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChessGame.dir/texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/formation/Documents/chess_opengl/texture.cpp > CMakeFiles/ChessGame.dir/texture.cpp.i

CMakeFiles/ChessGame.dir/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChessGame.dir/texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/formation/Documents/chess_opengl/texture.cpp -o CMakeFiles/ChessGame.dir/texture.cpp.s

CMakeFiles/ChessGame.dir/ressources/stb_image/stb_image.cpp.o: CMakeFiles/ChessGame.dir/flags.make
CMakeFiles/ChessGame.dir/ressources/stb_image/stb_image.cpp.o: ../ressources/stb_image/stb_image.cpp
CMakeFiles/ChessGame.dir/ressources/stb_image/stb_image.cpp.o: CMakeFiles/ChessGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/formation/Documents/chess_opengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ChessGame.dir/ressources/stb_image/stb_image.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ChessGame.dir/ressources/stb_image/stb_image.cpp.o -MF CMakeFiles/ChessGame.dir/ressources/stb_image/stb_image.cpp.o.d -o CMakeFiles/ChessGame.dir/ressources/stb_image/stb_image.cpp.o -c /home/formation/Documents/chess_opengl/ressources/stb_image/stb_image.cpp

CMakeFiles/ChessGame.dir/ressources/stb_image/stb_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChessGame.dir/ressources/stb_image/stb_image.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/formation/Documents/chess_opengl/ressources/stb_image/stb_image.cpp > CMakeFiles/ChessGame.dir/ressources/stb_image/stb_image.cpp.i

CMakeFiles/ChessGame.dir/ressources/stb_image/stb_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChessGame.dir/ressources/stb_image/stb_image.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/formation/Documents/chess_opengl/ressources/stb_image/stb_image.cpp -o CMakeFiles/ChessGame.dir/ressources/stb_image/stb_image.cpp.s

# Object files for target ChessGame
ChessGame_OBJECTS = \
"CMakeFiles/ChessGame.dir/main.cpp.o" \
"CMakeFiles/ChessGame.dir/object.cpp.o" \
"CMakeFiles/ChessGame.dir/renderer.cpp.o" \
"CMakeFiles/ChessGame.dir/shader.cpp.o" \
"CMakeFiles/ChessGame.dir/texture.cpp.o" \
"CMakeFiles/ChessGame.dir/ressources/stb_image/stb_image.cpp.o"

# External object files for target ChessGame
ChessGame_EXTERNAL_OBJECTS =

ChessGame: CMakeFiles/ChessGame.dir/main.cpp.o
ChessGame: CMakeFiles/ChessGame.dir/object.cpp.o
ChessGame: CMakeFiles/ChessGame.dir/renderer.cpp.o
ChessGame: CMakeFiles/ChessGame.dir/shader.cpp.o
ChessGame: CMakeFiles/ChessGame.dir/texture.cpp.o
ChessGame: CMakeFiles/ChessGame.dir/ressources/stb_image/stb_image.cpp.o
ChessGame: CMakeFiles/ChessGame.dir/build.make
ChessGame: /usr/lib/x86_64-linux-gnu/libOpenGL.so
ChessGame: /usr/lib/x86_64-linux-gnu/libGLX.so
ChessGame: /usr/lib/x86_64-linux-gnu/libGLU.so
ChessGame: /usr/lib/x86_64-linux-gnu/libGLEW.so
ChessGame: CMakeFiles/ChessGame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/formation/Documents/chess_opengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable ChessGame"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ChessGame.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/cmake -E copy_directory /home/formation/Documents/chess_opengl/models /home/formation/Documents/chess_opengl/build/models
	/usr/bin/cmake -E copy_directory /home/formation/Documents/chess_opengl/textures /home/formation/Documents/chess_opengl/build/textures

# Rule to build all files generated by this target.
CMakeFiles/ChessGame.dir/build: ChessGame
.PHONY : CMakeFiles/ChessGame.dir/build

CMakeFiles/ChessGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ChessGame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ChessGame.dir/clean

CMakeFiles/ChessGame.dir/depend:
	cd /home/formation/Documents/chess_opengl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/formation/Documents/chess_opengl /home/formation/Documents/chess_opengl /home/formation/Documents/chess_opengl/build /home/formation/Documents/chess_opengl/build /home/formation/Documents/chess_opengl/build/CMakeFiles/ChessGame.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ChessGame.dir/depend

