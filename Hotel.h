#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <cstring>
#include "Review.h"
using namespace std;

// Hotel class - manages hotel data and its reviews (COMPOSITION)
// Represents a hotel property with multiple reviews from different travelers
class Hotel {
private:
    char hotelName[100];         // Hotel name
    Review hotelReviews[100];    // COMPOSITION: Array of Review objects
    int reviewCount;             // Count of reviews received

public:
    // Constructor
    Hotel();
    
    // Setter method - initializes hotel with name
    void setHotelData(const char* name);
    
    // COMPOSITION: Add a review to this hotel
    void addReview(const Review& review);
    
    // Getter methods
    const char* getHotelName() const;
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
    
    // FRIEND FUNCTION: Allows external function to access private members
    // This demonstrates FRIEND FUNCTION requirement
    friend ostream& operator<<(ostream& os, const Hotel& hotel);
};

#endif
