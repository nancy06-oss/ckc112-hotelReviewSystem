#include "Review.h"

// Constructor - initializes review with default values
Review::Review() {
    rating = 0;
    strcpy(comment, "");
    strcpy(hotelName, "");
}

// Set all review data at once
// Parameters: r = rating (1-5), com = comment, hotel = hotel name
void Review::setReviewData(int r, const char* com, const char* hotel) {
    rating = r;
    strcpy(comment, com);
    strcpy(hotelName, hotel);
}

// Getter: Rating (1-5 stars)
int Review::getRating() const {
    return rating;
}

// Getter: Comment text
const char* Review::getComment() const {
    return comment;
}

// Getter: Hotel name
const char* Review::getHotelName() const {
    return hotelName;
}

// Display a single review with formatted output
void Review::displayReview() const {
    cout << "    Rating: " << rating << "/5 | Hotel: " << hotelName << "\n";
    cout << "    Comment: " << comment << "\n";
    cout << "    ---\n";
}
