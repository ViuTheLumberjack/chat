project(test)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCE_FILES runAllTests.cpp)
add_executable(runAllTests ${SOURCE_FILES})
target_link_libraries(runAllTests ${GTEST_BOTH_LIBRARIES} core)