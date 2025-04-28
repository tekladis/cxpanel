#ifndef PANEL_H
#define PANEL_H
#include "xcb/window.h"

class Panel : public Xcb::Window
{
  public:
    Panel(Xcb::Connection& connection);
};

#endif
