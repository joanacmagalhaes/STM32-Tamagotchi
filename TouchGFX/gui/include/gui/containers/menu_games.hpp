#ifndef MENU_GAMES_HPP
#define MENU_GAMES_HPP

#include <gui_generated/containers/menu_gamesBase.hpp>

class menu_games : public menu_gamesBase
{
public:
    menu_games();
    virtual ~menu_games() {}

    virtual void initialize();

    virtual void backMenu();
    virtual void runGame2();
protected:
};

#endif // MENU_GAMES_HPP
