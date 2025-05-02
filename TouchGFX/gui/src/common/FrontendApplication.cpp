#include <gui/common/FrontendApplication.hpp>

FrontendApplication::FrontendApplication(Model& m, FrontendHeap& heap)
    : FrontendApplicationBase(m, heap)
{

}

// Save the current state into the `savedState` variable
void FrontendApplication::saveState(const TamagotchiState& state)
{
    savedState = state;  // Copy the provided state into `savedState`
    hasSavedState = true;  // Mark that we now have a saved state
}

// Load the saved state into the provided variable
bool FrontendApplication::loadState(TamagotchiState& state)
{
    if (hasSavedState) {  // Check if a saved state exists
        state = savedState;  // Copy the saved state into the provided variable
        return true;         // Indicate success
    }
    return false;            // No saved state exists, return false
}
