#include <gui/screen_game_1_screen/Screen_Game_1View.hpp>
#include "stm32f7xx_hal.h"

extern ADC_HandleTypeDef hadc1;
uint32_t adc_value;
uint32_t flameThreshold = 100;

Screen_Game_1View::Screen_Game_1View()
	:tickCount(0),
	 sensorMonitoringEnabled(true),
	 lastSensorCheckTick(0),
	 SENSOR_CHECK_INTERVAL(10),
	 counterLevelsIce(0),
	 updateValueIceMelting(100),
	 setAlpha(255),
	 waitingForRelease(false) // New state variable
{

}

void Screen_Game_1View::setupScreen()
{
    Screen_Game_1ViewBase::setupScreen();
    HAL_ADC_Start(&hadc1);
}

void Screen_Game_1View::tearDownScreen()
{
    Screen_Game_1ViewBase::tearDownScreen();
}

void Screen_Game_1View::handleTickEvent(){
	tickCount++;

	    if (sensorMonitoringEnabled && (tickCount - lastSensorCheckTick > SENSOR_CHECK_INTERVAL))
	    {
	        lastSensorCheckTick = tickCount;

	        if (HAL_ADC_PollForConversion(&hadc1, 1) == HAL_OK)
	        {
	            adc_value = HAL_ADC_GetValue(&hadc1);

	            if (adc_value < flameThreshold && !waitingForRelease)
	            {
	                // New flame detected
	                waitingForRelease = true; // Require release before next detection

	                if(counterLevelsIce < 2) {
	                    counterLevelsIce++;
	                    updateValueIceMelting -= 40;
	                    progress_iceMelting.updateValue(updateValueIceMelting, 0);
	                    setAlpha -= 75;
	                    iceCube.setAlpha(setAlpha);
	                    iceCube.invalidate();
	                }
	                else {
	                    // Final step
	                    setAlpha = 255;
	                    iceCube.setAlpha(0);
	                    iceCube.invalidate();
	                    sensorMonitoringEnabled = false;
	                    progress_iceMelting.updateValue(0, 0);
	                    counterLevelsIce = 0;
	                    container_face_sad.setVisible(false);
	                    container_face_sad.invalidate();
	                    container_face_smile.setVisible(true);
	                    container_face_smile.invalidate();
	                    //gameWin = true;
	                    tickCount=0;
	                }
	            }
	            else if (adc_value >= flameThreshold && waitingForRelease)
	            {
	                // Flame removed after detection
	                waitingForRelease = false; // Ready for next interaction
	            }

	            HAL_ADC_Start(&hadc1); // Restart conversion
	        }
	    }

//	    if(gameWin && tickCount>60){
//	        gameWin = false;
//	        application().gotoScreen_MainScreenNoTransition();
//	    }
}
