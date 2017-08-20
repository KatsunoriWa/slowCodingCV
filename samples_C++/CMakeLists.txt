cmake_minimum_required(VERSION 2.8)
add_executable(ex_max ex_max.cpp)

# �\�����[�V�����t�@�C���̖��O���w�肷��
project( ex_max )

# ���̍s��ǉ������MinSizeRel��RelWithDebInfo�̑I�����𐶐����邱�Ƃ��}���ł��܂��B
SET(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "limited configs" FORCE)

#���̍s��ǉ������-DWITH_SOMELIB���R���p�C���I�v�V�����w��ł���B
#add_definitions(-DWITH_SOMELIB)

# OpenCV�̃p�b�P�[�W��T��
find_package(OpenCV REQUIRED)

find_package(PythonLibs REQUIRED)

# OpenCV�����������ꍇ�̂ݐݒ���s��
if(OpenCV_FOUND)
  # �C���N���[�h�p�X���w��
  include_directories(${OpenCV_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})

  # �����N���郉�C�u�����w��
  target_link_libraries(ex_max ${OpenCV_LIBS} ${PYTHON_LIBRARIES})
endif(OpenCV_FOUND)