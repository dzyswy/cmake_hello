
if (POLICY CMP0071)
  cmake_policy(SET CMP0071 NEW)
endif()


PROJECT(gui_client CXX)


set(CMAKE_PREFIX_PATH $ENV{QTDIR} ${CMAKE_PREFIX_PATH})



INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../../framework/include)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../../hardware/include)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} FILE_SRCS)

SET(CMAKE_AUTOMOC ON)
set(QMAKE_CXXFLAGS ${QMAKE_CXXFLAGS} -std=c++11)

#find_package(OpenCV REQUIRED)
#if(NOT OpenCV_FOUND)
#	message("fail to find OpenCV")
#else()
#	include_directories(${OpenCV_INCLUDE_DIRS})
#	SET(LIBS ${LIBS} ${OpenCV_LIBS})
#	message(STATUS "OpenCV library status:")
#	message(STATUS "    version: ${OpenCV_VERSION}")
#endif()

 
 
FIND_PACKAGE(Qt5Widgets)
FIND_PACKAGE(Qt5Gui)

set(QRC_SOURCE_FILES icons.qrc)
qt5_add_resources(QRC_FILES ${QRC_SOURCE_FILES})


SET(LIBS ${LIBS} cmake_framework)
SET(LIBS ${LIBS} cmake_hardware)


if (UNIX)
	set(LIBS ${LIBS} pthread)
endif ()


qt5_wrap_ui(UI_HEADERS form_gui.ui) # update_dialog.ui
ADD_EXECUTABLE(${PROJECT_NAME} ${FILE_SRCS} ${UI_HEADERS} ${QRC_FILES})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} 
	${LIBS}
	${Qt5Core_QTMAIN_LIBRARIES})
qt5_use_modules(${PROJECT_NAME} Widgets Gui)


INSTALL(TARGETS ${PROJECT_NAME} DESTINATION bin)

