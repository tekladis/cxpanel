#ifndef XCB_EVENT_H
#define XCB_EVENT_H
#include <memory>
#include <xcb/xcb.h>

namespace Xcb {
class Event
{
  public:
    Event(xcb_generic_event_t* event);
    ~Event();
    Event(const Event&) = delete;
    Event& operator=(const Event&) = delete;
    const xcb_generic_event_t* get() { return m_event; }

  private:
    // TODO maybe use a smart pointer?
    xcb_generic_event_t* m_event;
};

} // namespace Xcb
#endif // EVENT_H
