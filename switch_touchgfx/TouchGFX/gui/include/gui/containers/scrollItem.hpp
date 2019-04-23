#ifndef SCROLLITEM_HPP
#define SCROLLITEM_HPP

#include <gui_generated/containers/scrollItemBase.hpp>

class scrollItem : public scrollItemBase
{
public:
    scrollItem();
    virtual ~scrollItem() {}

    virtual void initialize();
protected:
};

#endif // SCROLLITEM_HPP
