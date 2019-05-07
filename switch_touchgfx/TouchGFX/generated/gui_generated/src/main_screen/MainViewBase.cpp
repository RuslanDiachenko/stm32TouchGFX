/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/main_screen/MainViewBase.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

MainViewBase::MainViewBase() :
    buttonCallback(this, &MainViewBase::buttonCallbackHandler)
{
    windowSettingsButton.setXY(0, 0);
    windowSettingsButton.setBitmaps(Bitmap(BITMAP_BACKGROUND_IMAGE_ID), Bitmap(BITMAP_BACKGROUND_IMAGE_ID));
    windowSettingsButton.setAction(buttonCallback);
    windowSettingsButton.setAlpha(0);

    background.setXY(0, 0);
    background.setBitmap(Bitmap(BITMAP_BACKGROUND_IMAGE_ID));

    sunHorizontImg.setXY(1, 333);
    sunHorizontImg.setBitmap(Bitmap(BITMAP_COMBINEDGRAPHICNEW_ID));

    sunIcon.setXY(66, 336);
    sunIcon.setBitmap(Bitmap(BITMAP_SUN_ICON_ID));

    clockNum.setPosition(42, 50, 121, 49);
    clockNum.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    clockNum.setLinespacing(0);
    Unicode::snprintf(clockNumBuffer1, CLOCKNUMBUFFER1_SIZE, "%s", TypedText(T_SINGLEUSEID4).getText());
    clockNum.setWildcard1(clockNumBuffer1);
    Unicode::snprintf(clockNumBuffer2, CLOCKNUMBUFFER2_SIZE, "%s", TypedText(T_SINGLEUSEID5).getText());
    clockNum.setWildcard2(clockNumBuffer2);
    clockNum.setTypedText(TypedText(T_SINGLEUSEID3));

    clockText.setXY(165, 50);
    clockText.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    clockText.setLinespacing(0);
    Unicode::snprintf(clockTextBuffer, CLOCKTEXT_SIZE, "%s", TypedText(T_SINGLEUSEID7).getText());
    clockText.setWildcard(clockTextBuffer);
    clockText.resizeToCurrentText();
    clockText.setTypedText(TypedText(T_SINGLEUSEID6));

    dayOfWeek.setXY(30, 106);
    dayOfWeek.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    dayOfWeek.setLinespacing(0);
    Unicode::snprintf(dayOfWeekBuffer, DAYOFWEEK_SIZE, "%s", TypedText(T_SINGLEUSEID9).getText());
    dayOfWeek.setWildcard(dayOfWeekBuffer);
    dayOfWeek.resizeToCurrentText();
    dayOfWeek.setTypedText(TypedText(T_SINGLEUSEID8));

    backgroundBlur.setXY(0, 0);
    backgroundBlur.setBitmap(Bitmap(BITMAP_BACKGROUND_IMAGE_BLUR_ID));
    backgroundBlur.setAlpha(0);

    panelSettingsButton.setXY(220, 428);
    panelSettingsButton.setBitmaps(Bitmap(BITMAP_PANELSETTINGSBUTTONICON_ID), Bitmap(BITMAP_PANELSETTINGSBUTTONICON_ID));
    panelSettingsButton.setAction(buttonCallback);

    allZonesContainer.setXY(-260, 10);

    windowSettingsContainer.setXY(-260, 10);

    allScenesContainer.setXY(-260, 10);

    panelSettingsContainer.setXY(10, -410);

    saintGobainLogo.setXY(87, 433);
    saintGobainLogo.setBitmap(Bitmap(BITMAP_SAINTGOBAINLOGO_ID));

    add(windowSettingsButton);
    add(background);
    add(sunHorizontImg);
    add(sunIcon);
    add(clockNum);
    add(clockText);
    add(dayOfWeek);
    add(backgroundBlur);
    add(panelSettingsButton);
    add(allZonesContainer);
    add(windowSettingsContainer);
    add(allScenesContainer);
    add(panelSettingsContainer);
    add(saintGobainLogo);
}

void MainViewBase::setupScreen()
{
    allZonesContainer.initialize();
    windowSettingsContainer.initialize();
    allScenesContainer.initialize();
    panelSettingsContainer.initialize();
}

void MainViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &windowSettingsButton)
    {
        //WindowSettingsButtonClicked
        //When windowSettingsButton clicked call virtual function
        //Call WindowSettingsButtonClicked
        WindowSettingsButtonClicked();
    }
    else if (&src == &panelSettingsButton)
    {
        //PanelSettingsButtonClicked
        //When panelSettingsButton clicked call virtual function
        //Call PanelSettingsButtonClicked
        PanelSettingsButtonClicked();
    }
}
