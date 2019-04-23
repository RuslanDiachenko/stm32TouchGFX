#include <gui/main_screen/MainView.hpp>

MainView::MainView() :
  closeContainer(this, &MainView::closeContainerOnView)
{
    customContainer.setCloseContainerOnViewCallback(closeContainer);
  
}

void MainView::setupScreen()
{
    MainViewBase::setupScreen();
}

void MainView::tearDownScreen()
{
    MainViewBase::tearDownScreen();
}

void MainView::closeContainerOnView(void)
{
  customContainer.clearMoveAnimationEndedAction();
  customContainer.startMoveAnimation(9, 487, 12, EasingEquations::linearEaseIn, EasingEquations::linearEaseIn);
}