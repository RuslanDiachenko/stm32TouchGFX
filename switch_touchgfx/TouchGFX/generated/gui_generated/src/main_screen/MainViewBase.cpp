/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/main_screen/MainViewBase.hpp>
#include "BitmapDatabase.hpp"

MainViewBase::MainViewBase() :
    buttonCallback(this, &MainViewBase::buttonCallbackHandler)
{
    image.setXY(0, 0);
    image.setBitmap(Bitmap(BITMAP_MAIN_SCREEN_ID));

    button1.setXY(51, 27);
    button1.setBitmaps(Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    button1.setAction(buttonCallback);

    zoneContainer1.setXY(9, 502);

    add(image);
    add(button1);
    add(zoneContainer1);
}

void MainViewBase::setupScreen()
{
    zoneContainer1.initialize();
}

void MainViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &button1)
    {
        //Interaction1
        //When button1 clicked move zoneContainer1
        //Move zoneContainer1 to x:9, y:30 with LinearIn easing in 200 ms (12 Ticks)
        zoneContainer1.clearMoveAnimationEndedAction();
        zoneContainer1.startMoveAnimation(9, 30, 12, EasingEquations::linearEaseIn, EasingEquations::linearEaseIn);
    }
}
