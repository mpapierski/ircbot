cmake_minimum_required (VERSION 2.6)
project (ircbot CXX)

find_package (Boost REQUIRED COMPONENTS
	system
	thread
	)

include_directories (
	src/
	${Boost_INCLUDE_DIRS}
	)

add_subdirectory (src)
add_subdirectory (tests)
