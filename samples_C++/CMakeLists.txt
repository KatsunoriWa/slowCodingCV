cmake_minimum_required(VERSION 2.8)
add_executable(ex_max ex_max.cpp)

# ソリューションファイルの名前を指定する
project( ex_max )

# 次の行を追加するとMinSizeRelとRelWithDebInfoの選択肢を生成することが抑制できます。
SET(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "limited configs" FORCE)

#次の行を追加すると-DWITH_SOMELIBをコンパイルオプション指定できる。
#add_definitions(-DWITH_SOMELIB)

# OpenCVのパッケージを探す
find_package(OpenCV REQUIRED)

find_package(PythonLibs REQUIRED)

# OpenCVが見つかった場合のみ設定を行う
if(OpenCV_FOUND)
  # インクルードパスを指定
  include_directories(${OpenCV_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})

  # リンクするライブラリ指定
  target_link_libraries(ex_max ${OpenCV_LIBS} ${PYTHON_LIBRARIES})
endif(OpenCV_FOUND)