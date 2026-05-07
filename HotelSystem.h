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
class HotelSystem {
private:
    Hotel hotels[50];           // COMPOSITION: Array of Hotel objects
    Traveler travelers[100];    // COMPOSITION: Array of Traveler objects
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
    void findHotelByID(int hotelID);
    void displayAllHotels() const;
    
    // Traveler operations
    void findTravelerByID(int travelerID);
    void displayAllTravelers() const;
    void displayTravelerProfile(int travelerID);
    
    // Menu-driven operations
    void displayPropertyDeepDive();
    void displayTravelerProfileMenu();
    void displayTopPickMatcher();
    void displayTopReviewers();
    
    // Utility methods
    void findHighestRatedHotel() const;
    void rankAllHotels() const;
    int findHotelIndex(int hotelID) const;
    int findTravelerIndex(int travelerID) const;
    
    // Manual review input
    void addManualReview();
    
    // Main menu
    void displayMainMenu();
    void run();
};

#endif