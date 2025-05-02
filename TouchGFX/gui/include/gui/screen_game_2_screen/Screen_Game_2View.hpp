#ifndef SCREEN_GAME_2VIEW_HPP
#define SCREEN_GAME_2VIEW_HPP

#include <gui_generated/screen_game_2_screen/Screen_Game_2ViewBase.hpp>
#include <gui/screen_game_2_screen/Screen_Game_2Presenter.hpp>

class Screen_Game_2View : public Screen_Game_2ViewBase
{
public:
    Screen_Game_2View();
    virtual ~Screen_Game_2View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SCREEN_GAME_2VIEW_HPP
