

set(GTEST_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/packages/Microsoft.googletest.v140.windesktop.msvcstl.static.rt-dyn.1.8.0/build/native/include)
set(PARENT_DIR ${CMAKE_CURRENT_LIST_DIR}/../Assignment1)

set(SOURCE
   ${SOURCE}
   ${CMAKE_SOURCE_DIR}/AABB.cpp
   ${CMAKE_SOURCE_DIR}/Vector3.cpp
   PARENT_SCOPE
)
set(HEADERS
   ${HEADERS}
   ${CMAKE_SOURCE_DIR}/AABB.h
   ${CMAKE_SOURCE_DIR}/Vector3.h
   PARENT_SCOPE
)




# Create a library called "Testing" which includes the source file "Testing.cxx".
# The extension is already found. Any number of sources could be listed here.
add_library (TEST_OCULUS pch.h pch.cpp)

# Adding parent source
#add_subdirectory(${PARENT_DIR})


include_directories(${PARENT_DIR} ${GTEST_INCLUDE_DIR})

#link_libraries( ${PARENT_DIR})

# Make sure the compiler can find include files for our Testing library
# when other libraries or executables link to Testing
target_include_directories (	TEST_OCULUS PUBLIC ${CMAKE_SOURCE_DIR} 
								#${GTEST_INCLUDE_DIR} 
								#${PARENT_DIR}
								)