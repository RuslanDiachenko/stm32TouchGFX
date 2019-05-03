#ifndef PANELSETTINGSCONTAINER_HPP
#define PANELSETTINGSCONTAINER_HPP

#include <gui_generated/containers/PanelSettingsContainerBase.hpp>

class PanelSettingsContainer : public PanelSettingsContainerBase
{
public:
    PanelSettingsContainer();
    virtual ~PanelSettingsContainer() {}

    virtual void initialize();

    virtual void urbanStyleButtonClicked(void);
    virtual void darkStyleButtonClicked(void);
    virtual void lightStyleButtonClicked(void);
    
    virtual void panelBrightnessSliderCallback(int value);
    
    void SetCloseContainerCallback(GenericCallback<void>& callback)
    {
        m_pCloseContainerCallback = &callback;
    }

protected:
    virtual void CloseButtonClicked();

private:
    GenericCallback<void>* m_pCloseContainerCallback;
    
    enum class PressedButton : uint8_t
    {
        LightStyle,
        DarkStyle,
        UrbanStyle
    };
    
    PressedButton m_currentPressedButton;
};

#endif // PANELSETTINGSCONTAINER_HPP
