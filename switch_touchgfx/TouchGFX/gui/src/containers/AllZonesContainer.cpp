#include <gui/containers/AllZonesContainer.hpp>


AllZonesContainer::AllZonesContainer()
{
    for (uint32_t i = 0; i < ZONE_CONTAINER_COUNT_MAX; ++i)
    {
        m_zonesInfos[i].isUsed = false;
    }

    m_lastZoneContainerEndY = 0;

    //////////////////////////////////////
    Unicode::UnicodeChar zoneName[20];

    Unicode::strncpy(zoneName, "Zone 1", 20);
    AddNewZone(1, zoneName);

    Unicode::strncpy(zoneName, "Zone 2", 20);
    AddNewZone(0, zoneName);

    Unicode::strncpy(zoneName, "Zone 3", 20);
    AddNewZone(1, zoneName);

    Unicode::strncpy(zoneName, "Zone 4", 20);
    AddNewZone(1, zoneName);
    /////////////////////////////////////
}

void AllZonesContainer::initialize()
{
    AllZonesContainerBase::initialize();
}

void AllZonesContainer::CloseButtonClicked()
{
    scrollableAllZonesContainer.reset();
    closeContainerCallback->execute();
}

void AllZonesContainer::ResetButtonClicked()
{
    DeleteAllZones();

    Unicode::UnicodeChar zoneName[20];

    Unicode::strncpy(zoneName, "Zone 5", 20);
    AddNewZone(1, zoneName);

    Unicode::strncpy(zoneName, "Zone 6", 20);
    AddNewZone(0, zoneName);

    Unicode::strncpy(zoneName, "Zone 7", 20);
    AddNewZone(0, zoneName);

    Unicode::strncpy(zoneName, "Zone 8", 20);
    AddNewZone(1, zoneName);
}

bool AllZonesContainer::AddNewZone(uint8_t type, Unicode::UnicodeChar *pZoneName)
{
    uint16_t freeContainerInfoIndex = GetFirstFreeContainerInfoIndex();
    if (freeContainerInfoIndex == ZONE_CONTAINER_COUNT_MAX)
    {
        return false;
    }

    uint16_t zoneHeight = (type == ZONE_TYPE_4) ? ZONE_CONTAINER_4_HEIGHT : ZONE_CONTAINER_8_HEIGHT;

    m_zonesInfos[freeContainerInfoIndex].isUsed = true;
    m_zonesInfos[freeContainerInfoIndex].type = type;

    m_zonesInfos[freeContainerInfoIndex].zoneContainer.SetZoneNameText(pZoneName);
    m_zonesInfos[freeContainerInfoIndex].zoneContainer.setHeight(zoneHeight);
    m_zonesInfos[freeContainerInfoIndex].zoneContainer.setY(m_lastZoneContainerEndY);
    scrollableAllZonesContainer.add(m_zonesInfos[freeContainerInfoIndex].zoneContainer);

    scrollableAllZonesContainer.childGeometryChanged();
    scrollableAllZonesContainer.invalidate();

    m_lastZoneContainerEndY += zoneHeight;

    return true;
}

void AllZonesContainer::DeleteAllZones()
{
    scrollableAllZonesContainer.reset();
    scrollableAllZonesContainer.removeAll();
    scrollableAllZonesContainer.childGeometryChanged();
    scrollableAllZonesContainer.invalidate();

    m_lastZoneContainerEndY = 0;

    for (uint32_t i = 0; i < ZONE_CONTAINER_COUNT_MAX; ++i)
    {
        if (m_zonesInfos[i].isUsed)
        {
            m_zonesInfos[i].isUsed = false;
            m_zonesInfos[i].zoneContainer.ResetInfo();
        }
        else
        {
            break;
        }
    }
}

uint16_t AllZonesContainer::GetFirstFreeContainerInfoIndex()
{
    for (uint32_t i = 0; i < ZONE_CONTAINER_COUNT_MAX; ++i)
    {
        if (!m_zonesInfos[i].isUsed)
        {
            return i;
        }
    }

    return ZONE_CONTAINER_COUNT_MAX;
}
