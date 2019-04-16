#ifndef TIMER_VIEW_HPP
#define TIMER_VIEW_HPP

#include <gui_generated/timer_screen/TimerViewBase.hpp>
#include <gui/timer_screen/TimerPresenter.hpp>

class TimerView : public TimerViewBase
{
public:
    TimerView();
    virtual ~TimerView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
protected:
    int16_t hour;
    int16_t minute;
    int16_t tickCount;
    int16_t addStart;
    int16_t addEnd;
};

#endif // TIMER_VIEW_HPP
