#ifndef ALLZONESCONTAINER_HPP
#define ALLZONESCONTAINER_HPP

#include <gui_generated/containers/AllZonesContainerBase.hpp>
#include <gui/containers/SingleZoneContainer.hpp>

class AllZonesContainer : public AllZonesContainerBase
{
public:
    AllZonesContainer();
    virtual ~AllZonesContainer() {}

    virtual void initialize();

    void SetCloseContainerCallback(GenericCallback<void>& callback)
    {
        closeContainerCallback = &callback;
    }

    bool AddNewZone(uint8_t type, Unicode::UnicodeChar *pZoneName);
    void DeleteAllZones();

protected:
    virtual void CloseButtonClicked();
    virtual void ResetButtonClicked();

    GenericCallback<void>* closeContainerCallback;

private:
    uint16_t GetFirstFreeContainerInfoIndex();

    static constexpr uint32_t ZONE_CONTAINER_COUNT_MAX = 100;
    static constexpr uint32_t ZONE_CONTAINER_4_HEIGHT = 110;
    static constexpr uint32_t ZONE_CONTAINER_8_HEIGHT = 180;
    enum
    {
        ZONE_TYPE_4 = 0,
        ZONE_TYPE_8 = 1
    };

    struct ZoneInfos
    {
        SingleZoneContainer zoneContainer;
        uint8_t isUsed : 1;
        uint8_t type : 1;
    };

    ZoneInfos m_zonesInfos[ZONE_CONTAINER_COUNT_MAX];
    uint16_t m_lastZoneContainerEndY;
};

#endif // ALLZONESCONTAINER_HPP
