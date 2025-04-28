#include "panel.h"

Panel::Panel(const Xcb::Connection& connection) :
  Xcb::Window(connection)
{
}
