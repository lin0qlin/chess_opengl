cmake_minimum_required(VERSION 3.10)
project(OpenGLChess)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 查找需要的包
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

# 包含头文件目录
include_directories(
    ${OPENGL_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS}
    ${GLFW_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/stb_image
)

# 源文件列表
set(SOURCES
    main.cpp
    object.cpp
#    camera.cpp
    renderer.cpp
    shader.cpp
#    texture.cpp
#    uvbuffer.cpp
#    vertexarray.cpp
#    vertexbuffer.cpp
#    controls.cpp
#    stb_image/stb_image.cpp
)

# 添加可执行文件
add_executable(ChessGame ${SOURCES})

# 使用 target_sources 显式包含头文件，以便在 Qt Creator 文件栏中显示
target_sources(ChessGame PRIVATE
    object.h
#    camera.h
    renderer.h
    shader.h
#    texture.h
#    uvbuffer.h
#    vertexarray.h
#    vertexbuffer.h
#    controls.h
#    stb_image/stb_image.h
)

# 链接库
target_link_libraries(ChessGame ${OPENGL_LIBRARIES} GLEW::GLEW glfw)
