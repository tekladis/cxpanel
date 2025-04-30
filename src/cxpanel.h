#ifndef CXPANEL_H
#define CXPANEL_H
#include "xcb/window.h"

class CxPanel : public Xcb::Window
{
  public:
    CxPanel(Xcb::Connection& connection);
};

#endif
