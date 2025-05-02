#ifndef SCREEN_MAINVIEW_HPP
#define SCREEN_MAINVIEW_HPP

#include <gui_generated/screen_main_screen/Screen_MainViewBase.hpp>
#include <gui/screen_main_screen/Screen_MainPresenter.hpp>

class Screen_MainView : public Screen_MainViewBase
{
public:
    Screen_MainView();
    virtual ~Screen_MainView() {}

    // Public methods to access containers
	menu_games& getContainerMenuGames() { return container_menu_games; }
	menu_main& getContainerMenuMain() { return container_menu_main; }
	menu_clothes& getContainerMenuClothes(){return container_menu_clothes; }
	menu_food& getContainerMenuFood(){ return container_menu_food; }
	face_smile& getContainerFaceSmile() { return container_face_smile; }
	face_smile_2& getContainerFaceSmile2() { return container_face_smile_2; }
	face_eating_1& getContainerFaceEating1() { return container_face_eating_1; }
	face_eating_2& getContainerFaceEating2() { return container_face_eating_2; }
	face_eating_3& getContainerFaceEating3() { return container_face_eating_3; }
	face_neutral& getContainerFaceNeutral() { return container_face_neutral; }
	poop& getContainerPop() {return container_poop;}
	touchgfx::Button& getButtonClothesPrev() { return button_clothes_prev; }
	touchgfx::Button& getButtonClothesNext() { return button_clothes_next; }
	touchgfx::Image& getImageBunnyHat() { return bunny_hat; }
	touchgfx::Image& getImageHeartSunglasses() { return heart_sunglasses; }
	touchgfx::Image& getImageAppleHat() { return apple_hat; }
	touchgfx::Image& getImageCupcake() { return cupcake; }
	touchgfx::Image& getImageJuice() { return juice; }
	touchgfx::Image& getImagePizza() { return pizza; }
	touchgfx::Image& getAstronautHat() { return astronaut_hat; }



	//struct and array for jumping animation
	struct MovableItem {
	        touchgfx::Drawable* item;
	        int yOffset;
	    };

	MovableItem movableItems[6]; //array of items to be in movement - first acessories and then faces

	//var for animation smile - after clothes confirmed
	bool activateSmile2_animation;
    int transitionCounter_Smile2;

    //var for animation food
    bool activateFoodAnimation;
    int transitionCounter_food;
    int transitionScene_food;
    float foodScale;
    bool foodAvailable;
    int typefood;
    int transitionCounter_foodMeter;
    int foodMeter;
    bool isFull;
    bool isDead;
    bool time2Poop;
    int transitionCounter_poop;
    int liveOfGame;
    //bool eatingOnGoing;

    //var for animation neutral face
    int transitionCounter_Neutral;

    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
    virtual void clothes_prev();
    virtual void next_clothes();
    void animationSmile2();
    void animationJumping();
    void animationEating();
    void animationFaceNeutral();
    void decFoodMeter();
    void animationFaceDead();
    void showPoop();
    //void incFoodMeter();
private:
    const int maxBounceOffset = 10; // Maximum pixels to move up and down
    float angle;          // Angle for sine wave calculation
    const float speed = 0.05f;   // Speed of oscillation (lower = slower)

    touchgfx::Image* clothesImages[4]; // Array of image pointers
    int currentClothesIndex;           // Current visible image index

};

#endif // SCREEN_MAINVIEW_HPP
