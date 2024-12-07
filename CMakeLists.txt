cmake_minimum_required(VERSION 3.10)
project(OpenGLChess)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


cmake_policy(SET CMP0072 NEW)


find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)


find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)


include_directories(
    ${OPENGL_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS}
    ${GLFW_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/stb_image
    ${CMAKE_SOURCE_DIR}/ressources/tinyobjloader-release
)


set(SOURCES
    main.cpp
    object.cpp
    renderer.cpp
    shader.cpp
    camera.cpp
    controls.cpp
    fpscontrols.cpp
    navigationcontrols.cpp
    texture.cpp
    ressources/stb_image/stb_image.cpp
)


add_executable(ChessGame ${SOURCES})


target_sources(ChessGame PRIVATE
    object.h
    renderer.h
    shader.h
    camera.h
    controls.h
    fpscontrols.h
    navigationcontrols.h
    texture.h
)


target_link_libraries(ChessGame
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${GLFW_LIBRARIES}
)


add_custom_command(TARGET ChessGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/models $<TARGET_FILE_DIR:ChessGame>/models
    ${CMAKE_SOURCE_DIR}/shaders $<TARGET_FILE_DIR:ChessGame>/shaders
    ${CMAKE_SOURCE_DIR}/textures $<TARGET_FILE_DIR:ChessGame>/textures
)
