#include <gui/containers/PanelSettingsContainer.hpp>

PanelSettingsContainer::PanelSettingsContainer():
  m_currentPressedButton(PressedButton::UrbanStyle)
{
  urbanStyleButton.forceState(true);
  urbanStyleButtonClicked();
}

void PanelSettingsContainer::initialize()
{
    PanelSettingsContainerBase::initialize();
}

void PanelSettingsContainer::CloseButtonClicked()
{
    m_pCloseContainerCallback->execute();
}

void PanelSettingsContainer::urbanStyleButtonClicked(void)
{
  if (urbanStyleButton.getState())
  {
    m_currentPressedButton = PressedButton::UrbanStyle;
    
    urbanStyleButton.setTouchable(false);
    
    darkStyleButton.setTouchable(true);
    darkStyleButton.forceState(false);
    darkStyleButton.invalidate();
    
    lightStyleButton.setTouchable(true);
    lightStyleButton.forceState(false);
    lightStyleButton.invalidate();
  }
}

void PanelSettingsContainer::darkStyleButtonClicked(void)
{
  if (darkStyleButton.getState())
  {
    m_currentPressedButton = PressedButton::DarkStyle;
    
    darkStyleButton.setTouchable(false);
    
    urbanStyleButton.setTouchable(true);
    urbanStyleButton.forceState(false);
    urbanStyleButton.invalidate();
    
    lightStyleButton.setTouchable(true);
    lightStyleButton.forceState(false);
    lightStyleButton.invalidate();
  }
}

void PanelSettingsContainer::lightStyleButtonClicked(void)
{
  if (lightStyleButton.getState())
  {
    m_currentPressedButton = PressedButton::LightStyle;
    
    lightStyleButton.setTouchable(false);
    
    urbanStyleButton.setTouchable(true);
    urbanStyleButton.forceState(false);
    urbanStyleButton.invalidate();
    
    darkStyleButton.setTouchable(true);
    darkStyleButton.forceState(false);
    darkStyleButton.invalidate();
  }
}
