#cmake_minimum_required(VERSION 3.10)
#project(OpenGLChess)

## 设置 C++ 标准
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED True)

## 查找需要的包
#find_package(OpenGL REQUIRED)
#find_package(GLEW REQUIRED)
#find_package(glfw3 REQUIRED)

## 包含头文件目录
#include_directories(
#    ${OPENGL_INCLUDE_DIRS}
#    ${GLEW_INCLUDE_DIRS}
#    ${GLFW_INCLUDE_DIRS}
#    ${CMAKE_SOURCE_DIR}
#    ${CMAKE_SOURCE_DIR}/stb_image
#    ${CMAKE_SOURCE_DIR}/ressources/tinyobjloader-release
#)

## 源文件列表
#set(SOURCES
#    main.cpp
#    object.cpp
##    camera.cpp
#    renderer.cpp
#    shader.cpp
#    model.cpp
##    texture.cpp
##    uvbuffer.cpp
##    vertexarray.cpp
##    vertexbuffer.cpp
##    controls.cpp
##    stb_image/stb_image.cpp
#)

## 添加可执行文件
#add_executable(ChessGame ${SOURCES})

## 使用 target_sources 显式包含头文件，以便在 Qt Creator 文件栏中显示
#target_sources(ChessGame PRIVATE
#    object.h
##    camera.h
#    renderer.h
#    shader.h
#    model.h
##    texture.h
##    uvbuffer.h
##    vertexarray.h
##    vertexbuffer.h
##    controls.h
##    stb_image/stb_image.h
#)

## 链接库
#target_link_libraries(ChessGame ${OPENGL_LIBRARIES} GLEW::GLEW glfw)



cmake_minimum_required(VERSION 3.10)
project(OpenGLChess)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 设置 CMake 策略
cmake_policy(SET CMP0072 NEW)

# 查找需要的包
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

# 使用 pkg-config 查找 glfw3
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)

# 包含头文件目录
include_directories(
    ${OPENGL_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS}
    ${GLFW_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/stb_image
    ${CMAKE_SOURCE_DIR}/ressources/tinyobjloader-release
)

# 源文件列表
set(SOURCES
    main.cpp
    object.cpp
    renderer.cpp
    shader.cpp
    camera.cpp
    control.cpp
)

# 添加可执行文件
add_executable(ChessGame ${SOURCES})

# 显式包含头文件
target_sources(ChessGame PRIVATE
    object.h
    renderer.h
    shader.h
    camera.h
    control.h
)

# 链接库
target_link_libraries(ChessGame
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${GLFW_LIBRARIES}
)

# 添加模型文件夹到运行目录
add_custom_command(TARGET ChessGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/models $<TARGET_FILE_DIR:ChessGame>/models
)
