#if !defined(IRCBOT_IRC_PROTOCOL_HPP_)
#define IRCBOT_IRC_PROTOCOL_HPP_

#include <memory>
#include <boost/asio.hpp>
#include <cassert>

/**
 * IRC protocol according to http://tools.ietf.org/html/rfc2812
 */
class irc_protocol
{
public:
    /**
     * Callbacks you should implement
     */
    class callbacks
    {
    public:
        /**
         * Send outgoing data to transport layer
         */
        virtual void on_egress(const boost::asio::const_buffer & data) = 0;
    };
    irc_protocol();
    /**
     * Set new callbacks pointers.
     *
     * It should be called after connection was established. Expect
     * some data to be sent.
     */
    void set_callbacks(callbacks * new_callbacks);
    /**
     * Feed the protocol with incoming bytes
     * @param data Data
     */
    void on_ingress(const boost::asio::const_buffer & data);
private:
    // Callbacks you want to use
    callbacks * callbacks_{nullptr};
    /**
     * This is what happens after connection is established.
     */
    void on_connect();
};

#endif