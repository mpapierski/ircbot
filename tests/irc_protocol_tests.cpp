#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>
#include "irc_protocol.hpp"

struct mock_callbacks
    : irc_protocol::callbacks
{
    MOCK_METHOD1(on_egress, void(const boost::asio::const_buffer & data));
};

struct IrcProtocolTest
    : ::testing::Test
{
    void SetUp()
    {
        this->protocol = std::make_unique<irc_protocol>();
        this->callbacks = std::make_unique<testing::StrictMock<mock_callbacks>>();
    }
    void TearDown()
    {
        callbacks.reset();
    }
    std::unique_ptr<irc_protocol> protocol;
    std::unique_ptr<mock_callbacks> callbacks;
};

TEST_F (IrcProtocolTest, TestConnect)
{
    protocol->set_callbacks(callbacks.get());
}