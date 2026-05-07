#include "HotelSystem.h"

// ========== MAIN PROGRAM ==========
// ENTITY-CENTRIC DESIGN DEMONSTRATION
// 
// This program demonstrates Object-Oriented Programming principles:
// - INHERITANCE: Traveler class inherits from User class
// - COMPOSITION: HotelSystem contains arrays of Hotel and Traveler objects
// - OPERATOR OVERLOADING: > < == << operators for comparisons
// - FRIEND FUNCTION: operator<< in Hotel class accesses private members
// - ENCAPSULATION: Private data members with public getters/setters
// - ONE-TIME I/O: Files read once at startup, written once at exit
// - FIXED-SIZE ARRAYS: No STL containers used (no vectors)
// - NO CIRCULAR DEPENDENCIES: Clean class hierarchy
//
// SINGLE PRIMARY ENTITY: The main() function operates on a single primary
// entity object (HotelSystem) that encapsulates all related data through
// COMPOSITION. No separate "Manager" or "System" placeholder classes.
// ===================================

int main() {
    // Create the main entity-centric object
    // This single HotelSystem object contains:
    //   - Array of Hotel objects (COMPOSITION)
    //   - Array of Traveler objects (COMPOSITION)
    //   - All system operations and file I/O methods
    HotelSystem system;
    
    // Run the entire system through this single object
    // The system handles:
    //   1. ONE-TIME I/O READ: Load files at startup
    //   2. MENU LOOP: Display menu and process user choices
    //   3. ALL OPERATIONS: Property search, traveler profiles, ranking, etc.
    //   4. ONE-TIME I/O WRITE: Save reports before termination
    system.run();
    
    return 0;
}
