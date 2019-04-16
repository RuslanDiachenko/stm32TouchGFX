/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef TIMER_VIEW_BASE_HPP
#define TIMER_VIEW_BASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/timer_screen/TimerPresenter.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/canvas/Circle.hpp>
#include <touchgfx/widgets/canvas/PainterRGB888.hpp>
#include <touchgfx/EasingEquations.hpp>
#include <touchgfx/mixins/MoveAnimator.hpp>

class TimerViewBase : public touchgfx::View<TimerPresenter>
{
public:
    TimerViewBase();
    virtual ~TimerViewBase() {}

    virtual void setupScreen();
    virtual void afterTransition();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Image background_Screen21;
    touchgfx::Button buttonSettings;
    touchgfx::MoveAnimator< touchgfx::TextAreaWithTwoWildcards > textClock;
    touchgfx::MoveAnimator< touchgfx::Circle > circle;
    touchgfx::PainterRGB888 circlePainter;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTCLOCKBUFFER1_SIZE = 3;
    touchgfx::Unicode::UnicodeChar textClockBuffer1[TEXTCLOCKBUFFER1_SIZE];
    static const uint16_t TEXTCLOCKBUFFER2_SIZE = 3;
    touchgfx::Unicode::UnicodeChar textClockBuffer2[TEXTCLOCKBUFFER2_SIZE];

private:

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

    /*
     * Callback Declarations
     */
    touchgfx::Callback<TimerViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Canvas Buffer Size
     */
    static const uint16_t CANVAS_BUFFER_SIZE = 7200;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];

};

#endif // TIMER_VIEW_BASE_HPP
