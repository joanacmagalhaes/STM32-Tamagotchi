#include <gui/screen_main_screen/Screen_MainView.hpp>
#include <cmath> // For sin() and M_PI

Screen_MainView::Screen_MainView()
	: activateFoodAnimation(false),
	  foodScale(1.0f),
	  typefood(0),
	  isFull(false),
	  isDead(false),
	  time2Poop(false),
	  activateSmile2_animation(false)
{

}

void Screen_MainView::setupScreen()
{
    Screen_MainViewBase::setupScreen();
    angle = 0.0f;         // Start at angle 0
    transitionCounter_Smile2 = 0; // Reset counter
    transitionCounter_foodMeter=0;
    foodMeter=10;
    transitionCounter_Neutral=0;
	transitionCounter_food=0;
	transitionScene_food=0;
	transitionCounter_poop=0;
	liveOfGame=0;
	foodAvailable=true;
	currentClothesIndex=4;

    // Initialize the array with pointers to the images
	clothesImages[0] = &bunny_hat;
	clothesImages[1] = &heart_sunglasses;
	clothesImages[2] = &apple_hat;
	clothesImages[3] = &astronaut_hat;


    // Initialize movable items with their offsets
    movableItems[0] = {&bunny_hat, -25};        // Bunny hat offset
    movableItems[1] = {&heart_sunglasses, 33};  // Heart sunglasses offset
    movableItems[2] = {&apple_hat, -14};
    movableItems[3] = {&astronaut_hat, 10};
    movableItems[4] = {&container_face_smile, 7};
    movableItems[5] = {&container_face_smile_2, 8};

//    movableItems[5] = {&container_face_eating_1, 7};
//    movableItems[6] = {&container_face_eating_2, 7};
//    movableItems[7] = {&container_face_eating_3, 7};

}

void Screen_MainView::tearDownScreen()
{
    Screen_MainViewBase::tearDownScreen();
}

void Screen_MainView::handleTickEvent()
{
	//jumping animation
    if(!activateFoodAnimation && !isDead){
    	liveOfGame++;
    	animationJumping();
    	decFoodMeter();
    }

		//animation for when new clothes confirmed
	if(activateSmile2_animation){
		animationSmile2();
	}
		//eating animation
	if(activateFoodAnimation){
		if(!foodAvailable && typefood==3) animationFaceNeutral();
		else {
			animationEating();
			foodBar.updateValue(foodMeter, 0);
		}
	}
	if(isFull) animationFaceNeutral();
	if(isDead) animationFaceDead();
	if(time2Poop) showPoop();
	if(liveOfGame==1500 && foodMeter>40) time2Poop=true;
}


void Screen_MainView::showPoop(){
	transitionCounter_poop++;
	if (transitionCounter_poop > 700) { // Wait for 30 ticks (~500ms at 60 FPS)
		getContainerPop().setVisible(true);
		getContainerPop().invalidate();
		liveOfGame=0;
	}

}

void Screen_MainView::animationFaceDead(){
	getContainerFaceSmile().setVisible(false);
	getContainerFaceSmile().invalidate();
	container_face_dead.setVisible(true);
	container_face_dead.invalidate();
}

void Screen_MainView::decFoodMeter(){
	transitionCounter_foodMeter++;
	if(transitionCounter_foodMeter == 1500 && foodMeter>=5)
	{
		//Update value foodBar over 0ms time
		foodMeter=foodMeter-5;
		foodBar.updateValue(foodMeter, 0);
		transitionCounter_foodMeter = 0;
	}
	else if(foodMeter<5){
		isDead=true;
	}
}


void Screen_MainView::animationSmile2(){
	transitionCounter_Smile2++;
	if (transitionCounter_Smile2 < 30) { // Wait for 30 ticks (~500ms at 60 FPS)
		getContainerFaceSmile().setVisible(false);
		getContainerFaceSmile().invalidate();
		getContainerFaceSmile2().setVisible(true);
		getContainerFaceSmile2().invalidate();
	}
	else {
		getContainerFaceSmile().setVisible(true);
		getContainerFaceSmile().invalidate();
		getContainerFaceSmile2().setVisible(false);
		getContainerFaceSmile2().invalidate();
		activateSmile2_animation = false; // Move to next step
		transitionCounter_Smile2=0;
	}
}

