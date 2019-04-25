#include <gui/main_screen/MainView.hpp>

MainView::MainView() :
    closeAllZonesContainer(this, &MainView::CloseAllZonesContainerHandler)
{
    allZonesContainer.SetCloseContainerCallback(closeAllZonesContainer);
}

void MainView::setupScreen()
{
    MainViewBase::setupScreen();
}

void MainView::tearDownScreen()
{
    MainViewBase::tearDownScreen();
}

void MainView::CloseAllZonesContainerHandler(void)
{
    allZonesContainer.clearMoveAnimationEndedAction();
    allZonesContainer.startMoveAnimation(9, 487, 12, EasingEquations::linearEaseIn, EasingEquations::linearEaseIn);
}
