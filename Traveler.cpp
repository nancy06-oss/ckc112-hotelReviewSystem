#include "Traveler.h"

// Constructor - initializes traveler with default values
// Calls parent class constructor via initialization list
Traveler::Traveler() : User() {
    strcpy(membershipLevel, "Silver");
    loyaltyPoints = 0;
    reviewCount = 0;
}

// Set traveler-specific data with all parameters
// Parameters: id, name, state, email from parent; membership level and loyalty points for traveler
void Traveler::setTravelerData(const char* id, const char* name, const char* st, 
                               const char* e, const char* membership, int points) {
    // Call parent class method to set base user data
    setUserData(id, name, st, e);
    strcpy(membershipLevel, membership);
    loyaltyPoints = points;
    reviewCount = 0;
}

// COMPOSITION: Add a review to traveler's collection
// Maximum 50 reviews per traveler
void Traveler::addReview(const Review& newReview) {
    if (reviewCount < 50) {
        reviewsAuthored[reviewCount] = newReview;
        reviewCount++;
    }
}

// Getter: Membership Level (Silver, Gold, Platinum)
const char* Traveler::getMembershipLevel() const {
    return membershipLevel;
}

// Getter: Loyalty Points
int Traveler::getLoyaltyPoints() const {
    return loyaltyPoints;
}

// Getter: Number of reviews authored
int Traveler::getReviewCount() const {
    return reviewCount;
}

// Getter: Review at specific index
Review Traveler::getReviewAt(int index) const {
    if (index >= 0 && index < reviewCount) {
        return reviewsAuthored[index];
    }
    return Review();
}

// Calculate average rating of all reviews authored by this traveler
double Traveler::getAverageRating() const {
    if (reviewCount == 0) return 0.0;
    
    int totalRating = 0;
    for (int i = 0; i < reviewCount; i++) {
        totalRating += reviewsAuthored[i].getRating();
    }
    return (double)totalRating / reviewCount;
}

// Add loyalty points to traveler's account
void Traveler::addLoyaltyPoints(int points) {
    loyaltyPoints += points;
}

// Override parent's display method to show traveler-specific information
void Traveler::displayUser() const {
    cout << "\n=== TRAVELER PROFILE ===\n";
    cout << "User ID: " << userID << " | Name: " << userName 
         << " | State: " << state << "\n";
    cout << "Email: " << email << "\n";
    cout << "Membership Level: " << membershipLevel << "\n";
    cout << "Loyalty Points: " << loyaltyPoints << "\n";
    cout << "Reviews Authored: " << reviewCount << "\n";
    if (reviewCount > 0) {
        cout << "Average Rating Given: " << getAverageRating() << "/5\n";
    }
}

// Display all reviews authored by this traveler
void Traveler::displayAllReviews() const {
    cout << "\n--- Reviews Written by " << userName << " ---\n";
    if (reviewCount == 0) {
        cout << "This traveler has not written any reviews yet.\n";
        return;
    }
    for (int i = 0; i < reviewCount; i++) {
        cout << "Review " << (i + 1) << ":\n";
        reviewsAuthored[i].displayReview();
    }
}

// OPERATOR OVERLOADING: Compare two travelers by loyalty points (>)
bool Traveler::operator>(const Traveler& other) const {
    return loyaltyPoints > other.loyaltyPoints;
}

// OPERATOR OVERLOADING: Compare two travelers by loyalty points (<)
bool Traveler::operator<(const Traveler& other) const {
    return loyaltyPoints < other.loyaltyPoints;
}

// OPERATOR OVERLOADING: Compare equality based on user ID
bool Traveler::operator==(const Traveler& other) const {
    return strcmp(userID, other.userID) == 0;
}
