#ifndef MENU_CLOTHES_HPP
#define MENU_CLOTHES_HPP

#include <gui_generated/containers/menu_clothesBase.hpp>

class menu_clothes : public menu_clothesBase
{
public:
    menu_clothes();
    virtual ~menu_clothes() {}

    virtual void initialize();

    virtual void clothes_cancel();
    virtual void clothes_confirm();
    void transitionMainMenu();
protected:
};

#endif // MENU_CLOTHES_HPP
