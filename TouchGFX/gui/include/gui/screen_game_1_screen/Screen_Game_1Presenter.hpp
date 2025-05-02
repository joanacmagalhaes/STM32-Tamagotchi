#ifndef SCREEN_GAME_1PRESENTER_HPP
#define SCREEN_GAME_1PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen_Game_1View;

class Screen_Game_1Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Screen_Game_1Presenter(Screen_Game_1View& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~Screen_Game_1Presenter() {}

private:
    Screen_Game_1Presenter();

    Screen_Game_1View& view;
};

#endif // SCREEN_GAME_1PRESENTER_HPP
