#include <gui/containers/PanelSettingsContainer.hpp>

#ifndef SIMULATOR
#include "main.h"
#include "cmsis_os.h"
#include "stm32f4xx_hal.h" 

extern TIM_HandleTypeDef htim4;
extern osTimerId sleepAfterTimerHandle;

sleep_after_state_t sleepAfterState_g = {1, 0, 60}; 
#endif

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
#ifndef SIMULATOR
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
  /*
  example of map function : 

  long map(long x, long in_min, long in_max, long out_min, long out_max)
  {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  } 
  */
  uint16_t newPWM = (value - 0) * (0 - 725) / (100 - 0) + 725;
  changePWMOut(newPWM);
}

void PanelSettingsContainer::sleepAfterSliderCallback(int value)
{
  uint16_t seconds = 0;
  sleepAfterState_g.infinity = 0;
  DBG_LOG("SLEP", "Value is - %d", value);
  if (value <= 33)
  {
    seconds = (value - 0) * (60 - 5) / (33 - 0) + 5;
  }
  else if (value > 33 && value <= 66)
  {
    seconds = (value - 34) * (300 - 60) / (64 - 34) + 60;
  }
  else if (value > 66 && value <= 98)
  {
    seconds = (value - 67) * (600 - 300) / (98 - 67) + 300;
  }
  else
  {
    seconds = 65535;
    sleepAfterState_g.infinity = 1;
  }
  sleepAfterState_g.duration = seconds;
  if (sleepAfterState_g.infinity)
    osTimerStop(sleepAfterTimerHandle);
  else 
    osTimerStart(sleepAfterTimerHandle, pdMS_TO_TICKS(seconds*1000));
  DBG_LOG("SLEP", "Seconds is - %d", seconds);
}
#else

void PanelSettingsContainer::panelBrightnessSliderCallback(int value)
{
  
}

void PanelSettingsContainer::sleepAfterSliderCallback(int value)
{
  
}
#endif