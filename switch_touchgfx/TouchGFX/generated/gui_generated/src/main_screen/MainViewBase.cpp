/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/main_screen/MainViewBase.hpp>
#include "BitmapDatabase.hpp"

MainViewBase::MainViewBase() :
    updateItemCallback(this, &MainViewBase::updateItemCallbackHandler)
{
    black1.setXY(0, 0);
    black1.setBitmap(Bitmap(BITMAP_BLACK_ID));

    image.setXY(0, 0);
    image.setBitmap(Bitmap(BITMAP_BLACK_ID));

    scalableImage1.setBitmap(Bitmap(BITMAP_BACKGROUND_ID));
    scalableImage1.setPosition(106, 0, 268, 272);
    scalableImage1.setScalingAlgorithm(ScalableImage::NEAREST_NEIGHBOR);

    scrollWheel1.setPosition(125, 0, 249, 272);
    scrollWheel1.setHorizontal(false);
    scrollWheel1.setCircular(false);
    scrollWheel1.setEasingEquation(EasingEquations::backEaseOut);
    scrollWheel1.setSwipeAcceleration(10);
    scrollWheel1.setDragAcceleration(10);
    scrollWheel1.setNumberOfItems(10);
    scrollWheel1.setSelectedItemOffset(100);
    scrollWheel1.setDrawableSize(43, 5);
    scrollWheel1.setDrawables(scrollWheel1ListItems, updateItemCallback);
    scrollWheel1.animateToItem(0, 0);

    add(black1);
    add(image);
    add(scalableImage1);
    add(scrollWheel1);
}

void MainViewBase::setupScreen()
{
    scrollWheel1.initialize();
    for (int i = 0; i < scrollWheel1ListItems.getNumberOfDrawables(); i++)
    {
        scrollWheel1ListItems[i].initialize();
    }
}

void MainViewBase::updateItemCallbackHandler(DrawableListItemsInterface* items, int16_t containerIndex, int16_t itemIndex)
{
    if (items == &scrollWheel1ListItems)
    {
        Drawable* d = items->getDrawable(containerIndex);
        CustomContainer1* cc = (CustomContainer1*)d;
        scrollWheel1UpdateItem(*cc, itemIndex);
    }
}
