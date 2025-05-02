#ifndef MENU_FOOD_HPP
#define MENU_FOOD_HPP

#include <gui_generated/containers/menu_foodBase.hpp>

class menu_food : public menu_foodBase
{
public:
    menu_food();
    virtual ~menu_food() {}

    virtual void initialize();
    virtual void backMenu();
    void eating_animation(int i);
    virtual void eating_animation_button1();
    virtual void eating_animation_button2();
    virtual void eating_animation_button3();
protected:
};

#endif // MENU_FOOD_HPP
