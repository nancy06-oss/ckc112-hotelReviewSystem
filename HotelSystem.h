#ifndef HOTELSYSTEM_H
#define HOTELSYSTEM_H

#include <iostream>
#include <fstream>
#include <cstring>
#include "Hotel.h"
#include "Traveler.h"
using namespace std;

// Main entity-centric class that encapsulates entire system
// COMPOSITION: Contains arrays of Hotel and Traveler objects
// Single primary entity that manages all system operations
class HotelSystem {
private:
    Hotel hotels[20];            // COMPOSITION: Array of Hotel objects (10 hotels)
    Traveler travelers[100];     // COMPOSITION: Array of Traveler objects (10 travelers)
    int hotelCount;
    int travelerCount;

public:
    // Constructor
    HotelSystem();
    
    // File I/O methods (ONE-TIME READ/WRITE)
    void loadUsersFromFile(const char* filename);
    void loadReviewsFromFile(const char* filename);
    void saveReportsToFile(const char* filename);
    
    // Hotel operations
    void findHotelByName(const char* hotelName);
    void displayAllHotels() const;
    
    // Traveler operations
    void findTravelerByID(const char* travelerID);
    void displayAllTravelers() const;
    void displayTravelerProfile(const char* travelerID);
    
    // Menu-driven operations
    void displayPropertyDeepDive();
    void displayTravelerProfileMenu();
    void displayTopPickMatcher();
    void displayTopReviewers();
    
    // Utility methods
    void findHighestRatedHotel() const;
    void rankAllHotels() const;
    int findHotelIndex(const char* hotelName) const;
    int findTravelerIndex(const char* travelerID) const;
    
    // Manual review input
    void addManualReview();
    
    // Main menu
    void displayMainMenu();
    void run();
};

#endif
