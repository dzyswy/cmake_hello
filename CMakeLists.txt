########################################################################
IF(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    MESSAGE(FATAL_ERROR "Prevented in-tree built. This is bad practice.")
ENDIF(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})


########################################################################
# Project setup
########################################################################
CMAKE_MINIMUM_REQUIRED(VERSION 3.9.0)
PROJECT(cmake_hello CXX)
ENABLE_TESTING()

if (POLICY CMP0074)
  cmake_policy(SET CMP0074 NEW)
endif()

set(CMAKE_MODULE_PATH APPEND "${CMAKE_SOURCE_DIR}/cmake/Modules/")
set(CMAKE_CXX_STANDARD 11)



if (UNIX)
	ADD_DEFINITIONS(-fPIC)
endif()

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/framework/include)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/hardware/include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/libs)

link_directories(${PROJECT_BINARY_DIR}/libs) 


ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/jsoncpp) 
ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/framework)
ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/hardware)
ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/app/gui_client)



MESSAGE(STATUS "Using install prefix: ${CMAKE_INSTALL_PREFIX}")
