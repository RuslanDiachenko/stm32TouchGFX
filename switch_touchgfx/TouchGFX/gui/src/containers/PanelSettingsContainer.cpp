#include <gui/containers/PanelSettingsContainer.hpp>

PanelSettingsContainer::PanelSettingsContainer()
{

}

void PanelSettingsContainer::initialize()
{
    PanelSettingsContainerBase::initialize();
}

void PanelSettingsContainer::CloseButtonClicked()
{
    m_pCloseContainerCallback->execute();
}
