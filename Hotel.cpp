#include "Hotel.h"

// Constructor - initializes hotel with default values
Hotel::Hotel() {
    strcpy(hotelName, "");
    reviewCount = 0;
}

// Set hotel data with hotel name
void Hotel::setHotelData(const char* name) {
    strcpy(hotelName, name);
    reviewCount = 0;
}

// COMPOSITION: Add a review to this hotel
// Maximum 100 reviews per hotel
void Hotel::addReview(const Review& review) {
    if (reviewCount < 100) {
        hotelReviews[reviewCount] = review;
        reviewCount++;
    }
}

// Getter: Hotel Name
const char* Hotel::getHotelName() const {
    return hotelName;
}

// Getter: Review Count
int Hotel::getReviewCount() const {
    return reviewCount;
}

// Getter: Review at index
Review Hotel::getReviewAt(int index) const {
    if (index >= 0 && index < reviewCount) {
        return hotelReviews[index];
    }
    return Review();
}

// Calculate average rating from all reviews
// Returns 0.0 if no reviews exist
double Hotel::getAverageRating() const {
    if (reviewCount == 0) return 0.0;
    
    int totalRating = 0;
    for (int i = 0; i < reviewCount; i++) {
        totalRating += hotelReviews[i].getRating();
    }
    return (double)totalRating / reviewCount;
}

// Display hotel information summary
void Hotel::displayHotelInfo() const {
    cout << "Hotel Name: " << hotelName 
         << " | Average Rating: " << getAverageRating() << "/5"
         << " | Total Reviews: " << reviewCount << "\n";
}

// Display all reviews for this hotel
void Hotel::displayAllReviews() const {
    cout << "\n=== REVIEWS FOR " << hotelName << " ===\n";
    if (reviewCount == 0) {
        cout << "No reviews yet.\n";
        return;
    }
    for (int i = 0; i < reviewCount; i++) {
        cout << "Review " << (i + 1) << ":\n";
        hotelReviews[i].displayReview();
    }
}

// OPERATOR OVERLOADING: Compare hotels by average rating (>)
bool Hotel::operator>(const Hotel& other) const {
    return getAverageRating() > other.getAverageRating();
}

// FRIEND FUNCTION: Allows external function to access private members
// This demonstrates FRIEND FUNCTION requirement
// Overloads << operator for easy printing of hotel information
ostream& operator<<(ostream& os, const Hotel& hotel) {
    os << "Hotel: " << hotel.hotelName 
       << " | Avg Rating: " << hotel.getAverageRating() << "/5"
       << " | Reviews: " << hotel.reviewCount << "\n";
    return os;
}