void Screen_MainView::animationJumping(){
	angle += speed;

	if (angle > 2 * M_PI) // Keep angle within [0, 2π] range
	{
		angle -= 2 * M_PI;
	}

	const int baseY = static_cast<int>(29 + maxBounceOffset * std::sin(angle));

	// Update each movable item if it is visible - all the time - check every item on array
	for (int i = 0; i < 6; i++) {
		if (movableItems[i].item->isVisible()) {
			const int newY = baseY + movableItems[i].yOffset;
			movableItems[i].item->moveTo(movableItems[i].item->getX(), newY);
			movableItems[i].item->invalidate();
		}
	}
}

void Screen_MainView::animationEating(){
	transitionCounter_food++;
	if (transitionCounter_food > 30) { // Wait for 30 ticks (~500ms at 60 FPS)
		switch(transitionScene_food){
			case 0:
				if(typefood==1 && foodMeter<=95){
					getImageJuice().setVisible(true);
					getImageJuice().invalidate();
					foodMeter=foodMeter+5;
				}
				else if(typefood==2 && foodMeter<=90){
					getImagePizza().setVisible(true);
					getImagePizza().invalidate();
					foodMeter=foodMeter+10;
				}
				else if(typefood==3 && foodMeter<=80){
					getImageCupcake().setVisible(true);
					getImageCupcake().invalidate();
					foodMeter=foodMeter+20;
				}
				else {
					transitionScene_food=0;
					activateFoodAnimation=false;
					transitionCounter_food=0;
					isFull=true;
					time2Poop=true;
					break;
				}
				transitionScene_food++;
				transitionCounter_food=0;
				break;
			case 1:
				getContainerFaceSmile().setVisible(false);
				getContainerFaceSmile().invalidate();
				getContainerFaceEating1().setVisible(false);
				getContainerFaceEating1().invalidate();
				getContainerFaceEating3().setVisible(true);
				getContainerFaceEating3().invalidate();
				foodScale -= 0.1f;  // Decrease scale by 10%
				if(typefood==1){
					getImageJuice().setWidth(static_cast<int>(74));
					getImageJuice().setHeight(static_cast<int>(67));
					getImageJuice().invalidate();
				}
				if(typefood==2){
					getImagePizza().setWidth(static_cast<int>(74 * foodScale));
					getImagePizza().setHeight(static_cast<int>(67 * foodScale));
					getImagePizza().invalidate();
				}
				if(typefood==3){
					getImageCupcake().setWidth(static_cast<int>(74 * foodScale));
					getImageCupcake().setHeight(static_cast<int>(67 * foodScale));
					getImageCupcake().invalidate();
				}
				transitionScene_food++;
				transitionCounter_food=0;
				break;
			case 2:
				getContainerFaceEating3().setVisible(false);
				getContainerFaceEating3().invalidate();
				getContainerFaceEating2().setVisible(true);
				getContainerFaceEating2().invalidate();
				foodScale -= 0.1f; // Decrease scale by 10%
				if(typefood==1){
					getImageJuice().setWidth(static_cast<int>(74));
					getImageJuice().setHeight(static_cast<int>(67));
					getImageJuice().invalidate();
				}
				if(typefood==2){
					getImagePizza().setWidth(static_cast<int>(74 * foodScale));
					getImagePizza().setHeight(static_cast<int>(67 * foodScale));
					getImagePizza().invalidate();
				}
				if(typefood==3){
					getImageCupcake().setWidth(static_cast<int>(74 * foodScale));
					getImageCupcake().setHeight(static_cast<int>(67 * foodScale));
					getImageCupcake().invalidate();
				}
				transitionScene_food++;
				transitionCounter_food=0;
				break;
			case 3:
				getContainerFaceEating2().setVisible(false);
				getContainerFaceEating2().invalidate();
				getContainerFaceEating1().setVisible(true);
				getContainerFaceEating1().invalidate();
				foodScale -= 0.1f; // Decrease scale by 10%
				if(typefood==1){
					getImageJuice().setWidth(static_cast<int>(74));
					getImageJuice().setHeight(static_cast<int>(67));
					getImageJuice().invalidate();
				}
				if(typefood==2){
					getImagePizza().setWidth(static_cast<int>(74 * foodScale));
					getImagePizza().setHeight(static_cast<int>(67 * foodScale));
					getImagePizza().invalidate();
				}
				if(typefood==3){
					getImageCupcake().setWidth(static_cast<int>(74 * foodScale));
					getImageCupcake().setHeight(static_cast<int>(67 * foodScale));
					getImageCupcake().invalidate();
				}
				transitionScene_food++;
				transitionCounter_food=0;
				break;
			case 4:
				getContainerFaceEating1().setVisible(false);
				getContainerFaceEating1().invalidate();
				getContainerFaceSmile().setVisible(true);
				getContainerFaceSmile().invalidate();
				foodScale=1.0f;
				if(typefood==1){
					getImageJuice().setVisible(false);
					getImageJuice().invalidate();
				}
				if(typefood==2){
					getImagePizza().setVisible(false);
					getImagePizza().invalidate();
					getImagePizza().setWidth(static_cast<int>(74));
					getImagePizza().setHeight(static_cast<int>(67));
				}
				if(typefood==3){
					getImageCupcake().setVisible(false);
					getImageCupcake().invalidate();
					getImageCupcake().setWidth(static_cast<int>(74));
					getImageCupcake().setHeight(static_cast<int>(67));
					foodAvailable=false;
				}
				transitionScene_food=0;
				activateFoodAnimation=false;
				transitionCounter_food=0;
				break;
		}
	}
}

