cmake_minimum_required(VERSION 3.20)
project(MyOpenGLApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MyOpenGLApp
    src/main.cpp
)

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