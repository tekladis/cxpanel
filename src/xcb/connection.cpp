#include "connection.h"

Xcb::Connection::Connection(std::string display)
  : m_connection(xcb_connect(display.empty() ? nullptr : display.c_str(),
                             &m_default_screen))
{
}

void
Xcb::Connection::Deleter::operator()(xcb_connection_t* connection)
{
  if (connection) {
    xcb_disconnect(connection);
  }
}

bool
Xcb::Connection::isValid()
{
  if (m_connection.get() && xcb_connection_has_error(m_connection.get()) == 0) {
    return true;
  }
  return false;
}

bool
Xcb::Connection::flush()
{
  return xcb_flush(m_connection.get()) > 0;
}

Xcb::Event
Xcb::Connection::waitForEvent()
{
  return { xcb_wait_for_event(m_connection.get()) };
}
