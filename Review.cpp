#include "Review.h"

// Constructor - initializes review with default values
Review::Review() {
    reviewID = 0;
    hotelID = 0;
    userID = 0;
    rating = 0;
    strcpy(comment, "");
}

// Set all review data at once
void Review::setReviewData(int rID, int hID, int uID, int r, const char* com) {
    reviewID = rID;
    hotelID = hID;
    userID = uID;
    rating = r;
    strcpy(comment, com);
}

// Getter: Review ID
int Review::getReviewID() const {
    return reviewID;
}

// Getter: Hotel ID
int Review::getHotelID() const {
    return hotelID;
}

// Getter: User ID
int Review::getUserID() const {
    return userID;
}

// Getter: Rating
int Review::getRating() const {
    return rating;
}

// Getter: Comment
const char* Review::getComment() const {
    return comment;
}

// Display a single review
void Review::displayReview() const {
    cout << "    Review ID: " << reviewID << " | Hotel ID: " << hotelID 
         << " | User ID: " << userID << " | Rating: " << rating << "/5\n";
    cout << "    Comment: " << comment << "\n";
}