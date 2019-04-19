#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <cmsis_os.h>
#include "main.h"

extern osMailQId  timeMsgBox_g;

Model::Model() : modelListener(0)
{
}

void Model::tick()
{
  osEvent evt;
  time_t *mail;
  
  evt = osMailGet(timeMsgBox_g, osWaitForever);
  if (evt.status == osEventMail)
  {
    mail = (time_t *) evt.value.p;
    
    if (mail != 0)
    {
      
    }
  }
}
