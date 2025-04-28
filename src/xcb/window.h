#ifndef XCB_WINDOW_H
#define XCB_WINDOW_H
#include "connection.h"

namespace Xcb {

class Window
{
  public:
    Window(Xcb::Connection& connection);
    void setPosition(uint32_t x, uint32_t y);
    void setSize(uint32_t width, uint32_t height);

    void show();

  private:
    Xcb::Connection* m_connection;
    xcb_drawable_t m_window;
};

} // namespace Xcb

#endif // XCB_WINDOW_H
