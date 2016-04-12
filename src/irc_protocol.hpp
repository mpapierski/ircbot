#if !defined(IRCBOT_IRC_PROTOCOL_HPP_)
#define IRCBOT_IRC_PROTOCOL_HPP_

#include <memory>

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
    void set_callbacks(std::unique_ptr<callback> new_callbacks);
    /**
     * Feed the protocol with incoming bytes
     * @param data Data
     */
    void on_ingress(const boost::asio::const_buffer & data);
private:
    // Callbacks you want to use
    std::unique_ptr<callbacks> callbacks_;
};

#endif