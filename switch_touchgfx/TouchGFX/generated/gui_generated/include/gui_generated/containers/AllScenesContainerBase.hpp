/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef ALLSCENESCONTAINER_BASE_HPP
#define ALLSCENESCONTAINER_BASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/ToggleButton.hpp>

class AllScenesContainerBase : public touchgfx::Container
{
public:
    AllScenesContainerBase();
    virtual ~AllScenesContainerBase() {}

    virtual void initialize();

    /*
     * Custom Action Handlers
     */
    virtual void CloseButtonClicked()
    {
        // Override and implement this function in AllScenesContainer
    }

    virtual void BackButtonClicked()
    {
        // Override and implement this function in AllScenesContainer
    }

    virtual void SceneButton0Clicked()
    {
        // Override and implement this function in AllScenesContainer
    }

    virtual void SceneButton1Clicked()
    {
        // Override and implement this function in AllScenesContainer
    }

    virtual void SceneButton2Clicked()
    {
        // Override and implement this function in AllScenesContainer
    }

    virtual void SceneButton3Clicked()
    {
        // Override and implement this function in AllScenesContainer
    }

    virtual void SceneButton4Clicked()
    {
        // Override and implement this function in AllScenesContainer
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Button backButton;
    touchgfx::Button closeButton;
    touchgfx::TextArea containerNameText;
    touchgfx::ToggleButton sceneButton0;
    touchgfx::ToggleButton sceneButton1;
    touchgfx::ToggleButton sceneButton2;
    touchgfx::ToggleButton sceneButton3;
    touchgfx::ToggleButton sceneButton4;
    touchgfx::TextArea sceneNameText4;
    touchgfx::TextArea sceneNameText3;
    touchgfx::TextArea sceneNameText2;
    touchgfx::TextArea sceneNameText1;
    touchgfx::TextArea sceneNameText0;

private:

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

    /*
     * Callback Declarations
     */
    touchgfx::Callback<AllScenesContainerBase, const touchgfx::AbstractButton&> buttonCallback;

};

#endif // ALLSCENESCONTAINER_BASE_HPP
