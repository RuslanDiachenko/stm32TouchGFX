#ifndef CUSTOMCONTAINER_HPP
#define CUSTOMCONTAINER_HPP

#include <gui_generated/containers/CustomContainerBase.hpp>

class CustomContainer : public CustomContainerBase
{
public:
    CustomContainer();
    virtual ~CustomContainer() {}

    virtual void initialize();
protected:
};

#endif // CUSTOMCONTAINER_HPP
