project(occulus_the_rift)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)

#Project settings to add local libraries
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/SDL2-devel-2.0.8-VC/SDL2-2.0.8)
set(GLUT_LIBRARIES ${CMAKE_CURRENT_LIST_DIR}/glut_bin/glut32.lib)
set(GLUT_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/glut_bin)
set(GLUT_glut_LIBRARY ${CMAKE_CURRENT_LIST_DIR}/glut_bin/glut32.lib)
set(SDL2_LIBRARY ${CMAKE_CURRENT_LIST_DIR}/SDL2-devel-2.0.8-VC/SDL2-2.0.8/lib/x86/SDL2.lib)
#set(SDL2_LIBRARY_TEMP "D:/SDL2/SDL/lib")
set(SDL2_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/SDL2-devel-2.0.8-VC/SDL2-2.0.8/include)
set(SDL2_SDLMAIN_LIBRARY ${CMAKE_CURRENT_LIST_DIR}/SDL2-devel-2.0.8-VC/SDL2-2.0.8/lib/x86/SDL2main.lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/build)
#set(SDL2_DIR "D:/SDL2/SDL2-2.0.8")
FIND_PATH(GLUT_INCLUDE_DIR NAMES GL/freeglut.h)
include_directories(.)
include_directories(${GLUT_INCLUDE_DIR})
include_directories(${SDL2_INCLUDE_DIR})


#Adding Testing settings
#d:\Murdoch\ICT290\occulus_the_rift\Assignment1\Test_Oculus_The_Rift\packages\Microsoft.googletest.v140.windesktop.msvcstl.static.rt-dyn.1.8.0\build\native\include\gtest\gtest.h
set(GTEST_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/Test_Oculus_The_Rift/packages/Microsoft.googletest.v140.windesktop.msvcstl.static.rt-dyn.1.8.0/build/native/include)
#add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/Tests)
#add_subdirectory(Tests)
add_subdirectory(Test_Oculus_The_Rift)

add_executable(
		occulus_the_rift
		main.cpp
		AABB.h
		AABB.cpp
		Game.h
		Game.cpp
		Actor.h
		Actor.cpp
		Player.h 
		Player.cpp
		Cube.h 
		Cube.cpp
		Texture.h
		Texture.cpp
		Model.h
		Model.cpp
		lodepng.h
		lodepng.cpp
		Vector3.cpp
		Vector3.h
		Projection.cpp
		Projection.h
)

#find_file(SDL2_INCLUDE_DIR NAMES SDL.h HINTS SDL2)
#find_file(SDL2_LIBRARY NAMES SDL2.lib)
#find_library(SDL2_LIBRARY NAMES SDL2)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(SDL2 REQUIRED)

include_directories(	${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS}  ${SDL2_INCLUDE_DIR} 
						${CMAKE_CURRENT_LIST_DIR}/Test_Oculus_The_Rift 
						${GTEST_INCLUDE_DIR}
						)

target_link_libraries(	occulus_the_rift 
						${OPENGL_LIBRARIES} 
						${GLUT_LIBRARIES} 
						${SDL2_LIBRARY} 
						${SDL2_SDLMAIN_LIBRARY} 
						TEST_OCULUS
						)

install(TARGETS occulus_the_rift DESTINATION ${CMAKE_CURRENT_LIST_DIR}/bin )