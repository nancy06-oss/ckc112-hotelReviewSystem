#include "HotelSystem.h"

// MAIN PROGRAM: Entity-Centric Design
// Single primary object (HotelSystem) encapsulates all system operations
// through COMPOSITION - managing arrays of Hotel and Traveler objects
int main() {
    // Create the main entity-centric object
    // This single object contains all hotels and travelers
    HotelSystem system;
    
    // Run the entire system through this single object
    // No separate "Manager" or "System" classes - entity-centric design
    system.run();
    
    return 0;
}