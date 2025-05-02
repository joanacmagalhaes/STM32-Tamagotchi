#include <gui/containers/menu_games.hpp>
#include <gui/screen_main_screen/Screen_MainView.hpp>

menu_games::menu_games()
{

}

void menu_games::initialize()
{
    menu_gamesBase::initialize();
}
void menu_games::backMenu(){
	Screen_MainView* screen = static_cast<Screen_MainView*>(touchgfx::Application::getInstance()->getCurrentScreen());

	// Access containers using public getter methods
	screen->getContainerMenuGames().setVisible(false);
	screen->getContainerMenuGames().invalidate();

	screen->getContainerMenuMain().setVisible(true);
	screen->getContainerMenuMain().invalidate();
}

void menu_games::runGame2(){

}
