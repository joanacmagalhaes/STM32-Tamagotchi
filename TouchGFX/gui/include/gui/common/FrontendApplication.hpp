#ifndef FRONTENDAPPLICATION_HPP
#define FRONTENDAPPLICATION_HPP

#include <gui_generated/common/FrontendApplicationBase.hpp>

struct TamagotchiState {
    int currentClothesIndex;
    float foodScale;
    bool foodAvailable;
    int foodMeter;
    // Add other variables you want to save/restore
};

class FrontendHeap;

using namespace touchgfx;

class FrontendApplication : public FrontendApplicationBase
{
public:
    FrontendApplication(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplication() { }

    virtual void handleTickEvent()
    {
        model.tick();
        FrontendApplicationBase::handleTickEvent();
    }
    void saveState(const TamagotchiState& state);      // Save state
    bool loadState(TamagotchiState& state);            // Load state
private:
    TamagotchiState savedState;                        // Holds the saved state
    bool hasSavedState = false;
};

#endif // FRONTENDAPPLICATION_HPP

