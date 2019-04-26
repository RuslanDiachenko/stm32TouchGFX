#include <gui/main_screen/MainView.hpp>

MainView::MainView() :
    closeAllZonesContainer(this, &MainView::CloseAllZonesContainerHandler)
{
    allZonesContainer.SetCloseContainerCallback(closeAllZonesContainer);
}

void MainView::setupScreen()
{
    MainViewBase::setupScreen();
}

void MainView::tearDownScreen()
{
    MainViewBase::tearDownScreen();
}

void MainView::CloseAllZonesContainerHandler(void)
{
    allZonesContainer.clearMoveAnimationEndedAction();
    allZonesContainer.startMoveAnimation(9, 487, 12, EasingEquations::linearEaseIn, EasingEquations::linearEaseIn);
}

void MainView::setSunState(int newSunState, int hour, int minute, int hF, int dow)
{
  int16_t endX, endY;
  switch (newSunState)
  {
  case 0:
    endX = 23;
    endY = 374;
    break;
  case 1:
    endX = 43;
    endY = 352;
    break;
  case 2:
    endX = 66;
    endY = 336;
    break;
  case 3:
    endX = 94;
    endY = 324;
    break;
  case 4:
    endX = 123;
    endY = 320;
    break;
  case 5:
    endX = 154;
    endY = 324;
    break;
  case 6:
    endX = 182;
    endY = 336;
    break;
  case 7:
    endX = 206;
    endY = 352;
    break;
  case 8:
    endX = 225;
    endY = 374;
    break;
  }
  
  Unicode::snprintf(clockNumBuffer1, CLOCKNUMBUFFER1_SIZE, "%d", hour);
  Unicode::snprintf(clockNumBuffer2, CLOCKNUMBUFFER2_SIZE, "%02d", minute);
  clockNum.invalidate();
  
  if (hF)
    Unicode::snprintf(clockTextBuffer, CLOCKTEXT_SIZE, "%s", 'pm');
  else
    Unicode::snprintf(clockTextBuffer, CLOCKTEXT_SIZE, "%s", 'am');
  clockText.invalidate();
  
  touchgfx::Unicode::UnicodeChar dayOfWeekStr[10] = {0};
  touchgfx::Unicode::UnicodeChar MondayStr[7] = {0x4D, 0x6F, 0x6E, 0x64, 0x61, 0x79};

  switch (dow)
  {
  case 0:
    Unicode::snprintf(dayOfWeekStr, 7, "%s", MondayStr);
    break;
  case 1:
    Unicode::snprintf(dayOfWeekStr, 10, "%s", "Tuesday");
    break;
  case 2:
    Unicode::snprintf(dayOfWeekStr, 10, "%s", "Wednesday");
    break;
  case 3:
    Unicode::snprintf(dayOfWeekStr, 10, "%s", "Thursday");
    break;
  case 4:
    Unicode::snprintf(dayOfWeekStr, 10, "%s", "Friday");
    break;
  case 5:
    Unicode::snprintf(dayOfWeekStr, 10, "%s", "Saturday");
    break;
  case 6:
    Unicode::snprintf(dayOfWeekStr, 10, "%s", "Sunday");
    break;
  }
  
  Unicode::snprintf(dayOfWeekBuffer, DAYOFWEEK_SIZE, "%s", dayOfWeekStr);
  dayOfWeek.invalidate();
  
  sunIcon.clearMoveAnimationEndedAction();
  sunIcon.startMoveAnimation(endX, endY, 48, EasingEquations::linearEaseIn, EasingEquations::linearEaseIn);
}