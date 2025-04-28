#ifndef XCB_WINDOW_H
#define XCB_WINDOW_H
#include "connection.h"

namespace Xcb {

class Window
{
  public:
    Window(const Xcb::Connection& connection);
    void resize(int width, int height);
    void show();
  private:
    // Since we don't own the connection here raw pointer is fine
    xcb_connection_t* m_connection;
    xcb_window_t m_window;
};

} // namespace Xcb

#endif // XCB_WINDOW_H
