#ifndef CUSTOMCONTAINER1_HPP
#define CUSTOMCONTAINER1_HPP

#include <gui_generated/containers/CustomContainer1Base.hpp>
#include <BitmapDatabase.hpp>
#include <math.h>
class CustomContainer1 : public CustomContainer1Base
{
public:
    CustomContainer1();
    virtual ~CustomContainer1() {}

    virtual void initialize();
    
    void offset(int16_t x)
    {
      icon001.moveTo(30 + x, icon001.getY());
      textArea1.moveTo(80 + x, textArea1.getY());
    }

    virtual void setY(int16_t y)
    {
      CustomContainer1Base::setY(y);
      
      const int circleRadius = 150;
      
      y = y - getHeight() / 2 - 250 / 2;
      
      float x_f = circleRadius - sqrtf((float)((circleRadius * circleRadius) - (y * y)));
      int16_t x = (int16_t)(x_f + 0.5f);
      
      offset(x);
    }
    
    void setNumber(int num)
    {
      Unicode::itoa(num, textArea1Buffer, TEXTAREA1_SIZE, 10);
      switch (num % 7)
      {
      case 0:
        icon001.setBitmap(Bitmap(BITMAP_ICON00_ID));
        break;
      case 1:
        icon001.setBitmap(Bitmap(BITMAP_ICON01_ID));
        break;
      case 2:
        icon001.setBitmap(Bitmap(BITMAP_ICON02_ID));
        break;
      case 3:
        icon001.setBitmap(Bitmap(BITMAP_ICON03_ID));
        break;
      case 4:
        icon001.setBitmap(Bitmap(BITMAP_ICON04_ID));
        break;
      case 5:
        icon001.setBitmap(Bitmap(BITMAP_ICON05_ID));
        break;
      case 6:
        icon001.setBitmap(Bitmap(BITMAP_ICON06_ID));
        break;
      }
    }
protected:
};

#endif // CUSTOMCONTAINER1_HPP
