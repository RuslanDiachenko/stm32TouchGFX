#include <stdint.h>
#include <touchgfx/Unicode.hpp>

#ifndef NO_USING_NAMESPACE_TOUCHGFX
using namespace touchgfx;
#endif



// Language Gb: No substitution
TEXT_LOCATION_FLASH_PRAGMA
KEEP const touchgfx::Unicode::UnicodeChar T_SingleUseId1_Gb[4] TEXT_LOCATION_FLASH_ATTRIBUTE = { 0x2, 0x3a, 0x2, 0x0 };
TEXT_LOCATION_FLASH_PRAGMA
KEEP const touchgfx::Unicode::UnicodeChar T_SingleUseId3_Gb[3] TEXT_LOCATION_FLASH_ATTRIBUTE = { 0x30, 0x30, 0x0 };
TEXT_LOCATION_FLASH_PRAGMA
KEEP const touchgfx::Unicode::UnicodeChar T_SingleUseId5_Gb[3] TEXT_LOCATION_FLASH_ATTRIBUTE = { 0x70, 0x6d, 0x0 };

TEXT_LOCATION_FLASH_PRAGMA
KEEP extern const touchgfx::Unicode::UnicodeChar* const textsGb[5] TEXT_LOCATION_FLASH_ATTRIBUTE =
{
    T_SingleUseId1_Gb,
    T_SingleUseId3_Gb+1,
    T_SingleUseId3_Gb,
    T_SingleUseId1_Gb+2,
    T_SingleUseId5_Gb
};

