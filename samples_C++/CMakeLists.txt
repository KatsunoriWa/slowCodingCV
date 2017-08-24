cmake_minimum_required(VERSION 2.8)
add_executable(ex_max ex_max.cpp)
add_executable(ex_setTo ex_setTo.cpp)
add_executable(ex_mean ex_mean.cpp)
add_executable(ex_addWeighted ex_addWeighted.cpp)
add_executable(ex_absdiff ex_absdiff.cpp)
add_executable(ex_scaleAdd ex_scaleAdd.cpp)
add_executable(ex_copyTo ex_copyTo.cpp)
add_executable(ex_normalize ex_normalize.cpp)
add_executable(ex_minMaxLoc ex_minMaxLoc.cpp)

project( slowCodingOpenCV )

SET(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "limited configs" FORCE)

#add_definitions(-DWITH_SOMELIB)

find_package(OpenCV REQUIRED)

find_package(PythonLibs REQUIRED)

if(OpenCV_FOUND)
  include_directories(${OpenCV_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})

  target_link_libraries(ex_max ${OpenCV_LIBS} ${PYTHON_LIBRARIES})
  target_link_libraries(ex_setTo ${OpenCV_LIBS} ${PYTHON_LIBRARIES})
  target_link_libraries(ex_mean ${OpenCV_LIBS} ${PYTHON_LIBRARIES})
  target_link_libraries(ex_addWeighted ${OpenCV_LIBS} ${PYTHON_LIBRARIES})
  target_link_libraries(ex_absdiff ${OpenCV_LIBS} ${PYTHON_LIBRARIES})
  target_link_libraries(ex_scaleAdd ${OpenCV_LIBS} ${PYTHON_LIBRARIES})
  target_link_libraries(ex_copyTo ${OpenCV_LIBS} ${PYTHON_LIBRARIES})
  target_link_libraries(ex_normalize ${OpenCV_LIBS} ${PYTHON_LIBRARIES})
  target_link_libraries(ex_minMaxLoc ${OpenCV_LIBS} ${PYTHON_LIBRARIES})

endif(OpenCV_FOUND)
