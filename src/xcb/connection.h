#ifndef XCB_CONNECTION_H
#define XCB_CONNECTION_H
#include "event.h"
#include <string>
#include <xcb/xcb.h>
namespace Xcb {

class Connection
{
  public:
    Connection(std::string display = "");
    Connection(const Connection&) = delete;
    Connection& operator=(const Connection&) = delete;

    // Convenience function
    xcb_connection_t* get() { return m_connection.get(); }

    bool isValid();
    bool flush();

    Xcb::Event waitForEvent();

    xcb_atom_t atom(const std::string& atom);

  private:
    struct Deleter
    {
        void operator()(xcb_connection_t* connection);
    };
    std::unique_ptr<xcb_connection_t, Deleter> m_connection;

    // Other useful data
    int m_default_screen;
};

} // namespace Xcb

#endif // XCB_CONNECTION_H
