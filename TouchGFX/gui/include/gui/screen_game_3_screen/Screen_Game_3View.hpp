#ifndef SCREEN_GAME_3VIEW_HPP
#define SCREEN_GAME_3VIEW_HPP

#include <gui_generated/screen_game_3_screen/Screen_Game_3ViewBase.hpp>
#include <gui/screen_game_3_screen/Screen_Game_3Presenter.hpp>

class Screen_Game_3View : public Screen_Game_3ViewBase
{
public:
    Screen_Game_3View();
    virtual ~Screen_Game_3View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SCREEN_GAME_3VIEW_HPP
