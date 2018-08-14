# Create a library called "Testing" which includes the source file "Testing.cxx".
# The extension is already found. Any number of sources could be listed here.
add_library (TESTING TestAABB.cpp)

# Make sure the compiler can find include files for our Testing library
# when other libraries or executables link to Testing
target_include_directories (TESTING PUBLIC ${CMAKE_SOURCE_DIR})