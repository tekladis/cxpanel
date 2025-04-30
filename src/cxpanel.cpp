#include "cxpanel.h"

CxPanel::CxPanel(Xcb::Connection& connection)
  : Xcb::Window(connection)
{
}
