file(GLOB_RECURSE test_srcs "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")


#INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../../3rdparty/jsoncpp/include)



SET(LIBS ${LIBS} cmake_framework)
SET(LIBS ${LIBS} cmake_hardware)

foreach(source_file ${test_srcs})
  # get file name
  get_filename_component(test_name ${source_file} NAME_WE)
    
  add_executable(${test_name} ${source_file})
  target_link_libraries(${test_name} ${LIBS})


  # install
  install(TARGETS ${test_name} DESTINATION bin)


endforeach()
