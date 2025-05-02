#ifndef MENU_MAIN_HPP
#define MENU_MAIN_HPP

#include <gui_generated/containers/menu_mainBase.hpp>

class menu_main : public menu_mainBase
{
public:
    menu_main();
    virtual ~menu_main() {}

    virtual void initialize();

    virtual void goGameMenu();
    virtual void buttonClothes();
    virtual void buttonFood();
protected:
};

#endif // MENU_MAIN_HPP
