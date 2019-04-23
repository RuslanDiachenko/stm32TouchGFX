/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/ZoneNameContainerBase.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

ZoneNameContainerBase::ZoneNameContainerBase() :
    buttonCallback(this, &ZoneNameContainerBase::buttonCallbackHandler)
{
    setWidth(228);
    setHeight(50);

    zoneToggleButton.setXY(127, 6);
    zoneToggleButton.setBitmaps(Bitmap(BITMAP_BLUE_TOGGLEBARS_TOGGLE_SMALL_BUTTON_OFF_ID), Bitmap(BITMAP_BLUE_TOGGLEBARS_TOGGLE_SMALL_BUTTON_ON_ID));
    zoneToggleButton.setAction(buttonCallback);

    zoneNameArea.setXY(22, 13);
    zoneNameArea.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    zoneNameArea.setLinespacing(0);
    Unicode::snprintf(zoneNameAreaBuffer, ZONENAMEAREA_SIZE, "%s", TypedText(T_SINGLEUSEID2).getText());
    zoneNameArea.setWildcard(zoneNameAreaBuffer);
    zoneNameArea.resizeToCurrentText();
    zoneNameArea.setTypedText(TypedText(T_SINGLEUSEID1));

    add(zoneToggleButton);
    add(zoneNameArea);
}

void ZoneNameContainerBase::initialize()
{
	
}

void ZoneNameContainerBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &zoneToggleButton)
    {
        //Interaction1
        //When zoneToggleButton clicked call virtual function
        //Call zoneButtonIsClocked
        zoneButtonIsClocked();
    }
}
