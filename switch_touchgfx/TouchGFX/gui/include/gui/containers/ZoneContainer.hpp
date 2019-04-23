#ifndef ZONECONTAINER_HPP
#define ZONECONTAINER_HPP

#include <gui_generated/containers/ZoneContainerBase.hpp>

class ZoneContainer : public ZoneContainerBase
{
public:
    ZoneContainer();
    virtual ~ZoneContainer() {}

    virtual void initialize();
protected:
};

#endif // ZONECONTAINER_HPP
