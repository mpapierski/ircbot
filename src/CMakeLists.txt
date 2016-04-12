add_library (ircbot_static STATIC
    irc_protocol.cpp
    irc_protocol.hpp
    )
target_link_libraries (ircbot_static
    ${Boost_LIBRARIES}
    )

add_executable (ircbot
    main.cpp
    )

target_link_libraries (ircbot
    ircbot_static
    )