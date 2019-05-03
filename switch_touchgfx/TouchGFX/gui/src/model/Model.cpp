#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

Model::Model() : modelListener(0)
{
}
#ifndef SIMULATOR
#include "cmsis_os.h"
#include "main.h"

extern osMailQId sunMsgBox_g;

static osEvent evt;
main_screen_state_t *mail;

void Model::tick()
{
  static uint8_t prevHour = 0, prevMinute = 0;
//  static unsigned int counter = 0;
//  if (counter >= 20)
//  {
//    counter = 0;
    evt = osMailGet(sunMsgBox_g, 0);
    if (evt.status == osEventMail)
    {
      mail = (main_screen_state_t *) evt.value.p;
      if (mail)
      {
        if (prevHour != mail->hour || prevMinute != mail->minute)
        {
          modelListener->notifySunStateChanged(mail->hour, mail->minute, mail->hF, mail->dayOfWeek);
        }
      }
      osMailFree(sunMsgBox_g, mail);
    }
//  }
//  counter++;
}
#else
void Model::tick()
{
    
}
#endif