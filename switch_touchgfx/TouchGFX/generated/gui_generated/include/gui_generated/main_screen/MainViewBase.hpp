/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef MAIN_VIEW_BASE_HPP
#define MAIN_VIEW_BASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/main_screen/MainPresenter.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>

class MainViewBase : public touchgfx::View<MainPresenter>
{
public:
    MainViewBase();
    virtual ~MainViewBase() {}

    virtual void setupScreen();

    /*
     * Custom Action Handlers
     */
    virtual void buttonHourUpClicked()
    {
        // Override and implement this function in MainView
    }

    virtual void buttonHourDownClicked()
    {
        // Override and implement this function in MainView
    }

    virtual void buttonMinuteUpClicked()
    {
        // Override and implement this function in MainView
    }

    virtual void buttonMinuteDownClicked()
    {
        // Override and implement this function in MainView
    }

    virtual void buttonSaveHourClicked()
    {
        // Override and implement this function in MainView
    }

    virtual void buttonSaveMinuteClicked()
    {
        // Override and implement this function in MainView
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Image image;
    touchgfx::TextArea textAreaHourCaption;
    touchgfx::TextAreaWithOneWildcard textAreaHour;
    touchgfx::TextArea textAreaMinuteCaption;
    touchgfx::TextAreaWithOneWildcard textAreaMinute;
    touchgfx::Button buttonHourUp;
    touchgfx::Button buttonHourDown;
    touchgfx::Button buttonMinuteUp;
    touchgfx::Button buttonMinuteDown;
    touchgfx::ButtonWithLabel buttonSaveHour;
    touchgfx::ButtonWithLabel buttonSaveMinute;
    touchgfx::ButtonWithLabel buttonClock;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTAREAHOUR_SIZE = 3;
    touchgfx::Unicode::UnicodeChar textAreaHourBuffer[TEXTAREAHOUR_SIZE];
    static const uint16_t TEXTAREAMINUTE_SIZE = 3;
    touchgfx::Unicode::UnicodeChar textAreaMinuteBuffer[TEXTAREAMINUTE_SIZE];

private:

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

    /*
     * Callback Declarations
     */
    touchgfx::Callback<MainViewBase, const touchgfx::AbstractButton&> buttonCallback;

};

#endif // MAIN_VIEW_BASE_HPP
