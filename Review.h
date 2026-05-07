#ifndef REVIEW_H
#define REVIEW_H

#include <iostream>
#include <cstring>
using namespace std;

// Review class - encapsulates individual hotel review data
// Represents a single review written by a traveler for a hotel
class Review {
private:
    int rating;                  // 1-5 star rating
    char comment[500];           // Review comment/feedback
    char hotelName[100];         // Hotel being reviewed

public:
    // Constructor - initializes review with default values
    Review();
    
    // Setter method - sets all review data
    void setReviewData(int r, const char* com, const char* hotel);
    
    // Getter methods
    int getRating() const;
    const char* getComment() const;
    const char* getHotelName() const;
    
    // Display review information
    void displayReview() const;
};

#endif
