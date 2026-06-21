cmake_minimum_required(VERSION 3.20)
project(MyOpenGLApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MyOpenGLApp
    src/main.cpp
    src/shader.h

    src/core/Window.cpp
    src/core/Window.h
    src/core/Application.cpp
    src/core/Application.h
    src/core/Time.cpp
    src/core/Time.h
    src/core/Input.cpp
    src/core/Input.h	
)

target_include_directories(MyOpenGLApp PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
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