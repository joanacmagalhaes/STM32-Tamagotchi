#ifndef SCREEN_GAME_1VIEW_HPP
#define SCREEN_GAME_1VIEW_HPP

#include <gui_generated/screen_game_1_screen/Screen_Game_1ViewBase.hpp>
#include <gui/screen_game_1_screen/Screen_Game_1Presenter.hpp>

class Screen_Game_1View : public Screen_Game_1ViewBase
{
public:
    Screen_Game_1View();
    virtual ~Screen_Game_1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
protected:
    int tickCount;
    bool sensorMonitoringEnabled;
    int lastSensorCheckTick;
    int SENSOR_CHECK_INTERVAL;
    int counterLevelsIce;
    int updateValueIceMelting;
    int setAlpha;
   // bool gameWin;
    bool waitingForRelease;

};

#endif // SCREEN_GAME_1VIEW_HPP
