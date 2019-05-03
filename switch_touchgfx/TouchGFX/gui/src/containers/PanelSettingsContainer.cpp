#include <gui/containers/PanelSettingsContainer.hpp>
#include "main.h"
#include "stm32f4xx_hal.h" 

extern TIM_HandleTypeDef htim4;

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

static void changePWMOut(uint16_t pulseWidth)
{
  TIM_OC_InitTypeDef conf;

  conf.OCMode = TIM_OCMODE_PWM1;
  conf.Pulse = pulseWidth;
  conf.OCPolarity = TIM_OCPOLARITY_HIGH;
  conf.OCFastMode = TIM_OCFAST_DISABLE;

  HAL_TIM_PWM_ConfigChannel(&htim4, &conf, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
}

void PanelSettingsContainer::panelBrightnessSliderCallback(int value)
{
  //uint16_t newPWM = map(value, 0, 100, 700, 0);
  /* input min  - 0
     input max  - 100
     output min - 725
     output max - 0 */
  uint16_t newPWM = (value - 0) * (0 - 725) / (100 - 0) + 725;
  changePWMOut(newPWM);
}