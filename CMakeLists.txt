cmake_minimum_required(VERSION 3.15.0)
project(unnamed-horse-game)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/modules/" ${CMAKE_MODULE_PATH})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Use modern C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(OpenGL_GL_PREFERENCE GLVND)

add_subdirectory(third-party/glad)
set(LIBRARIES ${LIBRARIES} glad)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(third-party/glfw-3.3.8)
set(LIBRARIES ${LIBRARIES} glfw)

find_package(OpenGL REQUIRED)
set(LIBRARIES ${LIBRARIES} ${OPENGL_gl_LIBRARY})


if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	list(APPEND _UHG_CMAKE_CXX_FLAGS ${_UHG_CMAKE_CXX_FLAGS} "-Wall" "-pedantic")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	# using GCC
	list(APPEND _UHG_CMAKE_CXX_FLAGS ${_UHG_CMAKE_CXX_FLAGS} "-fdiagnostics-color=always" "-Wall" "-pedantic")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
	# using Intel C++
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	add_compile_options("/permissive-")
	add_compile_options("/Zc:preprocessor")
	# Remove the default warning level.
	# https://stackoverflow.com/questions/58708772/cmake-project-in-visual-studio-gives-flag-override-warnings-command-line-warnin
	string(REGEX REPLACE "/W[3|4]" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	 # The above preprocessor warns about certain things in windows headers.
	 # Turn those off: https://docs.microsoft.com/en-us/cpp/error-messages/compiler-warnings/c5105?view=vs-2019
	add_compile_options("/wd5105")

	set(_UHG_CMAKE_CXX_FLAGS ${_UHG_CMAKE_CXX_FLAGS} /W3)

endif()

if(APPLE)
	set(LIBRARIES ${LIBRARIES} pthread dl)
elseif(UNIX)
	set(LIBRARIES ${LIBRARIES} pthread GL dl)
elseif(WIN32)
endif()

# Compile our main application
file(GLOB SOURCES
  src/classes/*
  src/main.cpp
    #third-party/glew-2.1.0/src/glew.c
)
set(INCLUDES ${INCLUDES} src)

set(APP_NAME "unnamed-horse-game")


add_executable(${APP_NAME} ${SOURCES})
target_include_directories(${APP_NAME} PRIVATE ${INCLUDES})
target_link_libraries(${APP_NAME} ${LIBRARIES})
target_compile_definitions(${APP_NAME} PRIVATE ${DEFINITIONS})
target_compile_options(${APP_NAME} PRIVATE ${_453_CMAKE_CXX_FLAGS})
set_target_properties(${APP_NAME} PROPERTIES INSTALL_RPATH "./" BUILD_RPATH "./")