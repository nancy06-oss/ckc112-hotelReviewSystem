#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <cstring>
#include "Review.h"
using namespace std;

// Hotel class - manages hotel data and its reviews (COMPOSITION)
class Hotel {
private:
    int hotelID;
    char hotelName[100];
    char location[100];
    int starRating;
    Review hotelReviews[100];  // COMPOSITION: Array of Review objects
    int reviewCount;

public:
    // Constructor
    Hotel();
    
    // Setter method
    void setHotelData(int id, const char* name, const char* loc, int stars);
    
    // COMPOSITION: Add a review to this hotel
    void addReview(const Review& review);
    
    // Getter methods
    int getHotelID() const;
    const char* getHotelName() const;
    const char* getLocation() const;
    int getStarRating() const;
    int getReviewCount() const;
    Review getReviewAt(int index) const;
    
    // Calculate average rating from all reviews
    double getAverageRating() const;
    
    // Display hotel information
    void displayHotelInfo() const;
    
    // Display all reviews for this hotel
    void displayAllReviews() const;
    
    // OPERATOR OVERLOADING: Compare hotels by average rating (>)
    bool operator>(const Hotel& other) const;
    
    // OPERATOR OVERLOADING: Stream insertion for easy printing
    friend ostream& operator<<(ostream& os, const Hotel& hotel);
};

#endif