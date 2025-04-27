#include "event.h"
#include <cstdlib>

Xcb::Event::Event(xcb_generic_event_t* event)
  : m_event(event)
{
}

Xcb::Event::~Event()
{
  if (m_event) {
    free(m_event);
  }
}
