#include "panel.h"

Panel::Panel(Xcb::Connection& connection)
  : Xcb::Window(connection)
{
}
