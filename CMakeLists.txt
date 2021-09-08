cmake_minimum_required(VERSION 3.16)
project(chat)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

set(SOURCE_FILES User.h Message.cpp Message.h Chat.cpp Chat.h Register.cpp Register.h)
add_executable(chat main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(chat core)
