#ifndef CUSTOMCONTAINER_HPP
#define CUSTOMCONTAINER_HPP

#include <gui_generated/containers/CustomContainerBase.hpp>
#include <touchgfx/Callback.hpp>

class CustomContainer : public CustomContainerBase
{
public:
    CustomContainer();
    virtual ~CustomContainer() {}

    virtual void initialize();
    
    void setCloseContainerOnViewCallback(GenericCallback<void>& callback)
    {
        closeContainerOnView = &callback;
    }

protected:
    virtual void closeButtonCallback()
    {
      closeContainerOnView->execute();
    }
    
    GenericCallback<void>* closeContainerOnView;
};

#endif // CUSTOMCONTAINER_HPP
