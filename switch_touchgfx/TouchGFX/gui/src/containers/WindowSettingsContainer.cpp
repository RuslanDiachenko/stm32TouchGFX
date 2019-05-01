#include <gui/containers/WindowSettingsContainer.hpp>

WindowSettingsContainer::WindowSettingsContainer() :
    m_currentPressedButton(PressedButton::AutoTint)
{
    autoTintButton.forceState(true);
    AutoTintButtonClicked();
}

void WindowSettingsContainer::initialize()
{
    WindowSettingsContainerBase::initialize();
}

void WindowSettingsContainer::CloseButtonClicked()
{
    m_pCloseContainerCallback->execute();
}

void WindowSettingsContainer::AutoTintButtonClicked()
{
    if (autoTintButton.getState())
    {
        m_currentPressedButton = PressedButton::AutoTint;

        autoTintButton.setTouchable(false);
        autoTintText.setAlpha(SETTINGS_TEXT_SELECTED_ALPHA);
        autoTintText.invalidate();

        manualTintButton.forceState(false);
        manualTintButton.invalidate();
        manualTintText.setAlpha(SETTINGS_TEXT_NOT_SELECTED_ALPHA);
        manualTintText.invalidate();

        presetScenesButton.forceState(false);
        presetScenesButton.invalidate();
        presetScenesText.setAlpha(SETTINGS_TEXT_NOT_SELECTED_ALPHA);
        presetScenesText.invalidate();
    }
}

void WindowSettingsContainer::ManualTintButtonClicked()
{
    if (manualTintButton.getState())
    {
        m_currentPressedButton = PressedButton::ManualTint;

        manualTintText.setAlpha(SETTINGS_TEXT_SELECTED_ALPHA);
        manualTintText.invalidate();

        autoTintButton.setTouchable(true);
        autoTintButton.forceState(false);
        autoTintButton.invalidate();
        autoTintText.setAlpha(SETTINGS_TEXT_NOT_SELECTED_ALPHA);
        autoTintText.invalidate();

        presetScenesButton.forceState(false);
        presetScenesButton.invalidate();
        presetScenesText.setAlpha(SETTINGS_TEXT_NOT_SELECTED_ALPHA);
        presetScenesText.invalidate();

        m_pOpenManualTintContainerCallback->execute();
    }
    else if(m_currentPressedButton == PressedButton::ManualTint)
    {
        manualTintButton.forceState(true);
        manualTintButton.invalidate();

        m_pOpenManualTintContainerCallback->execute();
    }
}

void WindowSettingsContainer::PresetScenesButtonClicked()
{
    if (presetScenesButton.getState())
    {
        m_currentPressedButton = PressedButton::PresetScenes;

        presetScenesText.setAlpha(SETTINGS_TEXT_SELECTED_ALPHA);
        presetScenesText.invalidate();

        autoTintButton.setTouchable(true);
        autoTintButton.forceState(false);
        autoTintButton.invalidate();
        autoTintText.setAlpha(SETTINGS_TEXT_NOT_SELECTED_ALPHA);
        autoTintText.invalidate();

        manualTintButton.forceState(false);
        manualTintButton.invalidate();
        manualTintText.setAlpha(SETTINGS_TEXT_NOT_SELECTED_ALPHA);
        manualTintText.invalidate();

        m_pOpenAllScenesContainerCallback->execute();
    }
    else if(m_currentPressedButton == PressedButton::PresetScenes)
    {
        presetScenesButton.forceState(true);
        presetScenesButton.invalidate();

        m_pOpenAllScenesContainerCallback->execute();
    }
}
