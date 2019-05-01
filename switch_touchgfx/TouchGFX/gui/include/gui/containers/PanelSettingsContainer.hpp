#ifndef PANELSETTINGSCONTAINER_HPP
#define PANELSETTINGSCONTAINER_HPP

#include <gui_generated/containers/PanelSettingsContainerBase.hpp>

class PanelSettingsContainer : public PanelSettingsContainerBase
{
public:
    PanelSettingsContainer();
    virtual ~PanelSettingsContainer() {}

    virtual void initialize();

    void SetCloseContainerCallback(GenericCallback<void>& callback)
    {
        m_pCloseContainerCallback = &callback;
    }

protected:
    virtual void CloseButtonClicked();

private:
    GenericCallback<void>* m_pCloseContainerCallback;
};

#endif // PANELSETTINGSCONTAINER_HPP
