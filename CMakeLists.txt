cmake_minimum_required(VERSION 2.8)
project(open_cv_practice)
find_package(OpenCV REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -O0")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES main.cpp
<<<<<<< HEAD
#				 tutorial1.cpp
#				 tutorial2.cpp
#				 tutorial3.cpp
#				 tutorial4.cpp
#				 tutorial5.cpp
#				 tutorial6.cpp
#				 tutorial7.cpp
#				 tutorial8.cpp
				 tutorial9.cpp)
=======
				 tutorial.cpp)
>>>>>>> e1de05cab382980a2ed55ddb605bce1e31e8b2b1

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
