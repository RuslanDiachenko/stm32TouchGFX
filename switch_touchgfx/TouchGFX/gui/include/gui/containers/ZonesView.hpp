#ifndef ZONESVIEW_HPP
#define ZONESVIEW_HPP

#include <gui_generated/containers/ZonesViewBase.hpp>

class ZonesView : public ZonesViewBase
{
public:
    ZonesView();
    virtual ~ZonesView() {}

    virtual void initialize();
protected:
};

#endif // ZONESVIEW_HPP