void Screen_MainView::animationFaceNeutral(){
	transitionCounter_Neutral++;
	if (transitionCounter_Neutral < 30) { // Wait for 30 ticks (~500ms at 60 FPS)
		getContainerFaceSmile().setVisible(false);
		getContainerFaceSmile().invalidate();
		getContainerFaceNeutral().setVisible(true);
		getContainerFaceNeutral().invalidate();
	}
	else {
		getContainerFaceSmile().setVisible(true);
		getContainerFaceSmile().invalidate();
		getContainerFaceNeutral().setVisible(false);
		getContainerFaceNeutral().invalidate();
		activateFoodAnimation=false;
		transitionCounter_Neutral=0;
		isFull=false;
	}
}

void Screen_MainView::next_clothes(){
	// Hide the current image if it's not in the "hidden" state
	    if (currentClothesIndex < 4)
	    {
	        clothesImages[currentClothesIndex]->setVisible(false);
	        clothesImages[currentClothesIndex]->invalidate();
	    }

	    // Move to the next index (wrap around from 4 back to 0)
	    currentClothesIndex = (currentClothesIndex + 1) % 4;

	    // Show the new current image if it's not in the "hidden" state
	    if (currentClothesIndex < 4)
	    {
	        clothesImages[currentClothesIndex]->setVisible(true);
	        clothesImages[currentClothesIndex]->invalidate();
	    }
}

void Screen_MainView::clothes_prev(){
	 // Hide the current image if it's not in the "hidden" state
	    if (currentClothesIndex < 4)
	    {
	        clothesImages[currentClothesIndex]->setVisible(false);
	        clothesImages[currentClothesIndex]->invalidate();
	    }

	    // Move to the previous index (wrap around from 0 back to 4)
	    currentClothesIndex = (currentClothesIndex - 1 + 4) % 4;

	    // Show the new current image if it's not in the "hidden" state
	    if (currentClothesIndex < 4)
	    {
	        clothesImages[currentClothesIndex]->setVisible(true);
	        clothesImages[currentClothesIndex]->invalidate();
	    }
}
