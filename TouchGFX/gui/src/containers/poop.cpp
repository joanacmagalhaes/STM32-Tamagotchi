#include <gui/containers/poop.hpp>
#include <gui/screen_main_screen/Screen_MainView.hpp>

poop::poop()
{

}

void poop::initialize()
{
    poopBase::initialize();
}

void poop::poopClicked(){
	Screen_MainView* screen = static_cast<Screen_MainView*>(touchgfx::Application::getInstance()->getCurrentScreen());

	// Access containers using public getter methods
	screen->getContainerPop().setVisible(false);
	screen->getContainerPop().invalidate();
	screen->transitionCounter_poop=0;
	screen->time2Poop=false;
}
