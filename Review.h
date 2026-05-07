#ifndef REVIEW_H
#define REVIEW_H

#include <iostream>
#include <cstring>
using namespace std;

// Review class - encapsulates individual hotel review data
class Review {
private:
    int reviewID;
    int hotelID;
    int userID;
    int rating;           // 1-5 star rating
    char comment[500];    // Review text

public:
    // Constructor
    Review();
    
    // Setter methods
    void setReviewData(int rID, int hID, int uID, int r, const char* com);
    
    // Getter methods
    int getReviewID() const;
    int getHotelID() const;
    int getUserID() const;
    int getRating() const;
    const char* getComment() const;
    
    // Display review information
    void displayReview() const;
};

#endif