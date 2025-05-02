#include <gui/containers/menu_food.hpp>
#include <gui/screen_main_screen/Screen_MainView.hpp>


//TIM_HandleTypeDef htim2;

menu_food::menu_food()
{

}

void menu_food::initialize()
{
    menu_foodBase::initialize();
}

void menu_food::backMenu(){
	Screen_MainView* screen = static_cast<Screen_MainView*>(touchgfx::Application::getInstance()->getCurrentScreen());

	// Access containers using public getter methods
	screen->getContainerMenuFood().setVisible(false);
	screen->getContainerMenuFood().invalidate();

	screen->getContainerMenuMain().setVisible(true);
	screen->getContainerMenuMain().invalidate();
}

void menu_food::eating_animation(int i){
	Screen_MainView* screen = static_cast<Screen_MainView*>(touchgfx::Application::getInstance()->getCurrentScreen());
	screen->activateFoodAnimation=true;
	screen->typefood=i;
}

void menu_food::eating_animation_button1(){
	eating_animation(1);
}

void menu_food::eating_animation_button2(){
	eating_animation(2);
}

void menu_food::eating_animation_button3(){
	eating_animation(3);
}
