#include "Hotel.h"

// Constructor - initializes hotel with default values
Hotel::Hotel() {
    hotelID = 0;
    strcpy(hotelName, "");
    strcpy(location, "");
    starRating = 0;
    reviewCount = 0;
}

// Set hotel data
void Hotel::setHotelData(int id, const char* name, const char* loc, int stars) {
    hotelID = id;
    strcpy(hotelName, name);
    strcpy(location, loc);
    starRating = stars;
    reviewCount = 0;
}

// COMPOSITION: Add a review to this hotel
void Hotel::addReview(const Review& review) {
    if (reviewCount < 100 && review.getHotelID() == hotelID) {
        hotelReviews[reviewCount] = review;
        reviewCount++;
    }
}

// Getter: Hotel ID
int Hotel::getHotelID() const {
    return hotelID;
}

// Getter: Hotel Name
const char* Hotel::getHotelName() const {
    return hotelName;
}

// Getter: Location
const char* Hotel::getLocation() const {
    return location;
}

// Getter: Star Rating
int Hotel::getStarRating() const {
    return starRating;
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
double Hotel::getAverageRating() const {
    if (reviewCount == 0) return 0.0;
    
    int totalRating = 0;
    for (int i = 0; i < reviewCount; i++) {
        totalRating += hotelReviews[i].getRating();
    }
    return (double)totalRating / reviewCount;
}

// Display hotel information
void Hotel::displayHotelInfo() const {
    cout << "Hotel ID: " << hotelID << " | Name: " << hotelName 
         << " | Location: " << location << " | Stars: " << starRating << "\n";
    cout << "Average Rating: " << getAverageRating() << "/5 | Total Reviews: " << reviewCount << "\n";
}

// Display all reviews for this hotel
void Hotel::displayAllReviews() const {
    cout << "\n=== REVIEWS FOR " << hotelName << " ===\n";
    if (reviewCount == 0) {
        cout << "No reviews yet.\n";
        return;
    }
    for (int i = 0; i < reviewCount; i++) {
        hotelReviews[i].displayReview();
    }
}

// OPERATOR OVERLOADING: Compare hotels by average rating (>)
bool Hotel::operator>(const Hotel& other) const {
    return getAverageRating() > other.getAverageRating();
}

// FRIEND FUNCTION: Allows external function to access private members
// This demonstrates FRIEND FUNCTION requirement
ostream& operator<<(ostream& os, const Hotel& hotel) {
    os << "Hotel: " << hotel.hotelName << " [ID: " << hotel.hotelID 
       << "] | Location: " << hotel.location << " | Avg Rating: " 
       << hotel.getAverageRating() << "/5\n";
    return os;
}