// Generated by imageconverter. Please, do not edit!

#ifndef BITMAPDATABASE_HPP
#define BITMAPDATABASE_HPP

#include <touchgfx/hal/Types.hpp>
#include <touchgfx/Bitmap.hpp>

const uint16_t BITMAP_BACKGROUND_ID = 0; // Size: 390x390 pixels
const uint16_t BITMAP_BLACK_ID = 1; // Size: 480x272 pixels
const uint16_t BITMAP_ICON00_ID = 2; // Size: 36x36 pixels
const uint16_t BITMAP_ICON01_ID = 3; // Size: 36x36 pixels
const uint16_t BITMAP_ICON02_ID = 4; // Size: 36x36 pixels
const uint16_t BITMAP_ICON03_ID = 5; // Size: 36x36 pixels
const uint16_t BITMAP_ICON04_ID = 6; // Size: 36x36 pixels
const uint16_t BITMAP_ICON05_ID = 7; // Size: 36x36 pixels
const uint16_t BITMAP_ICON06_ID = 8; // Size: 36x36 pixels

namespace BitmapDatabase
{
#ifndef NO_USING_NAMESPACE_TOUCHGFX
using namespace touchgfx;
#endif

class BitmapData;
const touchgfx::Bitmap::BitmapData* getInstance();
uint16_t getInstanceSize();
}

#endif
