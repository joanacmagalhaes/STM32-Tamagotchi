#include <gui/containers/menu_main.hpp>
#include <gui/screen_main_screen/Screen_MainView.hpp>


menu_main::menu_main()
{

}

void menu_main::initialize()
{
    menu_mainBase::initialize();
}

void menu_main::goGameMenu()
{
    // Get a reference to the current screen
    Screen_MainView* screen = static_cast<Screen_MainView*>(touchgfx::Application::getInstance()->getCurrentScreen());

    // Access containers using public getter methods
    screen->getContainerMenuGames().setVisible(true);
    screen->getContainerMenuGames().invalidate();

    screen->getContainerMenuMain().setVisible(false);
    screen->getContainerMenuMain().invalidate();
}

void menu_main::buttonClothes(){
	// Get a reference to the current screen
	Screen_MainView* screen = static_cast<Screen_MainView*>(touchgfx::Application::getInstance()->getCurrentScreen());
	if(!(screen->isDead)){
	// Hide the main menu container
		screen->getContainerMenuMain().setVisible(false);
		screen->getContainerMenuMain().invalidate();

		// Show the clothes menu container
		screen->getContainerMenuClothes().setVisible(true);
		screen->getContainerMenuClothes().invalidate();

		// Make the clothes navigation buttons visible
		screen->getButtonClothesPrev().setVisible(true);
		screen->getButtonClothesPrev().invalidate();

		screen->getButtonClothesNext().setVisible(true);
		screen->getButtonClothesNext().invalidate();
	}

}

void menu_main::buttonFood(){
	Screen_MainView* screen = static_cast<Screen_MainView*>(touchgfx::Application::getInstance()->getCurrentScreen());
	if(!(screen->isDead)){
	// Hide the main menu container
		screen->getContainerMenuMain().setVisible(false);
		screen->getContainerMenuMain().invalidate();

		// Show the clothes menu container
		screen->getContainerMenuFood().setVisible(true);
		screen->getContainerMenuFood().invalidate();
	}
}
