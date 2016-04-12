#include "irc_protocol.hpp"

irc_protocol::irc_protocol()
{
}

void irc_protocol::set_callbacks(irc_protocol::callbacks * new_callbacks)
{
    assert(new_callbacks != nullptr);
    callbacks_ = new_callbacks;
    on_connect();
}

void irc_protocol::on_connect() {
    assert(callbacks_ != nullptr);
    callbacks_->on_egress(boost::asio::buffer("PASS foobar\r\n"));
}
