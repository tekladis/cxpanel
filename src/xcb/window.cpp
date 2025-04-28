#include "window.h"

// This is possibly poor design?
Xcb::Window::Window(Xcb::Connection& connection)
  : m_connection(&connection)
{
  m_window = xcb_generate_id(m_connection->get());
  // We pick the default screen here.  Use setScreen after
  // construction to override
  const xcb_setup_t* screen_setup = xcb_get_setup(m_connection->get());
  xcb_screen_t* screen_data = xcb_setup_roots_iterator(screen_setup).data;
  xcb_create_window(m_connection->get(),
                    XCB_COPY_FROM_PARENT,
                    m_window,
                    screen_data->root,
                    0,
                    0,
                    100,
                    100,
                    50,
                    XCB_WINDOW_CLASS_INPUT_OUTPUT,
                    screen_data->root_visual,
                    XCB_CW_BACK_PIXEL,
                    &screen_data->white_pixel);
}

void
Xcb::Window::setPosition(uint32_t x, uint32_t y)
{
  uint16_t mask{ XCB_CONFIG_WINDOW_X | XCB_CONFIG_WINDOW_Y };
  uint32_t position[]{ x, y };
  xcb_configure_window(m_connection->get(), m_window, mask, position);
}

void
Xcb::Window::setSize(uint32_t width, uint32_t height)
{
  uint16_t mask{ XCB_CONFIG_WINDOW_WIDTH | XCB_CONFIG_WINDOW_HEIGHT };
  uint32_t size[]{ width, height };
  xcb_configure_window(m_connection->get(), m_window, mask, size);
}

void
Xcb::Window::show()
{
  xcb_map_window(m_connection->get(), m_window);
}
