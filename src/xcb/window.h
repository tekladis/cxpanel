#ifndef XCB_WINDOW_H
#define XCB_WINDOW_H
#include "connection.h"

namespace Xcb {

class Window
{
  public:
    Window(const Xcb::Connection& connection);
    void setPosition(uint32_t x, uint32_t y);
    void setSize(uint32_t width, uint32_t height);

    void show();

  private:
    // Since we don't own the connection here raw pointer is fine
    xcb_connection_t* m_connection;

    // TODO maybe use xcb_drawable_t instead?
    xcb_drawable_t m_window;
};

} // namespace Xcb

#endif // XCB_WINDOW_H
