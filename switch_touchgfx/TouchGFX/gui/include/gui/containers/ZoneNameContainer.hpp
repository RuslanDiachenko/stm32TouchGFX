#ifndef ZONENAMECONTAINER_HPP
#define ZONENAMECONTAINER_HPP

#include <gui_generated/containers/ZoneNameContainerBase.hpp>

class ZoneNameContainer : public ZoneNameContainerBase
{
public:
    ZoneNameContainer();
    virtual ~ZoneNameContainer() {}

    virtual void initialize();
protected:
};

#endif // ZONENAMECONTAINER_HPP
