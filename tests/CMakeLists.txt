add_subdirectory (googletest)
include_directories (
    googletest/googlemock/include/
    googletest/googletest/include/
    )
add_executable (unit_tests
    irc_protocol_tests.cpp
    )
target_link_libraries (unit_tests
	gtest
	gtest_main
	gmock
	ircbot_static
	)