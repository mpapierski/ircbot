cmake_minimum_required (VERSION 2.6)
project (ircbot CXX)

find_package (Boost REQUIRED)

add_subdirectory (src)
add_subdirectory (tests)
