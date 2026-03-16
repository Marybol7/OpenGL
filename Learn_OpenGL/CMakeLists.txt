cmake_minimum_required(VERSION 3.20)
project(MyOpenGLApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MyOpenGLApp
    src/main.cpp
 "src/shader.h")

# ImGui backends (binding sources)
# Ajuste típico: vcpkg expone los headers, pero tú compilas estos cpp.
target_sources(MyOpenGLApp PRIVATE
    
    
)

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

target_link_libraries(MyOpenGLApp PRIVATE
    glfw
    glad::glad
    glm::glm
    imgui::imgui
)

if (WIN32)
    target_link_libraries(MyOpenGLApp PRIVATE opengl32)
endif()

add_custom_command(TARGET MyOpenGLApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory
            $<TARGET_FILE_DIR:MyOpenGLApp>/resources
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/resources
            $<TARGET_FILE_DIR:MyOpenGLApp>/resources
)
