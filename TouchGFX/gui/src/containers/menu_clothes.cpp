#include <gui/containers/menu_clothes.hpp>
#include <gui/screen_main_screen/Screen_MainView.hpp>

menu_clothes::menu_clothes()
{

}

void menu_clothes::initialize()
{
    menu_clothesBase::initialize();
}

void menu_clothes::clothes_confirm(){

	Screen_MainView* screen = static_cast<Screen_MainView*>(touchgfx::Application::getInstance()->getCurrentScreen());
	screen->activateSmile2_animation=true;

	transitionMainMenu();

}

void menu_clothes::clothes_cancel(){
	//all hats hidden
	Screen_MainView* screen = static_cast<Screen_MainView*>(touchgfx::Application::getInstance()->getCurrentScreen());

	for (int i = 0; i < 4; i++) {
		if (screen->movableItems[i].item->isVisible()) {
			screen->movableItems[i].item->setVisible(false);
			screen->movableItems[i].item->invalidate();
		}
	}
	transitionMainMenu();
}

void menu_clothes::transitionMainMenu(){
	// Get a reference to the current screen
	Screen_MainView* screen = static_cast<Screen_MainView*>(touchgfx::Application::getInstance()->getCurrentScreen());

	// Hide the main menu container
	screen->getContainerMenuMain().setVisible(true);
	screen->getContainerMenuMain().invalidate();

	// Show the clothes menu container
	screen->getContainerMenuClothes().setVisible(false);
	screen->getContainerMenuClothes().invalidate();

	// Make the clothes navigation buttons visible
	screen->getButtonClothesPrev().setVisible(false);
	screen->getButtonClothesPrev().invalidate();

	screen->getButtonClothesNext().setVisible(false);
	screen->getButtonClothesNext().invalidate();
}

